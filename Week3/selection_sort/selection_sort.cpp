#include<iostream>
using namespace std;

void selection_sort(int arr[],int n)
{
    int i,j,min_idx,c=0,s=0;
    for(int i=0;i<n-1;i++)
    {
        min_idx = i;
        for(int j=i+1;j<n;j++)
        {
            c++;
            if(arr[j] < arr[min_idx])
            {
                min_idx = j;
            }
        }
        s++;
        swap(arr[i],arr[min_idx]);
    }
    for(int i=0;i<n;i++)
    {
        cout<<arr[i]<<" ";
    }
    cout<<endl<<"Comparison :"<<c;
    cout<<endl<<"Swaps :"<<s;

}
int main()
{
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        int arr[n];
        for(int i=0;i<n;i++)
        {
            cin>>arr[i];
        }
        selection_sort(arr,n);
        cout<<endl;
    }
}
