class Solution {
public:
    string dayOfTheWeek(int day, int month, int year) {
        vector<int> days = {31,28,31,30,31,30,31,31,30,31,30,31};
        vector<string> date = {"Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday", "Sunday"};
        int d = day;
        
        for(int i=0; i<month-1; i++) d += days[i];
        
        if(((year%4 == 0 && year % 100 != 0) || year%400 == 0) && month > 2) d++;
        
        for(int i=1971; i<year; i++) {
            if((i%4==0 && i%100 != 0) || i%400 == 0) d += 366;
            else d += 365;
        }
        
        return date[(d+3) % 7];
    }
};