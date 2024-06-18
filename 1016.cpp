#include<iostream>
#include<algorithm>
using namespace std;

int main(){
    int m;
    cin>>m;
    int* n=new int[m];
    int* x=new int[m];
    int** nums=new int*[m];
    for(int i=0;i<m;++i){
        cin>>n[i]>>x[i];
        nums[i]=new int[n[i]];
        for(int j=0;j<n[i];++j){
            cin>>nums[i][j];
        }
    }

    for(int i=0;i<m;++i){
        sort(nums[i],nums[i]+n[i]);
        int start=0,size=n[i],end=size-1;
        for(int j=0;start<=end;++j){
            if(nums[i][start]+nums[i][end]==x[i]){
                cout<<"yes"<<endl;
                break;
            }
            else if(nums[i][start]+nums[i][end]>x[i]){//sum>x
                --end;
            }
            else{
                ++start;
            }
        }
        if(start>end)cout<<"no"<<endl;
    }

    return 0;
}