#include<iostream>
#include<vector>
#include<cmath>
#include<algorithm>
using namespace std;

struct point{
    double x;
    double y;
};

struct edge{//最下以外的另一点pt，夹角angle
    point pt;
    double angle;
    double len;
};

bool compare(edge a,edge b){
    if(a.angle==b.angle){
        return a.len<b.len;
    }
    return a.angle<b.angle;
}

bool rotate_anticlockwise(edge a,edge b,edge center){
    //center->a到center->b为逆时针旋转返回1;

    // cout<<"pi="<<a.pt.x<<' '<<a.pt.y<<endl;
    // cout<<"pi+1="<<b.pt.x<<' '<<b.pt.y<<endl;
    // cout<<"center="<<center.pt.x<<' '<<center.pt.y<<endl;

    double x1=a.pt.x-center.pt.x,y1=a.pt.y-center.pt.y;
    double x2=b.pt.x-center.pt.x,y2=b.pt.y-center.pt.y;
    //单位化
    double len1=sqrt(x1*x1+y1*y1),len2=sqrt(x2*x2+y2*y2);
    x1/=len1;
    y1/=len1;
    x2/=len2;
    y2/=len2;
    // cout<<"(x1,y1)=("<<x1<<","<<y1<<")"<<endl;
    // cout<<"(x2,y2)=("<<x2<<","<<y2<<")"<<endl;
    return y1*x2<=y2*x1;//共线将线上的点去掉
}

int main(){
    int m;
    cin>>m;
    for(int a=0;a<m;++a){
        int n;
        cin>>n;
        vector<point>p=vector<point>(n);
        for(int i=0;i<n;++i){
            cin>>p[i].x>>p[i].y;
        }
        point p0=p[0];
        for(int i=0;i<n;++i){
            if(p[i].y<p0.y||(p[i].y==p0.y&&p[i].x<p0.x)){
                p0=p[i];
            }
        }
        vector<edge>e=vector<edge>(n);
        for(int i=0;i<n;++i){//计算夹角和长度
            e[i].pt=p[i];
            e[i].angle=atan2(p[i].y-p0.y,p[i].x-p0.x);
            e[i].len=sqrt((p[i].y-p0.y)*(p[i].y-p0.y)+(p[i].x-p0.x)*(p[i].x-p0.x));
        }
        sort(e.begin(),e.end(),compare);//按夹角排序
        
        vector<edge>stac=vector<edge>(n);
        stac[0]=e[0];
        stac[1]=e[1];
        stac[2]=e[2];
        int top=2;//栈顶指针
        for(int i=3;i<n;++i){
            if(stac[top].pt.x==e[i].pt.x&&stac[top].pt.y==e[i].pt.y)continue;//去除重复点

            while(rotate_anticlockwise(stac[top],stac[top-1],e[i])){//构造向量，确定旋转方向，逆时针则栈顶元素不在凸包上，出栈
                --top;
            }
            ++top;
            stac[top]=e[i];
        }
        cout<<"case "<<a+1<<":\n";
        cout<<stac[0].pt.x<<' '<<stac[0].pt.y<<endl;
        if(stac[1].angle!=stac[2].angle)cout<<stac[1].pt.x<<' '<<stac[1].pt.y<<endl;//第二个点未判断共线
        for(int i=2;i<=top;++i){
            cout<<stac[i].pt.x<<' '<<stac[i].pt.y<<endl;
        }
    }
    return 0;
}