#include<iostream>
#include<climits>
#include<vector>
#include<queue>

using namespace std;

void dfs(vector<vector<int>>arr,int s,int d,vector<bool> &vis,vector<int> &path,vector<vector<int>> &allpath)
{
    vis[s] = true;
    path.push_back(s+1);
    if(s == d)
    {
        allpath.push_back(path);
    }else{
        for(int i=0;i<arr.size();i++)
        {
            if(arr[s][i] != 0)
            {
                dfs(arr,i,d,vis,path,allpath);
            }
        }
    }
    path.pop_back();
    vis[s] = false;

}
void FindPath(vector<vector<int>>arr,int s,int d,int k)
{
    int n = arr.size();
    vector<bool>vis(n,false);
    vector<int>path;
    int dis = INT_MAX;
    int pt =0;
    vector<vector<int>>allpath;
    dfs(arr,s-1,d-1,vis,path,allpath);
    for(int j=0;j<allpath.size();j++)
    {
        vector<int> v = allpath[j];
        if(k == v.size())
        {
           
            int currdis = 0;
            for(int i=0;i<v.size()-1;i++)
            {
                currdis += arr[v[i]-1][v[i+1]-1];
            }
           
            if(currdis < dis)
            {
                dis = currdis;
                pt = j;
            }
        }
    }
    if(dis != INT_MAX)
    {
        cout<<"shotest path :";
        for(auto i:allpath[pt])
        {
            cout<<i<<" ";
        }
        cout<<endl<<"weight : "<<dis;
    }else{
        cout<<"NO PATH FOUND";
    }

}

int main(){
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    int n,s,d,k;
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
    cin>>s>>d>>k;
    FindPath(arr,s,d,k);
}
