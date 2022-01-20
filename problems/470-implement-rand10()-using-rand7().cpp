// The rand7() API is already defined for you.
// int rand7();
// @return a random integer in the range 1 to 7

class Solution {
public:
    int rand10() {
        float b =  (49 * (rand7() - 1) + 7 * (rand7() - 1) + (rand7() - 1)) /  343.0;
        return (int)(b * 10) + 1; 
    }
};