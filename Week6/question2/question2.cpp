#include<iostream>
#include<vector>
#include<queue>
using namespace std;


bool Bipartitle(vector<vector<int>>arr,int n)
{
    vector<int>vis(n,-1);
    queue<int>qe;
    qe.push(0);
    vis[0] = 0;
    while(!qe.empty())
    {
        int curr = qe.front();
        qe.pop();
        for(int i=0;i<n;i++)
        {
            if(arr[curr][i] == 1)
            {
                if(vis[i] == -1)
                {
                    if(vis[curr] == 0)
                    {
                        vis[i] = 1;
                    }else{
                        vis[i] = 0;
                    }
                    qe.push(i);
                }else{
                    if(vis[i] == vis[curr])
                    {
                        return false;
                    }
                }
            }
        }
    }
    return true;
   
}

int main()
{
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    int n;
    cin>>n;
    vector<vector<int>>arr(n,vector<int>(n));
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            int x;
            cin>>x;
            arr[i][j] = x;
        }
    }
    if(Bipartitle(arr,n))
    {
        cout<<"Bipartitle";
    }else{
        cout<<"Not Bipartitle";
    }
}
