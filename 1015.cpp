#include<iostream>
#include<vector>
using namespace std;

int main(){
    int n;
    cin>>n;
    int a,b,h;
    vector<int>height;
    for(int i=0;i<n;++i){
        cin>>a>>b>>h;
        if(b+1>height.size())height.resize(b+1);
        for(int j=a;j<b;++j){
            if(height[j]<h)height[j]=h;
        }
    }

    int size=height.size();
    if(height[0])cout<<0<<' '<<height[0]<<endl;
    for(int i=1;i<size;++i){
        if(height[i]!=height[i-1])cout<<i<<' '<<height[i]<<endl;
    }
    return 0;
}