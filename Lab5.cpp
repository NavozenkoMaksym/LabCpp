#include <iostream>
#include <Windows.h>

using namespace std;

class Smiley {
private:
    float R, r;
public:
    Smiley() { R = 0; r = 0; }
    Smiley(float a, float b) { R = a; r = b; }
    ~Smiley() {}
    void SetR(float a) { R = a; }
    void Setr(float a) { r = a; }
    float getR() { return R; }
    float getr() { return r; }
    float getS();
    friend ostream& operator <<(ostream& str, Smiley& obj);
    Smiley operator + (Smiley& obj);
    Smiley operator ++ (int i);
};

float Smiley::getS() {
    float S;
    S = 3.14 * pow(R, 2);
    return S;
}

ostream& operator <<(ostream& str, Smiley& obj) {
    str << "\nРадіус обличчя: " << obj.R << "\nРадіус очей: " << obj.r << "\nПлоща без очей: " << obj.getS() - 2 * 3.14 * pow(obj.r, 2);
    return str;
}

Smiley Smiley::operator + (Smiley& obj) {
    Smiley x(R + obj.R, r + obj.r);
    return x;
}

Smiley Smiley::operator ++ (int i) {
    R++;
    r++;
    return *this;
}

int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    Smiley a, b, c;
    a = Smiley(10, 2);
    b = Smiley(7, 1);
    cout << "a:" << a << "\nb:" << b << endl;
    c = a + b;
    cout << "c = a + b" << c << endl;
    a++;
    cout << "a++:" << a << endl;
}