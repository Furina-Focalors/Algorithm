// #include<iostream>
// using namespace std;

// int main(){
//     int nums;
//     cin>>nums;
//     while(nums--){
//         int m,n,target;
//         cin>>m>>n>>target;
//         int k=m*n;
//         bool ans=false;
//         for(int i=0;i<k;++i){
//             int temp;
//             cin>>temp;
//             ans=ans||(temp==target);
//         }
//         if(ans)cout<<"true"<<endl;
//         else cout<<"false"<<endl;
//     }
//     return 0;
// }

#include<iostream>
using namespace std;

bool search(int** mat,int m,int n,int target){
    int i=0,j=n-1;//从右上角开始搜索
    while(i<m&&j>=0){
        if(mat[i][j]==target){
            return true;
        }
        else if(mat[i][j]>target){
            --j;
        }
        else ++i;
    }
    return false;
}

int main(){
    int nums;
    cin>>nums;
    while(nums--){
        int m,n,target;
        cin>>m>>n>>target;
        int** mat=new int*[m];
        for(int i=0;i<m;++i){
            mat[i]=new int[n];
            for(int j=0;j<n;++j){
                cin>>mat[i][j];            
            }
        }
        if(search(mat,m,n,target))cout<<"true"<<endl;
        else cout<<"false"<<endl;
    }
    return 0;
}