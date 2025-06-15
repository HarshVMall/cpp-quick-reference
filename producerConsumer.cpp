#include <iostream>
#include <thread>
#include <condition_variable>
#include <mutex>
#include <stack>
using namespace std;

mutex m1;
condition_variable c;
int bufferSize = 10;
stack<int> buffer;



void consumer() {
    //continuously consume
    while(true) {
        unique_lock<mutex> locker(m1);
        c.wait(locker, []() {return buffer.size() > 0;});
        cout << "Consuming:" << buffer.top() << endl;
        buffer.pop();
        locker.unlock();
        c.notify_one();
    }
}

void producer(int n) {
    while(n > 0) {
        unique_lock<mutex> locker(m1);
        c.wait(locker, []() {return buffer.size() < bufferSize;});
        cout << "Producing:" << n << endl;
        buffer.push(n);
        n--;
        locker.unlock();
        c.notify_one();
    }
}

int main() {
    cout << "Hello Harsh Vardhan Singh Mall!!" << endl;
    cout << "Producer consumer/Bounded buffer problem" << endl;
    cout << "IMP: Notification is must in Producer Consumer problem" << endl;
    
    thread t1(producer, 100);
    thread t2(consumer);
    
    t1.join();
    t2.join();
    
    return 0;
}


