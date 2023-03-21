#include <iostream>
#include <Windows.h>

using namespace std;

class Numbers {
private:
    int* x;
public:
    Numbers(int size);
    ~Numbers();
    int* get() { return x; }
};

Numbers::Numbers(int size) {
    x = new int[size];
    cout << "Видiлення пам'ятi " << x << endl;
    for (int i = 0; i < size; i++) {
        if (i % 2 == 0) {
            x[i] = i - 4;
        }
        else {
            x[i] = i - 6;
        }
    }
}

Numbers::~Numbers() {
    cout << "Звiльнення пам'ятi " << x << endl;
    delete[] x;
    x = 0;
}

int multi(int size, int* x) {
    int y = 1;
    for (int i = 1; i < size; i += 2) {
        y *= x[i];
    }
    return y;
}

int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    Numbers a = Numbers(8);
    cout << multi(8, a.get()) << endl;
}
