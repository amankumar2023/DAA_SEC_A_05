#include<iostream>
#include<vector>
#include<climits>

using namespace std;

void Bellman(vector<vector<int>>arr,int s,int n)
{
    vector<int>dis(n,INT_MAX);
    dis[s-1] = 0;
    vector<int>path[n];
    path[s-1].push_back(1);
    for(int count=0;count<n-1;count++)
    {
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(arr[i][j] != 0)
                {
                    if(dis[i] != INT_MAX && dis[i]+arr[i][j] < dis[j])
                    {
                        dis[j] = dis[i]+arr[i][j];
                        path[j] = path[i];
                        path[j].push_back(j+1);
                    }
                }
            }
        }
    }
    for(int i=0;i<n;i++)
    {
        for(int k : path[i])
        {
            cout<<k<<" ";
        }
        cout<<": "<<dis[i]<<endl;
    }

}
int main()
{
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    int n,s;
    cin>>n;
    vector<vector<int>>arr(n,vector<int>(n));
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            cin>>s;
            arr[i][j] = s;
        }
    }
    cin>>s;
    Bellman(arr,s,n);
}
