#include <iostream>
#include <algorithm>
using namespace std;

//Implementing rule of 5
//if Heap memory is allocated, rule of 5 should be implemented
class ResourceClass {
    private:
        int* arr; /// Heap memory
        size_t size;
    
    public:
        //Constructor
        ResourceClass(size_t s) {
            size = s;
            arr = new int[s];
            cout << "Default constructor called!!" << endl;
        }
        
        //Rule of 5 functions
        
        //Destructor
        ~ResourceClass() {
            cout << "Destructor called!!" << endl;
            delete[] arr;
        }
        
        //Copy constructor
        ResourceClass(const ResourceClass& that) {
            this->size = that.size;
            this->arr = new int[size];
            copy(that.arr, that.arr + size, this->arr);
            cout << "Copy constructor called!!" << endl;
        }
        
        //Copy assignment operator
        ResourceClass& operator=(const ResourceClass& that) {
            if(this != &that) {
                delete[] arr;
                this->size = that.size;
                this->arr = new int[size];
                copy(that.arr, that.arr + size, this->arr);
                cout << "Copy assignment operator called!!" << endl;
            }
            return *this;
        }
        
        //Move constructor
        ResourceClass(ResourceClass&& that) {
            this->size = that.size;
            this->arr = that.arr;
            
            that.size = 0;
            that.arr = nullptr;
            cout << "Move constructor called!!" << endl;
        }
        
        //Move assignment operator
        ResourceClass& operator=(ResourceClass&& that) {
            if(this != &that) {
                delete[] arr;
                this->size = that.size;
                this->arr = that.arr;
                
                that.size = 0;
                that.arr = nullptr;
                cout << "Move assignment operator called!!" << endl;
            }
            
            return *this;
        }
    
};


int main() {
    //cout << "Hello Harsh Vardhan!!";
    ResourceClass a(10);
    ResourceClass b(20);
    ResourceClass c = b;
    a = b;
    ResourceClass d(b);
    
    ResourceClass e = move(a);
    ResourceClass f(move(a));
    e = move(b);
    return 0;
}
