#include <iostream>

using namespace std;

class smiley {
    double R1, r2;
public:
    smiley();
    smiley(double, double);
    ~smiley();
    void setR1(double);
    void setR2(double);
    int square();
    void print_sqrt();
};

smiley::smiley() {
    R1 = 0;
    r2 = 0;
    cout << "Конструктор без параметрів викликаний для об'єкта " << this << endl;
}

smiley::smiley(double R1, double r2) {
    this->R1 = R1;
    this->r2 = r2;
    cout << "Конструктор з параметрами викликаний для об'єкта " << this << endl;
}

smiley::~smiley() {
    cout << "Деструктор викликаний для об'єкта " << this << endl;
}

void smiley::setR1(double a) {
    R1 = a;
}

void smiley::setR2(double a) {
    r2 = a;
}

int smiley::square() {
    int S;
    S = R1 * R1 * 2 * 3.14;
    cout << "Площа= " << S << endl;
    return S;
}

void smiley::print_sqrt() {
    cout << "Радіус смайлика= " << R1 <<"\nРадіус очей смайлика= "<< r2 << "\nПлоща смайлика без очей: " << square() - 3.14 * r2 * r2 * 4 << endl;
}

int main() {
    setlocale(0, "");
    smiley a;
    a = smiley::smiley(4, 1);
    a.smiley::square();
    a.smiley::print_sqrt();
    a.smiley::setR1(5);
    a.smiley::setR2(2);
    a.smiley::square();
    a.smiley::print_sqrt();
}
