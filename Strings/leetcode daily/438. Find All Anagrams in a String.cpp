class Solution {
public:
    vector<int> findAnagrams(string str, string p) {
        vector<int> v(26,0);
        vector<int> res;
        int n = str.length(),   m=p.length();
        if(m>n) return res;

        int cnt=0;
        for(auto it:p){
            if(v[it-'a']==0)    cnt++;
            v[it-'a']++;
        }
        
        for(int i=0; i<m; i++){
            v[str[i]-'a']--;
            if(v[str[i]-'a']==0)    cnt--;
        }
        if(cnt==0)  res.push_back(0); 

        int l=0,h=m-1;
        while(h<n)
        {
            if(v[str[l]-'a']==0)    cnt++;
            v[str[l]-'a']++;
            l++;    h++;
            if(h>=n)    break;
            
            v[str[h]-'a']--;
            if(v[str[h]-'a']==0)   cnt--;
            if(cnt==0)  res.push_back(l);
        }
        return res;
    }
};