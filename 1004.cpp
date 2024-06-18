#include<iostream>
#include<vector>
using namespace std;

void merge(vector<int>&nums,int low,int mid,int high,int level){
    int i=low,j=mid+1;
    vector<int>aux=nums;
    for(int k=low;k<=high;++k){
        if(i>mid)nums[k]=aux[j++];
        else if(j>high)nums[k]=aux[i++];
        else if(aux[i]<=aux[j])nums[k]=aux[i++];
        else nums[k]=aux[j++];
    }
    if(level==3){
        for(int i=low;i<=high;++i){
            cout<<nums[i]<<' ';
        }
    }
}

void sort(vector<int>&nums,int low,int high,int level){
    if(low==high)return;
    int mid=low+(high-low)/2;
    sort(nums,low,mid,level+1);
    sort(nums,mid+1,high,level+1);
    if(nums[mid]<=nums[mid+1]){
        if(level==2){
        for(int i=low;i<=high;++i){
            cout<<nums[i]<<' ';
        }
    }
    return;
    }
    merge(nums,low,mid,high,level+1);
}

int main(){
    int m;
    cin>>m;
    for(int a=0;a<m;++a){
        int n;
        cin>>n;
        vector<int>nums=vector<int>(n);
        for(int i=0;i<n;++i){
            cin>>nums[i];
        }
        sort(nums,0,nums.size()-1,0);
        cout<<endl;
    }
    return 0;
}