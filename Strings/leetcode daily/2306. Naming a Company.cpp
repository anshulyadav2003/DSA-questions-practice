class Solution {
public:
    long long distinctNames(vector<string>& ideas) {
        // int n = ideas.size();
        vector<unordered_set<string>> v(26);
        for(auto it: ideas){
            v[it[0]-'a'].insert(it.substr(1));
        }
        long long unique_names = 0;
        for(int i=0; i<25; i++)
        {
            for(int j=i+1; j<26; j++)
            {
                unordered_set<string> st;
                
                /*************** this giving TLE *************/
                // auto st1 = v[i];
                // auto st2 = v[j];
                // for(auto it: st1)   st.insert(it);
                // for(auto it: st2)   st.insert(it);
                // unique_names += (st1.size()-st.size())*(st2.size()-st.size()); 

                st.insert(v[i].begin(),v[i].end());
                st.insert(v[j].begin(),v[j].end());
                unique_names += (v[i].size()-st.size())*(v[j].size()-st.size()); 
            }
        }
        return 2*unique_names;
    }
};



/************** BRUTE FORCE **************************/
// class Solution {
// public:
//     long long distinctNames(vector<string>& ideas) {
//         long long int cnt=0;
//         int n = ideas.size();
//         unordered_map<string,bool> mp;
//         for(auto it: ideas) mp[it]=true;

//         for(int i=0; i<n; i++)
//         {
//             for(int j=0; j<n; j++)
//             {
//                 if(i==j)    continue;
//                 string a = ideas[i];
//                 string b = ideas[j];
//                 swap(a[0],b[0]);
//                 if(mp[a]==false && mp[b]==false)  cnt++;
//             }
//         }
//         return cnt;
//     }
// };