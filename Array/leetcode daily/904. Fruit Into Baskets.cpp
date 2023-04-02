class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        int n = fruits.size();
        //          (fruitType, count)
        unordered_map<int,int> mp;
        int i=0,j=0,res=0;
        while(j<n)
        {
            mp[fruits[j]]++;
            while(mp.size()>2)
            {
                if(mp[fruits[i]]==1)   mp.erase(fruits[i]);
                else                   mp[fruits[i]]--;
                i++;
            }
            // update result
            res = max(res,(j-i+1));
            j++;
        }
        return res;
    }
};


/******************************* BRUTE FORCE *****************************/
// class Solution {
// public:
//     int totalFruit(vector<int>& fruits) {
//         int n = fruits.size();
//         int res = INT_MIN;
//         for(int i=0; i<n; i++)
//         {
//             pair<int,int> b1 = {-1,0};
//             pair<int,int> b2 = {-1,0};
//             for(int j=i; j<n; j++)
//             {
//                 // if(b1.first!=-1 && b2.first!=-1){
//                 if(b1.first==fruits[j])     b1.second++;
//                 else if(b2.first==fruits[j])    b2.second++;
//                 // }

//                 else if(b1.first==-1){
//                     b1.first=fruits[j];
//                     b1.second++;
//                 }
//                 else if(b2.first==-1){
//                     b2.first=fruits[j];
//                     b2.second++;
//                 }
//                 else
//                     break;
//                 // cout<<"{ {"<<b1.first<<","<<b1.second<<"}"<<" {"<<b2.first<<","<<b2.second<<"} }"<<",";
//             }
//             res = max(res,(b1.second+b2.second));
//             // cout<<"::: "<<res<<endl;
//         }
//         return res;A
//     }
// };