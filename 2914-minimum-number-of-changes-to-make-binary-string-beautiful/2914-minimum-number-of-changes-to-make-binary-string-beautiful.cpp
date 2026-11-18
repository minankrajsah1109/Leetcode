class Solution {
public:
    int minChanges(string s) {
        int n = s.length();

        char Ch = s[0]; //current character
        int count = 0;

        int changes = 0;

        for(int i = 0; i < n; i++){
            if(s[i] == Ch){
                count++;
                continue;
            }

            // current character s[i] is not equal to ch
            if(count % 2 == 0){ // previous substring is of even length
                count = 1;
            }
            else{
                // s[i] ko change karna padega to make even substring length
                changes += 1;
                count = 0;
            }
            Ch = s[i]; 
        }
        return changes;
    }
};