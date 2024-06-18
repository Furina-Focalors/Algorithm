#include<iostream>
#include<vector>
using namespace std;
//prim algorithm

int main(){
    int t;
    cin>>t;
    for(int a=0;a<t;++a){
        int n,e;
        cin>>n>>e;
        vector<vector<int>>map=vector<vector<int>>(n+1);
        for(int i=1;i<=n;++i){
            map[i]=vector<int>(n+1);
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

        int ans=0;
        vector<int>set=vector<int>(n);//已加入最小生成树的点的集合（下标）
        vector<bool>visited=vector<bool>(n+1);
        set[0]=1;
        visited[1]=true;
        int cur=0;
        while(cur<n-1){
            //寻找与集合内点关联的最小边
            int next=-1,len=2147483647;
            for(int i=0;i<=cur;++i){
                for(int j=1;j<=n;++j){
                    if(!visited[j]&&map[set[i]][j]&&map[set[i]][j]<len){
                        len=map[set[i]][j];
                        next=j;
                    }
                }
            }
            if(next==-1){
                break;
            }
            else{
                ans+=len;
                ++cur;
                set[cur]=next;
                visited[next]=true;
            }
        }
        if(cur!=n-1){
            cout<<-1<<endl;
        }
        else{
            cout<<ans<<endl;
        }
    }
    return 0;
}