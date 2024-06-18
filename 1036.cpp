#include<iostream>
using namespace std;

void calculate_next(int* next,char* t,int m){
    int j=0,k=-1;
    next[0]=-1;
    while(j<m-1){
        if(k==-1||t[j]==t[k]){
            ++j;++k;
            next[j]=k;
        }
        else{
            k=next[k];
        }
    }
}

int main(){
    int t;
    cin>>t;
    while(t--){
        int n,m;
        cin>>n>>m;
        char* s=new char[n];
        char* t=new char[m];
        for(int i=0;i<n;++i){
            cin>>s[i];
        }
        for(int i=0;i<m;++i){
            cin>>t[i];
        }
        int* next=new int[m];
        calculate_next(next,t,m);
        int s_ptr=0,count=0;
        while(s_ptr<n){
            int t_ptr=0;
            while(s_ptr<n&&t_ptr<m){
                if(t_ptr==-1||t[t_ptr]==s[s_ptr]){
                    ++s_ptr;++t_ptr;
                }
                else{
                    t_ptr=next[t_ptr];
                }
            }
            if(t_ptr==m){//匹配
                ++count;
                s_ptr-=(m-1);
            }
        }
        cout<<count<<endl;
        delete[] s;
        delete[] t;
        delete[] next;
    }
    return 0;
}