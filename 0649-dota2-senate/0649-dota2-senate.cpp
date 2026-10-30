class Solution {
public:
    string predictPartyVictory(string senate) {
        int n = senate.length();
        queue<int> q;
        queue<int> r;
        queue<int> d;
        for(int i = 0; i < n; i++){
            q.push(i);
            if(senate[i] == 'R') r.push(i);
            else d.push(i);
        }
        while(q.size() > 1){
            if(senate[q.front()] == 'X') q.pop();
            else if(senate[q.front()] == 'R'){
                // check for victory
                if(d.size() == 0) return "Radiant";
                else{  // takes right of next D
                    senate[d.front()] = 'X';
                    d.pop();
                    q.push(q.front());
                    q.pop();
                    r.push(r.front());
                    r.pop();
                }
            }
            else{  // senate[q.front() == 'D']
                // check for victory
                if(r.size() == 0) return "Dire";
                else{ // takes right of next R
                    senate[r.front()] = 'X';
                    r.pop();
                    q.push(q.front());
                    q.pop();
                    d.push(d.front());
                    d.pop();
                }
            }
        }
        if(senate[q.front()] == 'R') return "Radiant";
        else return "Dire";
    }
};