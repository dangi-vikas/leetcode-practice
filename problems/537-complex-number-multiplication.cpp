class Solution {
public:
    string complexNumberMultiply(string num1, string num2) {
        int i = num1.find('+');
        int real1 = stoi(num1.substr(0, i));
        int imaginary1 = stoi(num1.substr(i+1, num1.size()-i-2));
    
        i = num2.find('+');
        int real2 = stoi(num2.substr(0, i));
        int imaginary2 = stoi(num2.substr(i+1, num2.size()-i-2));
    
        return to_string(real1*real2 - imaginary1*imaginary2) + "+" + to_string(real1*imaginary2 + real2*imaginary1) + "i";
    }
};

