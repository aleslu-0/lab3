#include <iostream>
using namespace std;

int str_length(char* arr) {
    int size = 0;
    for (char* c = arr; *c != '\0'; c++) {
        size += 1;
    }
    return size;
}
int main()
{
    char arr[] = "computer";
    char* ptr = arr;
   
    cout << str_length(ptr);
}
