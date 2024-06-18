#include<iostream>
using namespace std;

int main(){
    int n;
    cin>>n;
    char** str=new char*[n];//initialize 2-dimentional array
    cin.ignore();
    /* equivalent to cin.ignore();
        char* temp=new char;
        cin.getline(temp,1,'\n');
        delete temp;
    */
    for(int i=0;i<n;++i){
        str[i]=new char[100];
        cin.getline(str[i],100,'\n');
    }
    for(int i=0;i<n;++i){
        int res=0;
        for(int j=0;str[i][j]!='\0';++j){
            if(str[i][j]>='0'&&str[i][j]<='9')++res;
        }
        cout<<res<<endl;
    }
    delete[] str;
    return 0;
}