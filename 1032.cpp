#include<iostream>
#include<iomanip>
using namespace std;

int main(){
    int t;
    cin>>t;
    for(int a=0;a<t;++a){
        int n;
        cin>>n;
        double ans=0.0;
        double temp;
        for(int i=1;i<n;++i){
           cin>>temp;
           ans+=temp; 
        }
        cout<<fixed<<setprecision(6)<<1.0+ans/100.0<<endl;
    }
    return 0;
}