#include<iostream>
using namespace std;

int main(){
    int n=0,a=0,b=0;
    cin>>n;
    int* res=new int[n];
    for(int i=0;i<n;++i){
        cin>>a>>b;
        res[i]=a+b;
    }
    for(int i=0;i<n;++i)cout<<res[i]<<endl;
    return 0;
}