#include<iostream>
using namespace std;

void freq(char arr[],int n)
{
    int dp[26] = {0};
    char ch;
    for(int i=0;i<n;i++)
    {
        dp[arr[i] - 'a']++;
    }
    int mx =0;
    for(int i=0;i<26;i++)
    {
        if(mx < dp[i])
        {
            mx=dp[i];
            ch = i+'a';
        }
    }
    if(mx > 1)
    {
        cout<<ch<<" "<<mx;
    }
    else{
        cout<<"No Duplicates Present";
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
        char arr[n];
        for(int i=0;i<n;i++)
        {
            cin>>arr[i];
        }
        freq(arr,n);
        cout<<endl;
    }
}
