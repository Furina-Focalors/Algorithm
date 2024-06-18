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

        mat[0][gems[0].size]=gems[0].value;//初值
        /*
        下一层的值mat[i][j]：
        1）或者等于mat[i-1][j-gems[i].size]+gems[i].value（装入新纳入的宝石，当且仅当对应mat值不为零（即有装入），且该值大于mat[i-1][j]时）；
        2）或者等于gems[i].value（当且仅当gems[i].size==j且该值大于mat[i-1][j]，即刚好装下这一颗）；
        否则等于mat[i-1][j]（忽视新纳入的宝石）
        */
        for(int i=1;i<n;++i){
            for(int j=1;j<=capacity;++j){
                if(j-gems[i].size>=0&&mat[i-1][j-gems[i].size]!=0&&mat[i-1][j-gems[i].size]+gems[i].value>mat[i-1][j]){
                    mat[i][j]=mat[i-1][j-gems[i].size]+gems[i].value;
                }
                else if(gems[i].size==j&&gems[i].value>mat[i-1][j]){
                    mat[i][j]=gems[i].value;
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