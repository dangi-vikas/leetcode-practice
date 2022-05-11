class Solution {
public:
string toGoatLatin(string sentence) {
    stringstream s(sentence);
    string word;
    string str="";
    vector<string> v;
    while(s>>word)
    {
        v.push_back(word);
    }
    for(int i=0;i<v.size();i++)
    {
        char x=v[i][0];
        if(x == 'a' || x == 'e' || x == 'i' ||x == 'o' || x == 'u' || x == 'A' || x == 'E' || x == 'I' || x == 'O' || x ==              'U')
        {
            v[i] += "ma";
        }
        else{
        v[i].erase(v[i].begin());
            v[i] += x;
            v[i] += "ma";
        }
        
        int p=i+1;
        while(p>0){
            v[i] += 'a';
            p--;
        }
        str+= v[i] + " ";
        
    }
    str.pop_back();
    return str;
    }
};
