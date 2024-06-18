#include<iostream>
using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        long* c = new long[n+1];
        for (int i = 1; i <= n; ++i) {
            cin >> c[i];
        }
        
        long y;
        cin>>y;
        long cur_cost = c[1];
        long ans = c[1]*y;
        for (int i = 2; i <= n; ++i) {
            cin >> y;
            cur_cost = min(cur_cost + 1, c[i]);// 第i个月生产，储存j个月的成本等价于在第i+j个月以c[i]+j的成本生产
            ans += cur_cost * y;
        }
        cout << ans << endl;
        delete[] c;
    }
    return 0;
}