#include <vector>
class Solution {
public:
    int compareVersion(string version1, string version2) {

        version1 += '.';
        version2 += '.';
        vector<int> v1, v2;
        int i = 0;
        string temp;
        
        for (char c : version1){
            if (c == '.'){
                v1.push_back(stoi(temp));
                i++;
                temp.clear();
                continue;
            }
            temp += c;
        }
        
        for (char c : version2){
            if (c == '.'){
                v2.push_back(stoi(temp));
                i++;
                temp.clear();
                continue;
            }
            temp += c;
        }
        
        int v1s = v1.size();
        int v2s = v2.size();
        if (v1s > v2s)
            v2.resize(v1s + (v1s - v2s));
        if (v1s < v2s)
            v1.resize(v1s + (v2s - v1s));

        int j=0, k=0;
        while (j < v1.size() && k < v2.size()){
            if(v1[j] < v2[k]) return -1;
            else if(v1[j] > v2[k]) return 1;
            else j++; k++;
        }
        
        return 0;
    }
};
