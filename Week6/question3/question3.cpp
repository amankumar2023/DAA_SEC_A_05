#include<iostream>
#include<vector>
#include<queue>
using namespace std;

bool dfs(vector<vector<int>> arr,int s,int n,vector<bool>vis)
{
    vis[s] = true;
    for(int i=0;i<n;i++)
    {
        if(arr[s][i] == 1)
        {
            
            if(vis[i] == false){
                
                if(dfs(arr,i,n,vis) == true)
                {
                    
                    return true;
                }
                }else{
                    return true;
                }
        }
    }
    vis[s] = false;
    return false;
}
bool check_cycle(vector<vector<int>> arr,int n)
{
    vector<bool>vis(n,false);
    return dfs(arr,0,n,vis);
}
int main()
{
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    int n;
    cin>>n;
    vector<vector<int>>arr(n,vector<int>(n,0));
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            int x;
            cin>>x;
            arr[i][j] = x;
        }
    }
    if(check_cycle(arr,n))
    {
        cout<<"Yes cycle Exists";
    }else{
        cout<<"No cycle Exists";
    }
}
