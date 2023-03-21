#include <iostream>
#include <Windows.h>

using namespace std;

class UnsignedNum {
    int num;
public:
    UnsignedNum(int n) { num = n; }
    virtual void print_num() = 0;
    int get_num() { return num; }
};

class BinaryNum :public UnsignedNum {
public:
    BinaryNum(int x) :UnsignedNum(x) {}
    void print_num() {
        int y = 0, i = 0, n = get_num();
        while (n != 0) {
            if (n % 2 == 1) {
                y += pow(10, i);
            }
            n = n / 2;
            i++;
        }
        cout << "Двійкова: " << y << endl;
    }
};

class DecimalNum :public UnsignedNum {
public:
    DecimalNum(int x):UnsignedNum(x) {}
    void print_num() {
        cout << "Десяткова: " << get_num() << endl;
    }
};

class HexadecimalNum :public UnsignedNum {
public:
    HexadecimalNum(int x) :UnsignedNum(x) {}
    void print_num() {
        string hexNum;
        int y, n = get_num();
        while (n > 0) {
            y = n % 16;
            if (y < 10) {
                hexNum = char(y + 48) + hexNum;
            }
            else {
                hexNum = char(y + 55) + hexNum;
            }
            n /= 16;
        }
        cout << "шістнадцяткова: " << (hexNum == "" ? "0" : hexNum) << endl;
    }
};

int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    int n = 28;
    BinaryNum b(n);
    DecimalNum c(n);
    HexadecimalNum d(n);
    UnsignedNum* a[3];
    a[0] = &b;
    a[1] = &c;
    a[2] = &d;
    for (int i = 0; i < 3; i++) {
        a[i]->print_num();
    }
}