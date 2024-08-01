#include <iostream>
using namespace std;

template<class T>
void Tsum(T x, T y) {
    cout << x + y << endl;
}

int main() {
    Tsum<int>(8, 4);
    Tsum<float>(6.7, 5.9);
    Tsum<char>('A', 'B');
    return 0;
}

