#include<iostream>
#include<string>
#include<vector>
using namespace std;
/*
Time=O(n^2)
Space=O(n^2)

len1*len2 mat[][] where index means the index of the last char in s1,s2
mat[i,j]=mat[i-1,j-1] if s1[i]==s2[j]
mat[i,j]=max(mat[i,j-1],mat[i-1,j]) if s1[i]!=s2[j]
situations where s1[i]==s2[j-1]? is considered in former calculation.
*/
int main(){
    int m;
    cin>>m;
    for(int a=0;a<m;++a){
        string s1,s2;
        cin.ignore();
        cin>>s1>>s2;
        int len1=s1.length(),len2=s2.length();
        vector<vector<int>>mat=vector<vector<int>>(len1);
        for(int i=0;i<len1;++i)mat[i]=vector<int>(len2);

        //initialize the first col
        int temp_index=0;
        for(temp_index=0;temp_index<len1;++temp_index){
            if(s1[temp_index]==s2[0])break;
            mat[temp_index][0]=0;
        }
        for(;temp_index<len1;++temp_index)mat[temp_index][0]=1;

        //initialize the first row
        for(temp_index=0;temp_index<len2;++temp_index){
            if(s2[temp_index]==s1[0])break;
            mat[0][temp_index]=0;
        }
        for(;temp_index<len2;++temp_index)mat[0][temp_index]=1;

        //calculate
        for(int i=1;i<len1;++i){
            for(int j=1;j<len2;++j){
                if(s1[i]==s2[j]){
                    mat[i][j]=mat[i-1][j-1]+1;
                }
                else{
                    mat[i][j]=mat[i][j-1]>mat[i-1][j]?mat[i][j-1]:mat[i-1][j];
                }
            }
        }

        cout<<mat[len1-1][len2-1]<<endl;
    }
    return 0;
}