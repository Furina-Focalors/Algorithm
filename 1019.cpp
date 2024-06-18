#include<iostream>
#include<vector>
using namespace std;
//动态规划
struct gem{
    int size;
    int value;
};

int main(){
    int m;
    cin>>m;
    for(int a=0;a<m;++a){
        int n,capacity;
        cin>>n>>capacity;
        vector<gem>gems=vector<gem>(n);
        vector<vector<int>>mat=vector<vector<int>>(n);//行：从前i颗宝石中挑选 列：背包大小
        for(int i=0;i<n;++i){
            cin>>gems[i].size>>gems[i].value;
            mat[i]=vector<int>(capacity+1);
        }
        for(int i=gems[0].size;i<=capacity;++i){//初值
            mat[0][i]=gems[0].value;
        }
        for(int i=1;i<n;++i){
            for(int j=1;j<=capacity;++j){
                if(gems[i].size<=j){
                    mat[i][j]=max(gems[i].value+mat[i-1][j-gems[i].size],mat[i-1][j]);
                }
                else{
                    mat[i][j]=mat[i-1][j];
                }
            }
        }
        cout<<mat[n-1][capacity]<<endl;
    }
    return 0;
}