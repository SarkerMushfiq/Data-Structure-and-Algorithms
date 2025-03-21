#include<bits/stdc++.h>
using namespace std;

vector<int>sortedArray(vector<int>&a,vector<int>&b){
    int n1=a.size();
    int n2=b.size();
    set<int>st;
    for(int i=0;i<n1;i++){
        st.insert(a[i]);
    }
    for(int i=0;i<n2;i++){
        st.insert(b[i]);
    }
    vector<int>temp;
    for(auto it:st){
        temp.push_back(it);
    }
    return temp;
}

int main(){
    vector<int>a={1,3,6,9,11,19,20};
    vector<int>b={1,2,2,6,20,35};
    vector<int>newArray=sortedArray(a,b);

    for(int num:newArray){
        cout<<num<<" ";
    }
    return 0;
}
