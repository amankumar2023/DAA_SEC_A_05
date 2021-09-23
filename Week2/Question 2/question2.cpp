#include<bits/stdc++.h>
using namespace std;

vector<int> findpair(int arr[],int n){
    vector<int>res;
    for(int i=n-1;i>=2;i--){
        int start=0;
        int end=i-1;
        while(start < end){
            if((arr[start]+arr[end]) == arr[i]){
                res.push_back(start+1);
                res.push_back(end+1);
                res.push_back(i+1);
                return res;
            }
            else if ((arr[start]+arr[end]) < arr[i]){
                start++;
            }
            else{
                end--;
            }
        }   
    }
    return res;
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
        vector<int>result = findpair(arr,n);
        if(result.size() == 0){
            cout<<"No Sequence posible";
        }
        else{
            for(auto i: result){
                cout<<i<<" ";
            }
        }
        cout<<endl;
    }
}
