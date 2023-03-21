#include <iostream>
#include <Windows.h>

using namespace std;                                                       //            Тест
                                                                           //             | - - -> Випробування
class Test {                                                               //             V
private:                                                                   //           Іспит
    string subject, testName;                                              //             |
    int numQuestions;                                                      //             V
public:                                                                    //       Випускний іспит
    Test(string sub, string name, int num) {
        subject = sub;
        testName = name;
        numQuestions = num;
    }
    ~Test() {}
    void set_numQuestions(int x) { numQuestions = x; }
    void set_subject(string x) { subject = x; }
    void set_testName(string x) { testName = x; }
    int get_numQuestions(){ return numQuestions; }
    string get_subject() { return subject; }
    string get_testName() { return testName; }
    void print_infoTest() {
        cout << "Предмет: " << subject << "\nТест: " << testName << "\nКількість питаннь: " << numQuestions << "\n---------------------" << endl;
    }
};

class Exam : public Test {
private:
    int timeLimit;
public:
    Exam(string sub, string name, int num, int time) :Test(sub, name, num) { timeLimit = time; }
    ~Exam() {}
    void set_timeLimit(int x) { timeLimit = x; }
    int get_timeLimit() { return timeLimit; }
    void print_infoExam() {
        cout << "Предмет: " << get_subject() << "\nІспит: " << get_testName() << "\nКількість питаннь: " << get_numQuestions() << endl;
        cout << "Час виконання: " << timeLimit << " хв" << "\n---------------------" << endl;
    }
};

class FinalExam: public Exam {
private:
    int passingScore;
public:
    FinalExam(string sub, string name, int num, int time, int p) :Exam(sub, name, num, time) { passingScore = p; }
    void set_passingScore(int x) { passingScore = x; }
    int get_passingScore() { return passingScore; }
    void print_infoFinalExam() {
        cout << "Предмет: " << get_subject() << "\nВипускний іспит: " << get_testName() << "\nКількість питаннь: " << get_numQuestions() << endl;
        cout << "Час виконання: " << get_timeLimit() << " хв" << "\nМінімальна кількість балів для проходження: " << passingScore << "\n---------------------" << endl;
    }
};

class Quiz : public Test {
private:
    int passingScore;
public:
    Quiz(string sub, string name, int num, int p) :Test(sub, name, num) { passingScore = p; }
    void set_passingScore(int x) { passingScore = x; }
    int get_passingScore() { return passingScore; }
    void print_infoQiuz() {
        cout << "Предмет: " << get_subject() << "\nВипробування: " << get_testName() << "\nКількість питаннь: " << get_numQuestions() << endl;
        cout << "Мінімальна кількість балів для проходження: " << passingScore << "\n---------------------" << endl;
    }
};

int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    Test a("Математика", "#1", 10);
    a.print_infoTest();
    Exam b("Фізика", "#2", 12, 45);
    b.print_infoExam();
    FinalExam c("Біологія", "#3", 20, 120, 60);
    c.print_infoFinalExam();
    Quiz d("Хімія", "#4", 15, 60);
    d.print_infoQiuz();
}