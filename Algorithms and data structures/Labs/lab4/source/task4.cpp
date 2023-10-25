// Задача №3050. Ханойские башни

#include <iostream>

using namespace std;

void hanoiTower(int n, int source, int auxiliary, int target) {
    if (n == 1) {
        cout << n << " " << source << " " << target << endl;
        return;
    }
    
    hanoiTower(n - 1, source, target, auxiliary);
    cout << n << " " << source << " " << target << endl;
    hanoiTower(n - 1, auxiliary, source, target);
}

int main() {
    int n;
    cin >> n;
    
    hanoiTower(n, 1, 2, 3);
}