#include <iostream>

using namespace std;

int main() {
    char crr[5] = {'a', 'b', 'c', 'c', 'd'};

    char* ctr = crr;

    cout << *ctr << endl;


    // while (*ctr != '\0') {
    //     void* ptr = (void*) ctr;
    //     cout << *((char*) ptr) << endl;
    //     ctr++;
    // }
  
    return 0;
}