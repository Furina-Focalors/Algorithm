#include<iostream>
#include<queue>
using namespace std;

int main(){
    int m;
    cin>>m;
    for(int a=0;a<m;++a){
        int n;
        cin>>n;
        queue<int>zeros;
        queue<int>ones;
        int ans=0;
        for(int i=0;i<2*n;++i){
            int x;
            cin>>x;
            if(x){//1
                if(!zeros.empty()){
                    ans+=i-zeros.front();
                    zeros.pop();
                }
                else{
                    ones.push(i);
                }
            }
            else{//0
                if(!ones.empty()){
                    ans+=i-ones.front();
                    ones.pop();
                }
                else{
                    zeros.push(i);
                }
            }
        }
        cout<<ans<<endl;
    }
    return 0;
}