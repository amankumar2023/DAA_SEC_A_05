#include <bits/stdc++.h>
using namespace std;


bool linearSearch(vector<int> arr,int k,int &pos){
    int i;
    for(i=0;i<arr.size();i++){
        if(arr[i]==k){
            break;
        }
    }
    pos=i+1;
    return i==arr.size();
}

int main(){
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    int t,n,k,x;
    cin>>t;
    while(t--){
        cin>>n;
        vector<int> arr(n);
        for(int i=0;i<n;i++){
            cin>>x;
            arr[i]=x;
        }
        int pos=0;
        cin>>k;
        if(!linearSearch(arr,k,pos)){
            cout<<"Element Present at position: "<<pos;
        }
        else{
            cout<<"Element Not present";
        }
        cout<<endl;
    }
    return 0;
}
