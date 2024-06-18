#include<iostream>
#include<algorithm>
using namespace std;

int main(){
    int nums;
    cin>>nums;
    while(nums--){
        int n,m;
        cin>>n>>m;
        int* num=new int[n+m];
        for(int i=0;i<n+m;++i){
            cin>>num[i];
        }
        sort(num,num+m+n);
        if((m+n)%2){
            cout<<num[(m+n)/2]<<endl;
        }
        else{
            cout<<(double)(num[(m+n)/2-1]+num[(m+n)/2])/2.0<<endl;
        }
    }
}