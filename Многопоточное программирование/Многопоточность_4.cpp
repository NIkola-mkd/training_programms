/*Лямбда выражения*/

#include <iostream>
#include <thread>
#include <chrono>

using namespace std;


int Sum(int a, int b) {

    this_thread::sleep_for(chrono::milliseconds(2000));
    cout << "ID thread = " << this_thread::get_id() << "\tSum started\t====" << endl;
    this_thread::sleep_for(chrono::milliseconds(5000));
    cout << "ID thread = " << this_thread::get_id()<< "\tSum stopped\t====" << endl;
    return a + b;
}

int main()
{
    int result;
    //thread t([]() {}) синтаксис лямда функции
    //cout << "\tSum: " << result << endl;

    thread t([&result]() {result = Sum(2, 8);});

    for (size_t i = 1;i <= 10;i++) {

        cout << "ID thread = " << this_thread::get_id() << "\t main works\t" << i << endl;
        this_thread::sleep_for(chrono::milliseconds(500));
    }
    t.join();
    cout << result;
    return 0;
}