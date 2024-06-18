#include<iostream>
#include<vector>
using namespace std;

void sift_up(vector<int> &nums){
    int size=nums.size();
    for(int p=size/2-1;p>=0;--p){
        int j=2*p+1;
        if(j+1<size&&nums[j]>nums[j+1])++j;//smaller sift up
        if(nums[p]>nums[j]){
            int temp=nums[p];
            nums[p]=nums[j];
            nums[j]=temp;
            //check nums[j]
            int k=2*j+1;
            while(k<size){
                if(k+1<size&&nums[k]>nums[k+1])++k;//smaller sift up
                if(nums[k]>=nums[j])break;//ok
                else{
                    int temp=nums[j];
                    nums[j]=nums[k];
                    nums[k]=temp;
                    j=k;
                    k=2*j+1;
                }
            }
        }
    }
}

int main(){
    int m;
    cin>>m;
    for(int a=0;a<m;++a){
        int n;
        cin>>n;
        vector<int>nums=vector<int>(n);
        for(int i=0;i<n;++i)cin>>nums[i];
        sift_up(nums);
        for(int i=0;i<n;++i)cout<<nums[i]<<' ';
        cout<<endl;
    }
    return 0;
}