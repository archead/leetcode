class Solution {
public:
    int myAtoi(string s) {

        int start = 0;
        int mult = 1;
        
        for (int i = 0; i < s.size(); i++){
            
            if (s[i] == ' ') continue;
            
            else if(s[i] == '+' || s[i] == '-'){ 
                if (s[i] == '-') mult = -1;
                start = i+1;
                break;
            }
            
            else if(s[i] >= '0' && s[i] <= '9'){
                start = i;
                break;
            }
            
            else break;
        }
        
        vector<int> intar;
        for (int i = start; i < s.size(); i++){
            if (s[i] >= '0' && s[i] <= '9') intar.push_back(s[i] - '0');
            else break;
        }
 
        long long int f = 0;
        reverse(intar.begin(), intar.end());
        for (int i = 0; i < intar.size(); i++){
            
            if (mult * intar[i] * pow(10, i) > 2147483647) return 2147483647;
            
            else if (mult * intar[i] * pow(10, i) < -2147483648) return -2147483648;
            
            f += (intar[i] * pow(10, i));
        }
        
        if (mult * f > 2147483647) return 2147483647;
        
        else if (mult * f < -2147483648) return -2147483648;
        
        return mult * f;
    }
};
