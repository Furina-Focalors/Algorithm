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
        vector<int>length=vector<int>(n);//length result for the case that ends at index i
        for(int end=0;end<n;++end){
            int temp=1;
            for(int i=end-1;i>=0;--i){
                if(nums[i]>nums[end])continue;
                if(length[i]+1>temp){
                    temp=length[i]+1;
                }             
            }
            length[end]=temp;
        }
        int res=0;
        for(int i=0;i<n;++i){
            if(length[i]>res)res=length[i];
        }
        cout<<res<<endl;
    }
    return 0;
}
//time=O(n^2),space=O(n)