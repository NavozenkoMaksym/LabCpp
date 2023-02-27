#include <iostream>

using namespace std;

class Konus {
public:
    float h, r;
    Konus();
    Konus(float, float);
    ~Konus() {}
    void hkonus(float);
    void rkonus(float);
    float vkonus();
    void  print_val();
    friend Konus frd(Konus a, Konus b);
};

Konus::Konus() {
    h = 0;
    r = 0;
    cout << "Конструктор викликаний об'єкта " << this << endl;
}

Konus::Konus(float a, float b) {
    h = a;
    r = b;
}

void Konus::hkonus(float a) {
    h = a;
}

void Konus::rkonus(float a) {
    r = a;
}

float Konus::vkonus() {
    float V;
    V = (3.14 * pow(r, 2) * h) / 3;
    return V;
}

void  Konus::print_val() {
    cout << "r=" << r << "\n" << "h=" << h << "\n" << "V=" << vkonus() << endl;
}

Konus frd(Konus a, Konus b) {
    float h, r;
    h = a.h + b.h;
    if (a.r > b.r) {
        r = a.r;
    }
    else r = b.r;
    return Konus(h, r);
}

int main()
{
    setlocale(0, "Ukr");
    Konus k1, k2, k3;
    k1 = Konus(15, 6);
    k2 = Konus(7, 9);
    cout << "k1:" << endl;
    k1.print_val();
    k1.hkonus(5);
    k1.rkonus(13);
    cout << "k1:" << endl;
    k1.print_val();
    frd(k1, k2);
    cout << "k3:" << endl;
    k3 = frd(k1,k2);
    k3.print_val();
}
