class Solution {
public:
    bool isAlienSorted(vector<string>& words, string order) {
        unordered_map<char,int> mp;
        for(int i=0; i<order.length(); i++)     mp[order[i]]=i;
        // checkOrder for each word
        for(int idx=0; idx<words.size()-1; idx++)
        {
            string w1 = words[idx],   w2 = words[idx+1];
            int i=0,j=0;
            while(i<w1.length() && j<w2.length())
            {
                if(mp[w1[i]]>mp[w2[j]]) return false;
                else if(mp[w1[i]]<mp[w2[j]])    break;
                i++; j++;
                // if(mp[w1[i]]==mp[w2[j]])    continue;
                // else if(mp[w1[i]]<mp)
            }
            if(j==w2.length() && i!=w1.length())    return false;
        } 
        return true;
    }
};