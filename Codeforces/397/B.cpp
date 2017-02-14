#include <bits/stdc++.h>
using namespace std;

bool isAppear[26];

int main(void) {

    string s; cin >> s;
    int Max = 0;
    for (int i = 0; i < s.size(); ++i) {
        if (s[i] - 'a' == Max) {
            ++Max;
        } else if (s[i] - 'a' > Max) {
            puts("NO");
            return 0;
        }
    }
    puts("YES");

    return 0;
}