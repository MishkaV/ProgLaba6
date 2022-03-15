#include <iostream>
#include <string>
#include <set>
#include <stdio.h>

using namespace std;

bool FSM(char ch, int &S) {
    switch (S) {
        case 0:
            if (ch == 'f') {
                S = 1;
                return false;
            }
            S = -1;
            return true;
        case 1:
            if (ch == 'o') {
                S = 2;
                return false;
            }
            S = -1;
            return true;
        case 2:
            if (ch == 'r') {
                S = 3;
                return false;
            }
            S = -1;
            return true;
        case 3:
            if ((ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z')) {
                S = 4;
                return false;
            }
            S = -1;
            return true;
        case 4:
            switch (ch) {
                case '0' ... '9':
                    S = 4;
                    return false;
                case 'a' ... 'z':
                    S = 4;
                    return false;
                case 'A' ... 'Z':
                    S = 4;
                    return false;
                case '=':
                    S = 5;
                    return false;
                default:
                    S = -1;
                    return true;
            }

        case 5:
            if (ch >= '0' && ch <= '9') {
                S = 6;
                return false;
            }
            S = -1;
            return true;
        case 6:
            switch (ch) {
                case '0' ... '9' :
                    S = 6;
                    return false;
                case 'd':
                    S = 7;
                    return false;
                case 't':
                    S = 11;
                    return false;
                default:
                    S = -1;
                    return true;
            }

        case 7:
            if (ch == 'o') {
                S = 8;
                return false;
            }
            S = -1;
            return true;
        case 8:
            if (ch == 'w') {
                S = 9;
                return false;
            }
            S = -1;
            return true;
        case 9:
            if (ch == 'n') {
                S = 10;
                return false;
            }
            S = -1;
            return true;
        case 10:
            if (ch == 't') {
                S = 11;
                return false;
            }
            S = -1;
            return true;
        case 11:
            if (ch == 'o') {
                S = 12;
                return false;
            }
            S = -1;
            return true;
        case 12:
            if (ch >= '0' && ch <= '9') {
                S = 13;
                return false;
            }
            S = -1;
            return true;
        case 13:
            switch (ch) {
                case '0' ... '9':
                    S = 13;
                    return false;
                case ' ':
                    S = 14;
                    return false;
                default:
                    S = -1;
                    return true;
            }
        case 14:
            if ((ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z')) {
                S = 15;
                return false;
            }
            S = -1;
            return true;
        case 15:
            switch (ch) {
                case '0' ... '9' :
                    S = 15;
                    return false;
                case 'a' ... 'z':
                    S = 15;
                    return false;
                case 'A' ... 'Z':
                    S = 15;
                    return false;
                case '=':
                    S = 16;
                    return false;
                default:
                    S = -1;
                    return true;
            }
        case 16:
            if (ch >= '0' && ch <= '9') {
                S = 17;
                return false;
            }
            S = -1;
            return true;
        case 17:
            switch (ch) {
                case '0' ... '9':
                    S = 17;
                    return false;
                case '+':
                    S = 18;
                    return false;
                case '-':
                    S = 18;
                    return false;
                default:
                    S = -1;
                    return true;
            }
        case 18:
            if (ch >= '0' && ch <= '9') {
                S = 19;
                return false;
            }
            S = -1;
            return true;
        case 19:
            switch (ch) {
                case '0' ... '9':
                    S = 19;
                    return false;
                case 'n':
                    S = 20;
                    return false;
                default:
                    S = -1;
                    return true;
            }

        case 20:
            if (ch == 'e') {
                S = 21;
                return false;
            }
            S = -1;
            return true;
        case 21:
            if (ch == 'x') {
                S = 22;
                return false;
            }
            S = -1;
            return true;
        case 22:
            if (ch == 't') {
                S = 23;
                return false;
            }
            S = -1;
            return true;
        case 23:
            break;
    }
}

int main() {
    int S = 0;
    string str;
    set<int> Final = {23};
    while (getline(cin, str), str != "") {
        for (auto i: str)
            if (FSM(i, S)) break;
    }
    cout << S << endl;
    if (Final.count(S))
        cout << "Yes";
    else
        cout << "No";
    return 0;
}

