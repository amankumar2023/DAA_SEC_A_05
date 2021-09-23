#include <bits/stdc++.h>
using namespace std;

int finddiff(int arr[],int n,int diff){
    sort(arr,arr+n);
    int count =0;
    int i=0,j=0;
    while(i<n && j<n){
        if(abs(arr[i]-arr[j]) == diff){
            count++;
            i++;
            j++;
        }
        else if(abs(arr[i]-arr[j]) < diff){
            j++;
        }
        else{
            i++;
        }
    }
    return count;
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
        int diff;
        cin>>diff;
        int count = finddiff(arr,n,diff);
        cout<<count<<endl;

    }

}
