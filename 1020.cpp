#include<iostream>
#include<vector>
using namespace std;
//动态规划
struct mat{
    int row;
    int col;
};

int main(){
    int m;
    cin>>m;
    for(int a=0;a<m;++a){
        int n;
        cin>>n;
        vector<mat>matrices=vector<mat>(n);
        for(int i=0;i<n;++i){
            cin>>matrices[i].row>>matrices[i].col;
        }
        vector<vector<int>>res=vector<vector<int>>(n);//行：start 列：end
        for(int i=0;i<n-1;++i){
            res[i]=vector<int>(n);
            res[i][i]=0;
            res[i][i+1]=matrices[i].row*matrices[i+1].row*matrices[i+1].col;
            //cout<<"res["<<i<<"]["<<i+1<<"]="<<res[i][i+1]<<endl;
        }
        res[n-1]=vector<int>(n);
        for(int step=2;step<n;++step){
            for(int start=0;start+step<n;++start){
                int end=start+step;
                //cout<<"start="<<start<<", end="<<end<<endl;
                int min=2147483647;
                /* res[start][end]=min{start<=k<end}(res[start,k]+res[k+1,end]+mat[start].row*mat[k].col*mat[end].col) */
                for(int k=start;k<end;++k){
                    int temp=res[start][k]+res[k+1][end]+matrices[start].row*matrices[k].col*matrices[end].col;
                    //cout<<"k="<<k<<", temp="<<temp<<endl;
                    if(temp<min)min=temp;
                }
                res[start][end]=min;
            }
        }
        cout<<res[0][n-1]<<endl;
    }
    return 0;
}