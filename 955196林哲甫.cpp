#include <iostream>
#include <queue>
#include <vector>
using namespace std;
bool find(vector<int> q, int a);//找出是否有相同的數
bool endcheck(vector<int> q, vector<int> a);//確認結果
int main() {
  vector<int> first;
  int a;
  while (true) {
    cin >> a;
    if (a == 0) {
      break;
    }
    //設定初始列車
    for (int i = a; i > 0; i--) {
      first.push_back(i);
    }
    while (true) {
      queue<int> end;
      vector<int> endcopy;
      //重置初始列車
      for (int i = a; i > 0; i--) {
        first.push_back(i);
      }
      //輸入
      for (int i = a; i > 0; i--) {
        int z;
        cin >> z;
        if (z == 0) {
          break;
        }
        end.push(z);
        endcopy.emplace_back(z);
      }
      if (end.size() == 0) {
        break;
      }
      vector<int> second;
      vector<int> last;
      while (true) {

        if (endcheck(last, endcopy)) {
          cout << "Yes\n";
          break;
        }
        if (end.size() == 0) {
          cout << "No\n";
          break;
        }
        //移動
        if (find(first, end.front())) {
          second.push_back(first[first.size() - 1]);
          first.pop_back();
        } else if (find(second, end.front())) {
          last.push_back(second[second.size() - 1]);
          second.pop_back();
          end.pop();
        } else if (!endcheck(last, endcopy)) {
          cout << "No\n";
          break;
        }
      }
    }
  }
}
bool find(vector<int> q, int a) {
  for (int i = 0; i < q.size(); i++) {
    if (q[i] == a) {
      return true;
    }
  }
  return false;
}
bool endcheck(vector<int> q, vector<int> a) {
  if (q.size() != a.size()) {
    return false;
  }
  for (int i = 0; i < a.size(); i++) {
    if (q[i] != a[i]) {
      return false;
    }
  }
  return true;
}
