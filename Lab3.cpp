#include <iostream>
#include <Windows.h>
#include <fstream>
#include <string>

using namespace std;

class Student {
    string lastname, firstname;
    int m, p, i;
public:
    Student();
    Student(string, string, int, int, int);
    ~Student() {}
    string lname();
    string fname();
    int math();
    int phisics();
    int informatics();
};

Student::Student() {
    lastname = "0";
    m = 0;
    p = 0;
    i = 0;
}

Student::Student(string ln, string fn, int m, int p, int i) {
    lastname = ln;
    firstname = fn;
    this->m = m;
    this->p = p;
    this->i = i;
}

string Student::lname() {
    return lastname;
}

string Student::fname() {
    return firstname;
}

int Student::math() {
    return m;
}

int Student::phisics() {
    return p;
}

int Student::informatics() {
    return i;
}

void data() {
    ofstream file("data.txt");
    file << "Іваненко   Іван    3   4   3\nМарченко Ірина   3   2   2\nМельник  Олексій 4   4   3\nБондаренко   Данило  1   2   4\nКравченко    Анастасія   4   5   5\nБойко    Олена   3   5   5\nОлійник  Богдан  4   5   5\nШевчук   Юля 5   4   3\nТкаченко Іван    3   2   2\nРуденко  Анна    3   3   3";
    file.close();
}

int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    int n = 0, m, p, i;
    bool t = 0;
    string str, ln, fn;
    data();
    ifstream file("data.txt");
    if (file.is_open()) {
        while (!file.eof()) {
            getline(file, str, '\n');
            cout << str << endl;
            n++;
        }
        file.seekg(0);
        Student* S = new Student[n];
        for (int j = 0; j < n; j++) {
            file >> ln;
            file >> fn;
            file >> m;
            file >> p;
            file >> i;
            S[j] = Student(ln, fn, m, p, i);
        }
        file.close();
        cout << "Ведіть прізвище та ім'я " << endl;
        cin >> ln;
        cin >> fn;
        for (int j = 0; j < n; j++) {
            if (S[j].lname() == ln && S[j].fname() == fn) {
                cout << "Математика: " << S[j].math() << "; Фізика: " << S[j].phisics() << "; Інформатика: " << S[j].informatics() << "." << endl;
                t = 1;
            }
        }
        if (t == 0) cout << "Помилка! Такого студента нема." << endl;
    }
    else cout << "Помилка! Неможлово відкрити файл" << endl;
}
