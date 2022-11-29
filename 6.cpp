class Solution {
public:
    string convert(string s, int numRows) {
        string zig[numRows];
        int row = 0;
        bool rev = false;
        if (numRows == 1) return s;
        for (int i = 0; i < s.size(); i++)
        {
            if(row == 0  || row == numRows - 1) rev = !rev;
            zig[row] += s[i];
            !rev ? row-- : row++;
        }
        string sum;
        for (int i = 0; i < numRows; i++)
            sum += zig[i];
        return sum;
    }
};
