#include<iostream>

using namespace std;

void insertion_sort(int arr[],int n)
{
  
    int i,temp,j,s=0,c=0;
    for(int i=1;i<n;i++)
    {
        temp = arr[i];
        j = i-1;
        bool flag = true;
        c++;
        while (j >= 0 && arr[j] > temp)
        {
           
            flag = false;
            c++;
            s++;
            arr[j+1] = arr[j];
            j=j-1;
        }  
        if(j == 0)
        {
            c--;
        }
        if(!flag)
        {
            s++;
        }
        arr[j+1] = temp;
        
    }
    for(int i=0;i<n;i++)
    {
        cout<<arr[i]<<" ";
    }
    cout<<endl<<c;
    cout<<endl<<s;
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
        insertion_sort(arr,n);
        
        cout<<endl;

    }
}
