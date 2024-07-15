vector<string> generateParenthesis(int n) {
        vector<string> ans;
        string str;

        generateParenthesisRecu(n, n, &str, &ans);
        
        return ans;
    }

private:
    void generateParenthesisRecu(int open, int close, string *str, vector<string> *ans) {
        
        /*base condition: if the both the count of opening and closing brackets reaches
          then we push the string in ans array*/
        if (open == 0 && close == 0) {
            ans->emplace_back(*str);
        }

        //if there is open bracket pushing it in string
        if (open > 0) {
            str->push_back('(');
            generateParenthesisRecu(open - 1, close, str, ans);
            str->pop_back();                                            //backtracking step
        }

        //if there are more close bracket pusing them in the string
        if (open < close) {
            str->push_back(')');
            generateParenthesisRecu(open, close - 1, str, ans);
            str->pop_back();                                            //backtracking step
        }
    }