#include<iostream>
using namespace std;

void merge(int arr[],int l, int r,int m,int &comp,int &in){
    int n1 = m-l+1;
    int n2 = r-m;
    int lf[n1],ri[n2];
    for(int i=0;i<n1;i++){
        lf[i] = arr[l+i];
    }
    for(int i=0;i<n2;i++){
        ri[i] = arr[i+1+m];
    }
    int i=0,j=0,k=l;
    while(i < n1 && j < n2){
        comp++;
        if(lf[i] <= ri[j]){
            arr[k++] = lf[i++];
        }
        else{
            in += n1-i;
            arr[k++] = ri[j++];
        }
    }
    while(i < n1){
        arr[k++] = lf[i++];
    }
    while(j < n2){
        arr[k++] = ri[j++];
    }
}

void merge_sort(int arr[],int l,int r,int &comp,int &in){
    if(l<r){
        int m = (l+r)/2;
        merge_sort(arr,l,m,comp,in);
        merge_sort(arr,m+1,r,comp,in);
        merge(arr,l,r,m,comp,in);
    }
}
int main(){
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    int t;
    cin>>t;
    while(t--)
    {
        int n,comp=0,in=0;
        cin>>n;
        int arr[n];
        for(int i=0;i<n;i++){
            cin>>arr[i];
        }
        merge_sort(arr,0,n-1,comp,in);
        for(int i=0;i<n;i++){
            cout<<arr[i]<<" ";
        }
        cout<<endl;
        cout<<"Compresion :"<<comp<<endl;
        cout<<"Inversions :"<<in;
        cout<<endl;
    }
}
