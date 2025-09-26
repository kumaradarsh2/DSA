#include <iostream>
using namespace std;

void leak() {
    int* p = new int(99); // allocates memory initialized with 99
    cout << *p << endl;
    delete p;
    // forgot delete p;  // leak!
}

int main() {
    for (int i = 0; i < 1000000; i++) leak();
    cout << "done\n";

    return 0;
}