#include<iostream>
#include<vector>
using namespace std;

int partition(vector<int> &nums,int lo,int hi){
    int j=lo;
    for(int i=lo;i<=hi;++i){
        if(nums[lo]>nums[i]){
            ++j;
            int temp=nums[i];
            nums[i]=nums[j];
            nums[j]=temp;
        }
    }
    int temp=nums[j];
    nums[j]=nums[lo];
    nums[lo]=temp;
    return j;
}

void quick_sort(vector<int> &nums,int lo,int hi,int level,vector<int> &res){
    if(lo>=hi)return;
    int j=partition(nums,lo,hi);
    if(level==1)res[j]=nums[j];
    if(level==2){
        for(int i=lo;i<=hi;++i)res[i]=nums[i];
    }
    quick_sort(nums,lo,j-1,level+1,res);
    // if(level==2){
    //     cout<<"lo="<<lo<<",j-1="<<j-1<<endl;
    //     for(int i=lo;i<=j-1;++i){
    //         cout<<nums[i]<<' ';
    //     }
    // }
    // if(level==1)cout<<"\npartition="<<j<<endl;
    quick_sort(nums,j+1,hi,level+1,res);
    // if(level==2){
    //     cout<<"j+1="<<j+1<<",hi="<<hi<<endl;
    //     for(int i=j+1;i<=hi;++i){
    //         cout<<nums[i]<<' ';
    //     }
    // }
}

int main(){
    int m;
    cin>>m;
    for(int a=0;a<m;++a){
        int n;
        cin>>n;
        vector<int>nums=vector<int>(n);
        vector<int>res=vector<int>(n);
        for(int i=0;i<n;++i)cin>>nums[i];
        quick_sort(nums,0,n-1,1,res);
        for(int i=0;i<n;++i)cout<<res[i]<<' ';
        cout<<endl;
    }
    return 0;
}