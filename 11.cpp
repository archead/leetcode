#include <algorithm>
class Solution {
public:
    int maxArea(vector<int>& height) {
        int max = 0, s = 0, e = height.size() - 1;
        while(e > s){
            max = std::max(max, std::min(height[s], height[e])*(e-s));
            if (height[s] > height[e]) e--;
            else if (height[e] > height[s]) s++;
            else{
                s++;
                e--;
            }
        }
        return max;
    }
};
