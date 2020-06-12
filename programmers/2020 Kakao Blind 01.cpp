#include <string>
#include <vector>

using namespace std;

void updateLen(int &used, int &size) {
    if (used < 2) {}
    else if (used < 10) {
        size += 1;
    }
    else if (used < 100) {
        size += 2;
    }
    else if (used < 1000) {
        size += 3;
    }
    else {
        size += 4;
    }
}

int solution(string s) {
    int answer = s.size();
    for (int i = 1; i <= s.size()/2; ++i) {
        int minSize = 0;
        int used = 1;
        string cmp = s.substr(0, i);
        for (int j = i; j+i <= s.size(); j += i) {
            if (cmp == s.substr(j, i)) {
                ++used;
            }
            else {
                minSize += i;
                updateLen(used, minSize);
                cmp = s.substr(j, i);
                used = 1;
            }
        }
        minSize += i;
        updateLen(used, minSize);
        minSize += (s.size() % i);
        answer = answer < minSize ? answer : minSize;
    }
    return answer;
}