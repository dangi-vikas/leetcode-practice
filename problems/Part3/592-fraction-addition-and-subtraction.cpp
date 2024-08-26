class Solution {
    int fraction[11];

public:
    string fractionAddition(string expression) {
        expression += '/';
        if(expression[0] > 47) expression = '+' + expression;
        fillFraction(expression);

        int i = 0;

        while(++i != 11) if(fraction[i] != 0) break;
        if(i == 11) return "0/1";

        int den = i, num = fraction[i]; 
        while(++i != 11) {
          if(fraction[i] == 0) continue;
          num = num * i + den * fraction[i];
          den *= i;
        }

        int N = NOD(abs(num), den);

        return to_string(num / N) + "/" + to_string(den/N);  
    }
    
    void fillFraction(string &s) {
        for(int i = 1; i != 11; i++) fraction[i] = 0;

        for(int i = 0, lim = s.size() - 1; i != lim;) {
          int sign, num, den; 
          s[i++]   == '-' ? sign = 0 : sign = 1;
          s[i + 1]  ==  '0' ? num = 10, i += 2 : num = s[i++] - '0';
          s[++i + 1] == '0' ? den = 10, i += 2 : den = s[i++] - '0'; 
          sign ? fraction[den] += num : fraction[den] -= num;
        }
    }
        
        
    int NOD(int a, int b) {
	    while(a && b) {
		    if(a > b) a %= b;
		    else b %= a;
        }
        
        return a + b;
    }
};