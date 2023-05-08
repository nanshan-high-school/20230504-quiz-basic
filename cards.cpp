#include <iostream>
#include <queue>
using namespace std;

int main() {
    int n;
    cin >> n;
    
    while (!(n == 0)) {
        queue<int> cards;
        
        for (int i = 1; i <= n; i++) {
            cards.push(i);
        }
        
        cout << "Discarded cards: ";
        
        while (cards.size() > 1) {
            cout << cards.front();
            if (cards.size() == 2) {
                cout << "";
            } else {
                cout << ", ";
            }

            cards.pop();
            cards.push(cards.front());
            cards.pop();
        }
        
        cout << endl << "Remaining card: " << cards.front() << endl;
        cin >> n;
    }
}