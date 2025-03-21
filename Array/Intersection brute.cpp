#include<bits/stdc++.h>
using namespace std;

vector<int>intersectionArray(vector<int>&a,vector<int>&b){
    int n=a.size();
    int m=b.size();

    vector<int>ans;
    int vis[m]={0};
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(a[i]==b[j]&&vis[j]==0){
                ans.push_back(a[i]);
                vis[j]=1;
                break;
            }
            if(b[j]>a[i]) break;
        }
    }
    return ans;
}

int main(){
    vector<int>a={1,3,6,9,11,19,20};
    vector<int>b={1,2,2,6,20,35};
    vector<int>newArray=intersectionArray(a,b);

    for(int num:newArray){
        cout<<num<<" ";
    }
    return 0;
}
