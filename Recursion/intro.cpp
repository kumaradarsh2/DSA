#include <iostream>

using namespace std;

void daysLeft(int days) {
    if (days == 0) {
        cout << "Happy Birthday" << endl;
        return;
    }
    cout << days << " days left for Birthday" << endl;
    daysLeft(days-1);
}

int main() {
    daysLeft(5); 

    return 0;
}
