#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

struct work{
    int d;
    int p;
};

bool cmp(work a,work b){
    return a.p>b.p;
}

int main(){
    int t;
    cin>>t;
    for(int a=0;a<t;++a){
        int n;
        cin>>n;
        vector<work>works=vector<work>(n);
        int max_time=0;
        for(int i=0;i<n;++i){
            cin>>works[i].d>>works[i].p;
            if(works[i].d>max_time)max_time=works[i].d;
        }
        sort(works.begin(),works.end(),cmp);//收益降序
        vector<int>ans=vector<int>(max_time+1);
        for(int i=0;i<n;++i){
            for(int j=works[i].d;j>0;--j){//寻找可选择范围内的空位填入活动，使其尽量晚完成
                if(works[i].p>ans[j]){
                    ans[j]=works[i].p;
                    break;
                }
            }
        }
        long long res=0;
        for(int i=1;i<=max_time;++i)res+=ans[i];
        cout<<res<<endl;
    }
    return 0;
}