#include<iostream>
using namespace std;

int main(){
    int m;
    cin>>m;
    int** arr=new int*[m];
    int* size=new int[m];
    int n;
    for(int i=0;i<m;++i){
        cin>>n;
        arr[i]=new int[n];
        size[i]=n;
        for(int j=0;j<n;++j){
            cin>>arr[i][j];
        }
    }
    for(int i=0;i<m;++i){
        int smallest=INT32_MAX,second_smallest=INT32_MAX;
        for(int j=0;j<size[i];++j){
            if(arr[i][j]<=smallest){
                second_smallest=smallest;
                smallest=arr[i][j];
            }
            else if(arr[i][j]<second_smallest){
                second_smallest=arr[i][j];
            }
        }
        cout<<second_smallest<<endl;
    }
    delete[] arr;
    delete[] size;
    return 0;
}