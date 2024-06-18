#include<iostream>
#include<vector>
#include<iomanip>
using namespace std;
//DP

int main(){
    int m;
    cin>>m;
    for(int x=0;x<m;++x){
        int n;
        cin>>n;
        vector<int>keys=vector<int>(n);
        for(int i=0;i<n;++i){
            cin>>keys[i];
        }
        vector<double>a=vector<double>(n);//搜索keys[i]的概率
        for(int i=0;i<n;++i){
            cin>>a[i];
        }
        vector<double>b=vector<double>(n+1);//搜索(keys[i-1],keys[i])区间内的概率
        for(int i=0;i<n+1;++i){
            cin>>b[i];
        }
        vector<vector<double>>c=vector<vector<double>>(n);//c[i][j]=keys[i:j+1]中的元素构造的最优二叉树的代价
        for(int i=0;i<n;++i){
            c[i]=vector<double>(n);
            c[i][i]=a[i]+b[i]+b[i+1];//初始化
        }
        for(int step=1;step<n;++step){
            for(int lo=0,hi=lo+step;hi<n;++lo,++hi){
                /* c(i,j) = w(i,j)  +  min{ c(i,k-1) +  c(k+1,j) }, 其中i <= k <= j */

                //cout<<lo<<' '<<hi<<endl;
                double w=0.0;
                for(int i=lo;i<=hi;++i){
                    w+=(a[i]+b[i]);
                }
                w+=b[hi+1];
                //cout<<"w="<<w<<endl;
                double cmin=min(c[lo+1][hi],c[lo][hi-1]);//无左子树、无右子树
                for(int k=lo+1;k<hi;++k){
                    double temp=c[lo][k-1]+c[k+1][hi];
                    if(temp<cmin)cmin=temp;
                }
                c[lo][hi]=w+cmin;
                //cout<<"c[lo][hi]="<<c[lo][hi]<<endl;
            }
        }
        cout<<fixed<<setprecision(6)<<c[0][n-1]<<endl;
    }
    return 0;
}