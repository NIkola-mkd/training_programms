/*Возврат результата из потока по ссылке*/

#include <iostream>
#include <thread>
#include <chrono>

using namespace std;


void doWork(int &a) {

    this_thread::sleep_for(chrono::milliseconds(1000));
    cout << "ID:"<<this_thread::get_id()<<"\t" << "doWork started\t====" << endl;
    this_thread::sleep_for(chrono::milliseconds(5000));
    a *= 2;
    cout << "ID:" << this_thread::get_id() << "\t" << "doWork stopped\t====" << endl;
}


int main()
{
    int q = 5;
    thread t(doWork,std::ref(q));
   // doWork(q);
   
    
  
    for (size_t i = 0;i<10;i++) {
        cout << "ID:" << this_thread::get_id() << "\t main works" << i << endl;
        this_thread::sleep_for(chrono::milliseconds(500));
    }
    t.join();
    cout << q << endl;
    return 0;
}
