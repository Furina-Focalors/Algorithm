#include<iostream>
#include<vector>
using namespace std;
//分治
int merge(vector<int>& nums,int lo,int mid,int hi){
    //返回逆序对数
    int i=lo,j=mid+1;
    int count=0;
    vector<int>temp=nums;
    for(int k=lo;k<=hi;++k){
        if(i>mid)nums[k]=temp[j++];//右半有多
        else if(j>hi)nums[k]=temp[i++];//左半有多
        else if(temp[i]<=temp[j])nums[k]=temp[i++];//先放左边，不构成逆序
        else{//先放右边，此时左边未归并的所有元素和该元素均构成逆序对
            nums[k]=temp[j++];
            count+=mid-i+1;
        }
    }
    return count;
}


int sort(vector<int>& nums,int lo,int hi){
    //归并排序，返回逆序对数
    if(lo>=hi)return 0;
    if(hi==lo+1){
        if(nums[lo]<=nums[hi])return 0;
        else{
            int temp=nums[lo];
            nums[lo]=nums[hi];
            nums[hi]=temp;
            return 1;
        }
    }
    int mid=(lo+hi)/2;
    int count=sort(nums,lo,mid)+sort(nums,mid+1,hi);
    count+=merge(nums,lo,mid,hi);
    return count;
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
        cout<<sort(nums,0,n-1)<<endl;
    }
    return 0;
}