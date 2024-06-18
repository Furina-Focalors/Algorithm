#include<iostream>
#include<algorithm>
#include<vector>
#include<cmath>
using namespace std;

struct point{
    double x;
    double y;
    double c;//右侧半径为d的圆的圆心，即使(x,y)在圆周上的圆心在x轴上，半径为d的圆的圆心（若有两个取右侧）
};

bool compare_c(point a,point b){
    return a.c<b.c;
}

int main(){
    int m;
    cin>>m;
    for(int a=0;a<m;++a){
        int n,d;
        cin>>n>>d;
        if(n==0){
            cout<<0<<endl;
            return 0;
        }
        vector<point>p=vector<point>(n);
        for(int i=0;i<n;++i){
            cin>>p[i].x>>p[i].y;
            p[i].c=p[i].x+sqrt(d*d-p[i].y*p[i].y);
        }
        sort(p.begin(),p.end(),compare_c);
        // for(int i=0;i<n;++i){
        //     cout<<'('<<p[i].x<<','<<p[i].y<<"), c=("<<p[i].c<<",0)\n";
        // }
        vector<double>c=vector<double>(n);//被选中的圆心横坐标
        int count=1;
        c[0]=p[0].c;
        for(int i=1;i<n;++i){//遍历所有点
            int j;
            for(j=0;j<count;++j){
                if((p[i].x-c[j])*(p[i].x-c[j])+p[i].y*p[i].y-d*d<=1e-10)break;//有一个圆覆盖就ok
            }
            if(j==count){//未被所有圆覆盖
                c[count]=p[i].c;
                ++count;
            }
        }
        cout<<count<<endl;
    }
    return 0;
}