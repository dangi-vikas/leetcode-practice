class Solution {
public:
    bool isPalindrome(int x) {
        //starting checks for a number to be a palindrome
        if(x<0 || (x%10 == 0 && x)) {
            return false;
        }

        //finding the reverse of a number 
        int revertedNumber = 0;
        while(x > revertedNumber) {
            revertedNumber = revertedNumber * 10 + x % 10;
            x /= 10;
        }
        
        //checking for equality condition(also includes condition for preceeding zeroes)
        return x == revertedNumber || x == revertedNumber/10;
    }
};