#include<iostream>
#include<vector>
using namespace std;

int main(){
    int t;
    cin>>t;
    for(int a=0;a<t;++a){
        int n,e,s,t;//顶点数 边数 起点 终点
        cin>>n>>e>>s>>t;
        if(s==t){
            cout<<0<<endl;
            continue;
        }
        vector<vector<int>>map=vector<vector<int>>(n+1);
        vector<int>dist=vector<int>(n+1);
        vector<bool>visited=vector<bool>(n+1);
        for(int i=1;i<=n;++i){
            map[i]=vector<int>(n+1);
            dist[i]=2147483647;
        }
        for(int i=0;i<e;++i){
            int u,v,w;
            cin>>u>>v>>w;
            if(!map[u][v]||w<map[u][v]){//去重边
                map[u][v]=w;
                map[v][u]=w;
            }
        }

        // for(int i=1;i<=n;++i){
        //     for(int j=1;j<=n;++j){
        //         cout<<map[i][j]<<' ';
        //     }
        //     cout<<endl;
        // }

        //将原点s加入集合
        dist[s]=0;
        visited[s]=true;
        int next=-1,pre_dist=2147483647;
        for(int i=1;i<=n;++i){
            if(map[s][i]){//map[s][i]==0无路径
                dist[i]=map[s][i];
                //寻找距离s最近的点
                if(dist[i]<pre_dist){
                    pre_dist=dist[i];
                    next=i;
                }
            }
        }
        while(next!=-1){
            //将next加入集合，更新距离
            visited[next]=true;
            int temp=next;
            for(int i=1;i<=n;++i){
                if(map[temp][i]&&dist[temp]+map[temp][i]<dist[i]){
                    dist[i]=dist[temp]+map[temp][i]; 
                }
            }
            //从未访问过的点中寻找距离s最近的
            pre_dist=2147483647;
            next=-1;
            for(int i=1;i<=n;++i){
                if(!visited[i]&&dist[i]<pre_dist){
                    next=i;
                    pre_dist=dist[i];
                }
            }
        }
        if(dist[t]!=2147483647)cout<<dist[t]<<endl;
        else cout<<-1<<endl;
    }
    return 0;
}