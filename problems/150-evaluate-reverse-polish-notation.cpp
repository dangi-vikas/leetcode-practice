class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> st;
        
        for(auto t : tokens){

            //if the character is a operator
            if(t == "+" || t == "-" || t == "*" || t == "/"){
                int op1 = st.top(); st.pop();
                int op2 = st.top(); st.pop();
                
                //performing the operation
                if(t=="+") st.push(op1 + op2);
                if(t=="-") st.push(op2 - op1);
                if(t=="*") st.push(op1 * op2);
                if(t=="/") st.push(op2 / op1);
            }
            
            else st.push(stoi(t));
        }
        
        return st.top();
    }
}; 
