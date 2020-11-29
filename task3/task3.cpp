#include <iostream>
#define SENT 4
using namespace std;

void swap_sort(int* p1, int* p2, int* p3, bool sort) {
    int *a = p1;
    int *b = p2;
    int *c = p3;

    if (sort) {
        if (*a >= *b && *a >= *c) {
            if (*b >= *c) {
                //c b a 
                a = p3;
                b = p2;
                c = p1;
            }
            else if (*c >= *b) {
                // b c a
                a = p2;
                b = p3;
                c = p1;
            }
        }
        else if (*b >= *a && *b > *c) {
            if (*a > *c) {
                // c a b
                a = p3;
                b = p1;
                c = p2;
            }
            else if (*c >= *a) {
                // a c b
                a = p1;
                b = p3;
                c = p2;
            }
        }
        else if (*c >= *a && *c >= *b) {
            if (*b >= *a) {
                // a b c
                a = p1;
                b = p2;
                c = p3;
            }
            else if (*a >= *b) {
                // b a c
                a = p2;
                b = p1;
                c = p3;
            }
        }
    }
    else {
        if (*a >= *b && *a >= *c) {
            if (*b >= *c) {
                // a b c
                a = p1;
                b = p2;
                c = p3;
            }
            else if (*c >= *b) {
                // a c b
                a = p1;
                b = p3;
                c = p2;
            }
        }
        else if (*b >= *a && *b >= *c) {
            if (*a >= *c) {
                // b a c
                a = p2;
                b = p1;
                c = p3;
            }
            else if (*c >= *a) {
                // b c a
                a = p2;
                b = p3;
                c = p1;
            }
        }
        else if (*c >= *a && *c >= *b) {
            if (*b >= *a) {
                // c b a
                a = p3;
                b = p2;
                c = p1;
            }
            else if (*a >= *b) {
                //c a b
                a = p3;
                b = p1;
                c = p2;
            }
        }
    }
    cout << *a << " " << *b << " " << *c << endl;
}

void error() {
    cout << "Error, inserting 0." << endl; 
    cin.clear();
    cin.ignore(1, '\n');
}

int main()
{
    int a, b , c;
    while (true) {
        
        cout << "Give a: ";
        cin >> a;
        if (cin.fail()) { 
            error();
        }

        cout << "Give b: ";
        cin >> b;
        if (cin.fail()) {
            error();
        }

        cout << "Give c: ";
        cin >> c;
        if (cin.fail()) {
            error();
        }

        int* p1 = &a;
        int* p2 = &b;
        int* p3 = &c;

        int order;
        cout << "Sort ascending/descending (1/0), 2 to exit: ";
        cin >> order;
        if (cin.fail()) {
            error();
        }

        if (order == 0) {
            swap_sort(p1, p2, p3, false);
        }
        else if (order == 1) {
            swap_sort(p1, p2, p3, true);
        }
        else if (order == 2) {
            return 0;
        }
        else {
            cout << "Wrong input." << endl;
        }
    }
    return 0;
}
