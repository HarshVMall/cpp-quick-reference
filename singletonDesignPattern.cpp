#include <iostream>
using namespace std;

class Singleton {
    private:
    
    int count;
    //Make constructor private so no one else is able to call it 
    Singleton() {
        cout << "Singleton constructor called!!" << endl;
    }
    
    //Delete copy constructor
    Singleton(const Singleton&) = delete;
    
    //Delete copy assignment operator
    Singleton& operator=(const Singleton&) = delete;
    
    
    public:
    
    //Thread safe static function so that only one instance is available
    static Singleton& getInstance() {
        static Singleton s; //this is thread safe by modern compilers
        return s;
    }
    
    void setCountValue(int i) {
        count = i;
    }
    
    int incrementCount() {
        count++;
        return count;
    }
};

int main() {
    cout << "Hello Harsh Vardhan!" << endl;
    Singleton &s1 = Singleton::getInstance();
    Singleton &s2 = Singleton::getInstance();
    
    s1.setCountValue(5);
    int tempCount = s2.incrementCount();
    cout << "Count value is: " << tempCount << endl;
    return 0;
}
