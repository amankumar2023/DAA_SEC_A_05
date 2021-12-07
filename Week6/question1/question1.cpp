#include<iostream>
#include<vector>
using namespace std;

bool dfs(vector<vector<int>>arr,int i,int j,int n,int d,vector<vector<bool>>&vis)
{
    if(vis[i][j] == false)
    {
        vis[i][j] = true;
        if(i == d)
        {
            return true;
        }
        if(arr[i][j] == 1)
        {
            for(int k=0;k<n;k++)
            {
                bool flag = dfs(arr,j,k,n,d,vis);
                if(flag)
                {
                    return true;
                }
            }
        }

    }
    return false;
}

bool findpath(vector<vector<int>>arr,int n,int s,int d)
{
    vector<vector<bool>>vis(n,vector<bool>(n));
    bool flag = false;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            vis[i][j] = false;   
        }
    }
    s--;
    d--;
    for(int i=0;i<n;i++)
    {
        if(vis[s][i] == false)
        {
            flag = dfs(arr,s,i,n,d,vis);
        }
        if(flag)
        {
            break;
        }
    }
    return flag;
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
    int s,d;
    cin>>s>>d;
    if(findpath(arr,n,s,d) == true)
    {
        cout<<"Yes path Exists";
    }else{
        cout<<"No path Exists";
    }
}
