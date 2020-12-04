#include <iostream>
using namespace std;

void replace_chars(char* str, char sc, char rc) {
    for (char* c = str; *c != '\0'; c++) {
        if (*c == sc) { 
            *c = rc; //character l = r
        }
    }
}
int main()
{
	char str[] = "hello lady";
    char* ptr = str;
    char sc = 'l';
    char rc = 'r';

    cout << str << endl; //hello lady

    replace_chars(ptr, sc, rc);
    cout << str; //herro rady
    return 0;
}
