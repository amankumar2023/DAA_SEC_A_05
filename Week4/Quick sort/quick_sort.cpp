#include <bits/stdc++.h>
using namespace std;

int privot(int arr[], int l, int r,int &comp,int &swaps){
    int a = rand() % (r-l+1)+l;
    swap(arr[a],arr[r]);
    int pv = arr[r];
    int i = l-1;
    for(int j=l;j<=r-1;j++){
        comp++;
        if(arr[j] < pv){
            swaps++;
            i++;
            swap(arr[i],arr[j]);
        }
    }
    swaps++;
    swap(arr[i+1],arr[r]);
    return (i+1);
} 

void quick_sort(int arr[], int l,int r,int &comp,int &swaps){
    
    if(l<r){
        int p = privot(arr,l,r,comp,swaps);
        quick_sort(arr,l,p-1,comp,swaps);
        quick_sort(arr,p+1,r,comp,swaps);
       
    }
 
}

int main(){
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    int t;
    cin>>t;
    while(t--){
        int n,comp=0,swaps=0;
        cin>>n;
        int arr[n];
        for(int i=0;i<n;i++){
            cin>>arr[i];
        }
        quick_sort(arr,0,n-1,comp,swaps);
        for(int i=0;i<n;i++){
            cout<<arr[i]<<" ";
        }
        cout<<endl;
        cout<<"Comparsion :"<<comp<<endl;
        cout<<"Swap :"<<swaps<<endl;
    }
    return 0;
}
