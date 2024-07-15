class Solution {
public:
    void solve(string equation, int& coeff, int& num) {
        int flag=0, sign=1, i=0 ;
        
        while(equation.length()) {
            if(equation[0] == '=') {
                flag = 1 ;
                sign = 1 ;
                equation = equation.substr(1) ;
            }

            if(equation[0] == '-') {
                sign = 0 ;
                equation = equation.substr(1) ;
             }
            
            if(equation[0] == '+') {
                sign = 1 ;
                equation = equation.substr(1) ; 
             }
            
            int temp = -1 ;
            for(int j=0; j<equation.length(); j++) {
                if(equation[j] == '+' || equation[j] == '-' || equation[j] == '='){
                    temp = j ;
                    break ;
                }
            }
            
            if(temp == -1) 
                temp = equation.length() ;
            
            string s = equation.substr(0,temp) ;

            if(s[s.length()-1] == 'x') {
                s = s.substr(0, s.length()-1) ;
                
                if(s.length() == 0) s += '1' ;
                if(flag ^ sign) coeff += stoi(s) ;
                else coeff -= stoi(s) ; 
            } 
            
            else {
                if(flag ^ sign) num += stoi(s) ;
                else num -= stoi(s) ;   
            }
            
            equation = equation.substr(temp) ;
        }
    }
    
    string solveEquation(string equation) {
        int num = 0 , coeff = 0 ;
        
        solve(equation,coeff,num) ;
        
        if (num == 0 && coeff == 0) return "Infinite solutions";
        if (coeff == 0) return "No solution";
        
        return "x=" + to_string(-1 * num/coeff);
    }
};