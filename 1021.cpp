#include<iostream>
#include<vector>
using namespace std;

struct price{
    int length;
    int profit;
};

int main(){
    int m;
    cin>>m;
    for(int a=0;a<m;++a){
        int n,k;
        cin>>n>>k;
        vector<price>table=vector<price>(k);
        for(int i=0;i<k;++i){
            cin>>table[i].length>>table[i].profit;
        }
        vector<int>res=vector<int>(n+1);//index=length,value=max profit
        for(int i=1;i<=n;++i){
            int max=res[i-1];
            for(int j=0;j<k;++j){
                if(i>=table[j].length){
                    int temp=table[j].profit+res[i-table[j].length];
                    if(temp>max)max=temp;
                }
            }
            res[i]=max;
            //cout<<"res["<<i<<"]="<<res[i]<<endl;
        }
        cout<<res[n]<<endl;
    }
    return 0;
}