#include<vector>
#include <iostream>
#include <algorithm>
using namespace std;

bool binarySearch(vector<int> arr,int key,int l,int h,int &comp)
{
    int low=l,high= h;
    while(low <= high)
    {
        int mid = low+(high-low)/2;
        comp++;
        if(arr[mid] == key)
        {
            return true;
        }
        else if(arr[mid] < key)
        {
            low = mid+1;
        }else{
            high = mid-1;
        }
    }
    return false;
}
bool exponebtialSearch(vector<int> arr,int key,int &comp)
{
    
    int n = arr.size();
     if (arr[0] == key)
     {
        comp++;
        return true;
     }
     int i=1;
     while( i< n && arr[i] <= key)
     {
         comp++;
         i=i*2;
     }
     int h = min(i , n-1);
     return binarySearch(arr,key,i/2,h,comp);
     
}
int main()
{
    
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    int t,size,key,x;
    cin>>t;
    while(t--)
    {    
        cin>>size;
        vector<int>arr(size);
        for(int i=0;i<size;i++)
        {
            cin>>x;
            arr[i] = x;
        }
        int comp=0;
        cin>>key;
   
        if(exponebtialSearch(arr,key,comp))
        {
            cout<<"Present "<<comp;

        }else{
            cout<<"NOT Presrnt "<<comp;
        }
        cout<<endl;
    }
    return 0;
}
