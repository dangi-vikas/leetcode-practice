class Solution {
public:
    string numberToWords(int num) {
        vector<string> ones = {"", " One", " Two", " Three", " Four", " Five", " Six", " Seven", " Eight", " Nine"};
        vector<string> teens = {" Ten", " Eleven", " Twelve", " Thirteen", " Fourteen", " Fifteen", " Sixteen", " Seventeen", " Eighteen", " Nineteen" };
        vector<string> tens = {"",  "",  " Twen", " Thir", " For", " Fif", " Six", " Seven", " Eigh", " Nine" };
        vector<string> greats = {"", " Thousand", " Million", " Billion"};
        
        string ans;
        int k = 0;
        
        while(num) {
            string sub;
            int s4 = num%1000, s3 = s4/100, s2 = s4%100;
            
            if(s4) ans.insert(0, greats[k]);
            if(s3) sub += ones[s3] + " Hundred";
            if(s2) sub += s2 < 20 ? (s2 < 10 ? ones[s2%10] : teens[s2%10]) : tens[s2/10%10] + "ty" + ones[s2%10];
            
            ans.insert(0, sub);
            num /= 1000;
            k++;
        }
        
        return ans.size() ? string(ans.begin()+1, ans.end()) : "Zero"; 
    }
};