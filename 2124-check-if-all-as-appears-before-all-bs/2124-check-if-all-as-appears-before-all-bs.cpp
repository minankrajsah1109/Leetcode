class Solution {
public:
    bool checkString(string s) {
        bool flag = true;
        int n = s.length();
        int i = 0;

        while(s[i] == 'a' && i < n){
            i++;
        }
        for(int j = i+1; j < n; j++){
            if(s[j] == 'a'){
               flag = false;
               break;
            }

        }
        return flag;
        
    }
};