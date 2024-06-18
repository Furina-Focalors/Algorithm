#include<iostream>
#include<vector>
#include<queue>
using namespace std;

class Node{
public:
    Node(int p_v=0,int p_cost=0,int p_len=0)
    :v(p_v),cost(p_cost),len(p_len){}
    bool operator<(const Node& n)const{
        return len>n.len;//len最小的排在优先队列最前面
    }
    int v;
    int cost;
    int len;
};

int main(){
    int t;
    cin>>t;
    for(int a=0;a<t;++a){
        int n_country,e_road,start,target,money;
        cin>>n_country>>e_road>>start>>target>>money;
        int c[n_country+1];//c[i]=到i国的路费
        int map[n_country+1][n_country+1];//邻接矩阵 map[u][v]=w
        int best[n_country+1][money+1];//best[i][j]=k 从s国到i国花费j元需要的总路程为k
        for(int i=1;i<=n_country;++i){
            cin>>c[i];
            for(int j=1;j<=n_country;++j)map[i][j]=0;
            for(int j=0;j<=money;++j)best[i][j]=0;
        }
        for(int i=0;i<e_road;++i){
            int u,v,w;
            cin>>u>>v>>w;
            if(!map[u][v]||map[u][v]>w){//重边取小
                map[u][v]=w;
                map[v][u]=w;
            }
        }
        priority_queue<Node>q;
        //BFS第一层
        for(int i=1;i<=n_country;++i){
            if(map[start][i]&&c[i]<=money){//有路且钱够
                q.push(Node(i,c[i],map[start][i]));
                best[i][c[i]]=map[start][i];
            }
        }
        while(!q.empty()){
            Node cur=q.top();
            if(cur.v==target){//到t国,且由于是优先队列距离一定最短
                cout<<cur.len<<endl;
                break;
            }
            for(int i=1;i<=n_country;++i){
                //遍历邻接矩阵cur.v一行，若v到i有路，检查从s经过v到i的路是否是可选（钱够）或比原先更优（钱相同，路径更短）
                //若有，则加入优先队列之后做下一级检查——BFS
                if(i!=start&&map[cur.v][i]&&cur.cost+c[i]<=money){//有路 钱够 不是s国
                    if(!best[i][cur.cost+c[i]]||cur.len+map[cur.v][i]<best[i][cur.cost+c[i]]){
                        //到某国本来没路 或 到某国花费相同的价格有更短的路
                        q.push(Node(i,cur.cost+c[i],cur.len+map[cur.v][i]));
                        best[i][cur.cost+c[i]]=cur.len+map[cur.v][i];
                    }
                }
            }
            q.pop();
        }
        if(q.empty())cout<<-1<<endl;
    }
    return 0;
}