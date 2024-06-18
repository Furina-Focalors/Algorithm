#include<iostream>
#include<vector>
using namespace std;

void binary_search(vector<int>&nums,int x){
    int low=0,high=nums.size()-1;
    int mid=(low+high)/2;
    int pre=mid;
    while(low<=high){
        if(x==nums[mid]){
            cout<<"success, father is "<<nums[pre]<<endl;
            return;
        }
        else if(x>nums[mid]){
            low=mid+1;
            pre=mid;
            mid=(low+high)/2;
        }
        else{
            high=mid-1;
            pre=mid;
            mid=(low+high)/2;
        }
    }
    cout<<"not found, father is "<<nums[pre]<<endl;
}

int main(){
    int m;
    cin>>m;
    for(int a=0;a<m;++a){
        int n,x;
        cin>>n>>x;
        vector<int>nums=vector<int>(n);
        for(int i=0;i<n;++i){
            cin>>nums[i];
        }
        binary_search(nums,x);
    }
    return 0;
}