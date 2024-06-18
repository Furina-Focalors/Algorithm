#include<iostream>
#include<vector>
using namespace std;
//similar to 1007

long long sum(vector<int>& nums,int lo,int hi){
    long long res=0;
    for(int i=lo;i<=hi;++i)res+=nums[i];
    return res;
}

int main(){
    int m;
    cin>>m;
    for(int a=0;a<m;++a){
        int n,k;
        cin>>n>>k;
        vector<int>nums=vector<int>(n);
        for(int i=0;i<n;++i)cin>>nums[i];
        //initialize
        vector<vector<long long>>res=vector<vector<long long>>(k);//行：乘号数 列：末尾元素下标end
        for(int i=0;i<k;++i){
            res[i]=vector<long long>(n);
        }
        //calculate k=1,n=2,3,...,N
        for(int i=1;i<n;++i){
            long long result=0;
            for(int j=0;j<i;++j){//add '*' after nums[j]
                long long temp=sum(nums,0,j)*sum(nums,j+1,i);
                if(temp>result)result=temp;
            }
            res[0][i]=result;
        }
        //calculate k>1
        for(int i=1;i<k;++i){
            //calculate n=k+1 input must satisfy n>k
            
            //calculate n=k+1,k+2,...,N
            for(int j=i+1;j<n;++j){
                //res[i][j]=max(res[i-1][i]*sum(nums,i+1,j),res[i-1][i+1]*sum(nums,i+2,j),...,res[i-1][j-1]*sum(nums,j,j))
                long long r=0;
                for(int b=i;b<=j-1;++b){
                    long long temp=res[i-1][b]*sum(nums,b+1,j);
                    if(temp>r)r=temp;
                }
                res[i][j]=r;
            }
        }
        cout<<res[k-1][n-1]<<endl;
    }
    return 0;
}