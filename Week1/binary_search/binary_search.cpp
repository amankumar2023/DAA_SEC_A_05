#include<iostream>
#include<vector>
using namespace std;
bool binarySearch(vector<int> arr,int key,int &comp)
{
    int low=0,high= arr.size()-1;
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
        if(binarySearch(arr,key,comp))
        {
            cout<<"Present "<<comp;

        }else{
            cout<<"NOT Presrnt "<<comp;
        }
        cout<<endl;
    }
    return 0;
}