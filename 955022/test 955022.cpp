#include <iostream>
#include <stack>
using namespace std;
int main() {
    int n;
    while (cin >> n) {
        if (n == 0)break;
        for (;;) {
            int num[1001],t=0;
            stack<int>stk;
            cin >> num[0];
            if (num[0] == 0) {
                cout << "\n";
                break;
            }
            for (int i = 1; i < n; i++)cin >> num[i];
            for (int i = 1; i <= n; i++) {
                stk.push(i);
                while (true) {
                    if (!stk.empty() && stk.top() == num[t]) {
                        t++;
                        stk.pop();
                    }
                    else break;
                }
            }
            if (stk.empty())cout << "Yes\n";
            else cout << "No\n";
        }
    }
}