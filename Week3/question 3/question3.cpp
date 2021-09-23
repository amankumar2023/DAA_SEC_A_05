#include<iostream>

using namespace std;

void insertion_sort(int arr[],int n)
{
  
    int i,temp,j;
    for(int i=1;i<n;i++)
    {
        temp = arr[i];
        j = i-1;
        while (j >= 0 && arr[j] > temp)
        {
            arr[j+1] = arr[j];
            j=j-1;
        } 
        arr[j+1] = temp;
        
    }
   
    
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
        bool flag = false;
        for(int i=0;i<n-1;i++)
        {
            if(arr[i] == arr[i+1])
            {
                flag = true;
                break;
            }
        }
        if(flag)
        {
            cout<<"Yes";
        }else{
            cout<<"No";
        }
        cout<<endl;


    }
}
