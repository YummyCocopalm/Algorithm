#include <string>
#include <vector>
#include <stack>

using namespace std;

bool isRight(string &p) {
    int count = 0;
    for (int i = 0; i < p.size(); ++i) {
        if (p[i] == '(') {
            ++count;
        }
        else {
            if (count == 0) {
                return false;
            }
            else {
                --count;
            }
        }
    }
    return true;
}

int splitString(string &p) {
    int count = 0;
    for (int i = 0; i < p.size(); ++i) {
        if (p[i] == '(') ++count;
        else --count;
        if (count == 0) return i;
    }
    return -1;
}

void inverse(string &p) {
    for (int i = 0; i < p.size(); ++i) {
        if (p[i] == '(') p[i] = ')';
        else p[i] = '(';
    }
}

string solution(string p) 
{
    if (isRight(p)) {
        return p;
    }
    else {
        int second = splitString(p);
        string u = p.substr(0, second+1);
        string v = p.substr(second+1, p.size()-second-1);
        v = solution(v);
        if (isRight(u)) {
            return u+v;
        }
        else {
            inverse(u);
            return '('+v+')'+u.substr(1, u.size()-2);
        }
    }
}