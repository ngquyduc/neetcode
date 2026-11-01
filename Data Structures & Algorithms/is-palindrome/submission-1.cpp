#include <cctype>
class Solution {
public:
    bool isPalindrome(string s) {
        int i = 0, j = s.size() - 1;
        while (i <= j) {
            cout << s[i] << "\n";
            cout << s[j] << "\n";
            if (!isalnum(static_cast<unsigned char>(s[i]))) { i++; continue; }
            if (!isalnum(static_cast<unsigned char>(s[j])))  { j--; continue; }
            if (tolower(static_cast<unsigned char>(s[i])) == tolower(static_cast<unsigned char>(s[j]))) {
                i++; j--;
            } else {
                return false;
            }
        }
        return true;
    }
};
