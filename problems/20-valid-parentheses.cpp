class Solution {
public:
    bool isValid(string s) {
        
        //initialising an empty stack
        stack<int> st;
        
        //traversing the given string
        for(int i=0; i<s.size(); i++){

            //if the current character is an opening bracket then pushing it in the stack
            if(s[i]=='(' || s[i]=='[' || s[i]=='{') st.push(s[i]);
            
            //if it is a closing bracket
            else if(s[i]==')' || s[i]==']' || s[i]=='}'){

                /*if stack is empty, it means that the closing bracket 
                doesn't have matching opening  bracket*/ 
                if(st.empty()) return false;

                //getting the last pushed opening bracket
                char ch = st.top(); st.pop();
                
                /*finding out if the current closing bracket has matching opening bracket which
                  is immediate before it(stack's top)*/
                if((s[i]==')' && ch =='(') || (s[i]==']' && ch =='[') || 
                   (s[i]=='}' && ch=='{')) continue;
                
                return false;
            }
        }
        
        //if each bracket find its matching bracket then the stack must be empty
        if(st.empty()) return true;
        
        return false;
    }
};