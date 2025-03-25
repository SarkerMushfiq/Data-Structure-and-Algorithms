#include<iostream>
#include<vector>
using namespace std;

vector<int>intersectionArray(vector<int>&a,vector<int>&b){
    int n=a.size();
    int m=b.size();
    int i=0;
    int j=0;
    vector<int>ans;

    while(i<n&&j<m){
        if(a[i]<b[j]){
            i++;
        }
        else if(a[i]>b[j]){
            j++;
        }
        else{
            ans.push_back(a[i]);
            i++;
            j++;
        }
    }
    return ans;
}

int main(){
    vector<int>a={1,1,2,3,6,9,11,19,20};
    vector<int>b={1,2,2,6,19,20,35};
    vector<int>newArray=intersectionArray(a,b);

    for(int num:newArray){
        cout<<num<<" ";
    }
    return 0;
}
