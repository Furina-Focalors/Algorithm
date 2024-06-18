#include<iostream>
#include<vector>
using namespace std;

int main(){
    int m;
    cin>>m;
    for(int a=0;a<m;++a){
        int n;
        cin>>n;
        vector<int>nums=vector<int>(n);
        for(int i=0;i<n;++i)cin>>nums[i];
        for(int i=0;i<n-1;++i){
            if(nums[i]>nums[i+1]){
                int temp=nums[i];
                nums[i]=nums[i+1];
                nums[i+1]=temp;
            }
        }
        for(int i=0;i<n;++i){
            cout<<nums[i]<<' ';
        }
        cout<<endl;
    }
    return 0;
}