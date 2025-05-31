#include <iostream>
#include <vector>
using namespace std;


class PageObject {
    virtual void add() {};
    virtual void erase() {};
};


class Page : public PageObject {
    public:
    
    void add() override {
        cout << "Added a line to page" << endl;
    }
    
    void erase() override {
        cout << "Removed a line from page" << endl;
    }
};

class Notebook : public PageObject {
    private:
    vector<PageObject> pages;
    
    public:
    void addPage(PageObject page) {
        pages.push_back(page);
    }
    
    void printTotalPages() {
        cout << "Total number of pages are: " << pages.size() << endl;
    }
    
    void add() override {
        cout << "Added a line to NoteBook" << endl;
    }
    
    void erase() override {
        cout << "Removed a line from NoteBook" << endl;
    }
};


//main function
int main() {
    Page a;// = new Page();
    Page b;// = new Page();
    Notebook nb;
    nb.addPage(a);
    nb.addPage(b);
    
    a.add();
    b.add();
    nb.printTotalPages();
    nb.add();
}

