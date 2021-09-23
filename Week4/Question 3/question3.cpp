#include<iostream>
#include<stdlib.h>
#include<stdio.h>
#include <time.h>
using namespace std;

int pivot(int arr[], int l, int r){
    int pv = arr[r];
    int i = l-1;
    for(int j=l;j<=r-1;j++){
        if(arr[j] < pv){
            i++;
            swap(arr[i],arr[j]);
        }
    }
    swap(arr[i+1],arr[r]);
    return (i+1);
} 

int  kth_largest(int arr[], int l,int r,int k){ 
    if(l<r)
    {
        int p = pivot(arr,l,r);
        if(k == p)
        {
            
            return arr[p];

        }else if(p < k){
            return kth_largest(arr,p+1,r,k);
        }else{
            return kth_largest(arr,l,p-1,k);
        }
       
    }
    return 0;
 
}

int main(){    
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        int arr[n];
        for(int i=0;i<n;i++){
            cin>>arr[i];
        }
        int k;
        cin>>k;
        cout<<"Kth largest : "<<kth_largest(arr,0,n-1,k-1)<<endl;       
    }
    return 0;

}
