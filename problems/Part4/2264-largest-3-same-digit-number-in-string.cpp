class Solution {
public:
    std::string largestGoodInteger(string num) {
        char com;
        int left = 0, right = 0;

        for(int i=0; i<num.length()-2; i++) {
            if(num[i] == num[i+1] && num[i+1] == num[i+2]) {
                if(com <= num[i]) {
                    left = i;
                    right = i + 2;
                    com = num[i];
                }
            }
        }

        return com ? num.substr(left, 3) : "";
    }
};
