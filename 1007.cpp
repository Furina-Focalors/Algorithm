#include<iostream>
#include<vector>
using namespace std;
//time=O(n^2*k)
//space=O(n*k)
long long get_substr_val(char *str,int start,int end){
    long long res=0;
    long long radix=1;
    for(int i=end;i>=start;--i){
        res+=radix*(str[i]-'0');
        radix*=10;
    }
    return res;
}

int main(){
    int m;
    cin>>m;
    for(int a=0;a<m;++a){
        int n,k;
        cin>>n>>k;
        char *str=new char[n];
        cin>>str;
        //initialize
        vector<vector<long long>>res=vector<vector<long long>>(k);
        for(int i=0;i<k;++i){
            res[i]=vector<long long>(n);
        }
        //calculate k=1,n=2,3,...,N
        for(int i=1;i<n;++i){
            long long result=0;
            for(int j=0;j<i;++j){//add '*' after str[j]
                long long temp=get_substr_val(str,0,j)*get_substr_val(str,j+1,i);
                if(temp>result)result=temp;
            }
            res[0][i]=result;
        }
        //calculate k>1
        for(int i=1;i<k;++i){
            //calculate n=k+1 input must satisfy n>k
            // int r=1;
            // for(int tmp=0;tmp<i+1;++tmp){
            //     r*=(int)str[i];
            // }
            // res[i][i+1]=r;
            
            //calculate n=k+1,k+2,...,N
            for(int j=i+1;j<n;++j){
                //res[i][j]=max(res[i-1][i]*get_substr_val(str,i+1,j),res[i-1][i+1]*get_substr_val(str,i+2,j),...,res[i-1][j-1]*get_substr_val(str,j,j))
                long long r=0;
                for(int b=i;b<=j-1;++b){
                    long long temp=res[i-1][b]*get_substr_val(str,b+1,j);
                    if(temp>r)r=temp;
                }
                res[i][j]=r;
            }
        }
        cout<<res[k-1][n-1]<<endl;
    }
    return 0;
}