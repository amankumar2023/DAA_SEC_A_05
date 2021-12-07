#include<iostream>
#include<vector>
#include<limits.h>
#include<queue>


using namespace std;
struct mycomp{
     bool operator()(pair<int,int> a, pair<int,int> b){
        
         return a.first > b.first;
     }
};
void find_path(vector<vector<int>>arr,int s)
{
    priority_queue<pair<int,int>,vector<pair<int,int>>,mycomp>pq;
    int n = arr.size();
    vector<bool>vis(n,false);
    vector<int>dis(n,INT_MAX);
    vector<int>minpath[n];
    minpath[0].push_back(1);
    dis[0] = 0; 
    pq.push({0,s-1});
    int i=0;
    while(!pq.empty())
    {
        int u = pq.top().second;
        pq.pop();
        vis[u] = true;
        for(int j=0;j<n;j++)
        {
            if(arr[u][j] != 0 && vis[j]==false)
            {
                if(dis[j] > dis[u]+arr[u][j])
                {
                    dis[j] = dis[u]+arr[u][j];
                    pq.push({dis[j],j});
                    minpath[j] = minpath[u];
                    minpath[j].push_back(j+1);
                }
                
            }
        }
         
    }
    for(int i=0;i<n;i++)
    {
        for(auto i:minpath[i])
        {
            cout<<i<<" ";
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
    int x;
    cin>>x;
   find_path(arr,x);
   return 0;
}
