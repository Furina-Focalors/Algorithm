#include<iostream>
#include<iomanip>
#include<algorithm>
#include<cmath>
#include<vector>
using namespace std;
//time=O(nlogn)
//space=O(n)
struct point{
    double x;
    double y;
};

bool compare_x(point a,point b){
    if(a.x!=b.x)return a.x<b.x;
    return a.y<b.y;
}

bool compare_y(point a,point b){
    if(a.y!=b.y)return a.y<b.y;
    return a.x<b.x;
}

double dist(point a,point b){
    return sqrt((a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y));
}

double closest_point_pair(vector<point>& p,int i,int j){//返回p[i:j+1]中最短距离
    int n=j-i+1;
    if(n==2){
        return dist(p[i],p[j]);
    }
    else if(n<2)return __DBL_MAX__;
    double mid=p[(i+j)/2].x;
    int m=n%2?n/2:n/2-1;
    double d1=closest_point_pair(p,i,i+m);//left
    double d2=closest_point_pair(p,i+m+1,j);//right
    double d=min(d1,d2);
    //critical
    vector<point>critical;
    for(int k=i;k<=j;++k){
        if(p[k].x>=mid-d&&p[k].x<=mid+d)critical.emplace_back(p[k]);
    }
    sort(critical.begin(),critical.end(),compare_y);
    int size=critical.size();
    for(int k1=0;k1<size;++k1){
        for(int k2=k1+1;k2<k1+7&&k2<size;++k2){//抽屉原理 最多只需要比较6次
            double di=dist(critical[k1],critical[k2]);
            if(di<d)d=di;
        }
    }
    return d;
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
        sort(p.begin(),p.end(),compare_x);
        cout<<fixed<<setprecision(2)<<closest_point_pair(p,0,p.size())<<endl;
    }
    return 0;
}