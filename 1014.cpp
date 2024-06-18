#include<iostream>
#include<vector>
using namespace std;
/*
动态规划
Time=O(n)
Space=O(1)
*/
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

        /*
        vector<int>max=vector<int>(n);//以下标i结尾的最大子数组和
        max[0]=nums[0];
        for(int end=1;end<n;++end){
            max[end]=max[end-1]<=0?nums[end]:max[end-1]+nums[end];//前end-1个为正则相加，不为正则最大值就是nums[end]
        }
        int result=max[0];
        for(int i=1;i<n;++i){
            if(max[i]>result)result=max[i];
        }
        cout<<result<<endl;
        */
        
        int pre=nums[0];//存上一个结果
        int max=nums[0];
        for(int end=1;end<n;++end){//求以end为结尾的最大子数组和
            pre=pre<=0?nums[end]:pre+nums[end];
            if(pre>max)max=pre;
        }
        cout<<max<<endl;
    }
    return 0;
}