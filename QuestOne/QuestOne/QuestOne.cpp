#include <iostream>
#include <string>

using namespace std;

bool Comparis(char one, char two) {
    bool cond = false;
    for (int l = 65; l < 90; ++l) {
        if (one == char(l)) one = char(one + 32);
        if (two == char(l)) two = char(two + 32);
    }
    // Цифры 65-90 - номера заглавных латинских символов в ASCII
    if (one == two) cond = true;
    return cond;
}

string Convertis(string theString) {
    string convString;
    int length = theString.length();
    char header, pointer;
    bool comp = false;
    for (int i = 0; i < length; ++i) {
        header = theString[i];
        for (int j = 0; !comp && (j < length); ++j) {
            if (i != j) {
                pointer = theString[j];
                comp = Comparis(header, pointer);
            }
        }
        if(comp) convString.push_back(')');
        else convString.push_back('(');
        comp = false;
    }
    return convString;
}

int main() {
    string inString, outString;
    cout << "Put your string: ";
    getline(cin, inString);
    outString = Convertis(inString);
    cout << "Converted string: " << outString;
}
