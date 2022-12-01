class Solution {
public:

    string shiftingLetters(string s, vector<int>& shifts) {
        int sum = 0;
        for (auto n : shifts)
            sum += n % 26;
        for (int i = 0; i < s.length(); i++){
            s[i] = 'a' + ((s[i] - 'a') + sum)%26;
            sum -= shifts[i] % 26;
        }
        return s;
    }
};
