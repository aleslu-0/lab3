#include <iostream>
#define SENT 4
using namespace std;

void swap_sort_ptr_addr(int** p1, int** p2, int** p3, bool sort) {
    int** ap = p1, ** bp = p2, ** cp = p3;
    int a = **p1, b = **p2, c = **p3; //a, b, c will remain unchanged

    if (sort) {
        if (a >= b && a >= c) {
            if (b >= c) {
                //c b a 
                **ap = c;
                **bp = b;
                **cp = a;
            }
            else if (c >= b) {
                // b c a
                **ap = b;
                **bp = c;
                **cp = a;
            }
        }
        else if (b >= a && b > c) {
            if (a > c) {
                // c a b
                **ap = c;
                **bp = a;
                **cp = b;
            }
            else if (c >= a) {
                // a c b
                **ap = a;
                **bp = c;
                **cp = b;
            }
        }
        else if (c >= a && c >= b) {
            if (b >= a) {
                // a b c
                **ap = a;
                **bp = b;
                **cp = c;
            }
            else if (a >= b) {
                // b a c
                **ap = b;
                **bp = a;
                **cp = c;
            }
        }
    }
    else {
        if (a >= b && a >= c) {
            if (b >= c) {
                // a b c
                **ap = a;
                **bp = b;
                **cp = c;
            }
            else if (c >= b) {
                // a c b
                **ap = a;
                **bp = c;
                **cp = b;
            }
        }
        else if (b >= a && b >= c) {
            if (a >= c) {
                // b a c
                **ap = b;
                **bp = a;
                **cp = c;
            }
            else if (c >= a) {
                // b c a
                **ap = b;
                **bp = c;
                **cp = a;
            }
        }
        else if (c >= a && c >= b) {
            if (b >= a) {
                // c b a
                **ap = c;
                **bp = b;
                **cp = a;
            }
            else if (a >= b) {
                //c a b
                **ap = c;
                **bp = a;
                **cp = b;
            }
        }
    }
}

void error() {
    cout << "Error, inserting 0." << endl;
    cin.clear();
    cin.ignore(1, '\n');
}

int main()
{
    //Works with this code

    int a = 7, b = 6, c = 1;
    int* p1 = &a, * p2 = &b, * p3 = &c;
    swap_sort_ptr_addr(&p1, &p2, &p3, true);
    cout << *p1 << " " << *p2 << " " << *p3 << endl;    // Points "1 6 7"

    
    while (true) {
        int a, b, c;

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
            swap_sort_ptr_addr(&p1, &p2, &p3, false);
        }
        else if (order == 1) {
            swap_sort_ptr_addr(&p1, &p2, &p3, true);
        }
        else if (order == 2) {
            return 0;
        }
        else {
            cout << "Wrong input." << endl;
        }
        cout << *p1 << " " << *p2 << " " << *p3 << endl;
    }
    return 0;
}
