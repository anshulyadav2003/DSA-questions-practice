class Solution {
public:
    bool check(string str, int n, vector<int> mp)
    {
        for(auto it: str)   mp[it-'a']--;
        for(auto it: mp){
            if(it!=0)   return false;
        }
        return true;
    }

    bool checkInclusion(string s1, string s2) {
        int n1 = s1.length(),   n2=s2.length();
        if(n1>n2)   return false;

        int val1 = 0;  // hash value of s1 string
        vector<int> mp(26,0);
        for(int i=0; i<n1; i++){
            val1 += (s1[i]-'a');
            mp[s1[i]-'a']++;
        }
        for(int i=0; i<n2-n1+1; i++)
        {
            string temp = s2.substr(i,n1);
            // cout<<temp<<" ";
            int val2 = 0;
            for(int j=0; j<n1; j++){
                val2 += (temp[j]-'a');
            }
            // cout<<val2<<endl;
            if(val1==val2 && check(temp, n1, mp))  return true;
        }
        return false;
    }
};
