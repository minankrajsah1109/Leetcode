class Solution {
public:
    bool checkString(string s) {
        string check = s;

        sort(s.begin(), s.end());

        return check == s;
    }
};