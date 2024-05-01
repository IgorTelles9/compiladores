#include <iostream>
#include <string>
#include <stdio.h>

using namespace std;

enum token { ID = 256, NUM};
string lexema;

int next_token() {
    int ch = getchar();

    while (ch == " " || ch == "\n" || ch == "\t" || ch == "\r"){
        ch = getchar();
    }

}

int main() {
    int tk = next_token();
    while(tk != EOF ){
        cout << tk << ": " < lexema << endl;
        tk = next_token();
    }
    return 0;
}
