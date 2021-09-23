#include<iostream>
using namespace std;

void findcom(int arr[],int arr2[],int n,int m)
{
 
    int i=0,j=0;
    while(i < n && j<m)
    {
        if(arr[i] == arr2[j])
        {
            cout<<arr[i]<<" ";
            i++;
            j++;
        }else if(arr[i] < arr2[j]){
            i++;
        }else{
            j++;
        }
    }
}
int main()
{
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    int n,m;

    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }
    cin>>m;
    int arr2[m];
    for(int i=0;i<m;i++)
    {
        cin>>arr2[i];
    }
    findcom(arr,arr2,n,m);
    cout<<endl;

}
