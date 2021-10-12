class Solution {
public:
    string multiply(string num1, string num2) {
        
        //if any one of the numbers is zero
        if(num1=="0" || num2=="0") return "0";

        //size of resultant string will be n+1 at max
        int n = num1.size() + num2.size() - 1;
        string ans(n+1, '0');
        
        //index1 and num2 are position pointer for num1 and num2
        //carry1 for multiplication and carry2 for addition 
        int index1=0, index2=0, carry1=0, carry2=0;

        //iterating in num1
        for(int i=num1.size()-1; i>=0; i--){
            
            //at the starting of new i, position of index2 should be reset
            //carry2 should be vanished
            index2 = 0;
            carry2 = 0;

            //iterating in num2 and multiplying with number in num1 at position index1
            for (int j=num2.size()-1; j>=0; j--){
                
                //individual multiplication and getting carried number 
                int val1 = (num1[i]-'0') * (num2[j]-'0') + carry1;
                carry1 = val1 / 10;
                val1 = val1 % 10;
                
                //adding it to the previous products done with numbers in num1
                int val2 = (ans[n-(index1+index2)]-'0') + val1 + carry2;
                carry2 = val2 / 10;
                val2 = val2 % 10;
                
                char c = '0' + val2;
                
                //placing the value in ans string
                ans[n - (index1+index2)] = c;
                
                index2++;
            }

            if(n>=(index1+index2)){
                int val1 = carry1;
                carry1 = val1 / 10;
                val1 = val1 % 10;

                int val2 = (ans[n-(index1+index2)]-'0') + val1 + carry2;
                carry2 = val2 / 10;
                val2 = val2 % 10;

                char c = '0' + val2;

                ans[n - (index1+index2)] = c;
            }

            index1++;
        }

        //erasing the preceeding zero
        if (ans[0] == '0') ans.erase(0, 1);

        return ans;
    }
};