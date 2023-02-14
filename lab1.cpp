#include <iostream>

using namespace std;

class smiley {
    double R1, r2;
public:
    smiley();
    smiley(double, double);
    ~smiley();
    void set(double, double);
    void square();
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

void smiley::set(double a, double b) {
    this->R1 = a;
    this->r2 = b;
}

void smiley::square() {
    cout << "Площа= " << R1 * R1 * 2 * 3.14 << endl;
}

void smiley::print_sqrt() {
    cout << "Радіус смайлика= " << R1 <<"\nРадіус очей смайлика= "<< r2 << "\nПлоща смайлика без очей: " << 2 * 3.14 * R1 * R1 - 3.14 * r2 * r2 * 4 << endl;
}

int main() {
    setlocale(0, "");
    smiley a;
    a = smiley::smiley(4, 1);
    a.smiley::square();
    a.smiley::print_sqrt();
    a.smiley::set(5, 2);
    a.smiley::square();
    a.smiley::print_sqrt();
}