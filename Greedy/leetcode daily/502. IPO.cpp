class Solution {
public:
    int findMaximizedCapital(int k, int w, vector<int>& profit, vector<int>& capital) {
       int n = profit.size();
       vector<pair<int,int>> project(n);
       for(int i=0; i<n; i++){
           project[i] = {capital[i], profit[i]};
       }
       // sort according to capital required
       sort(project.begin(), project.end());
       priority_queue<int> maximizeCap;
       int i=0;
       while(k--)
       {
           while(i<n && project[i].first <= w){
               maximizeCap.push(project[i].second);  
               i++;
           }
           // if no sufficient capital available to start further projects i.e, no project available in 'maximizeCap' to select their profit
           if(maximizeCap.empty())   break;
           w += maximizeCap.top();
           maximizeCap.pop();
       }
       return w;
    }







/***************** MY WRONG APPROACH initially **************/

// class Solution {
// public:
//     static bool compareCapital(const pair<pair<int,int>,int> &p1, const pair<pair<int,int>,int> &p2){
//         return (p1.first.second < p2.first.second);
//     }
//     static bool compareDiff(pair<pair<int,int>,int> &p1, pair<pair<int,int>,int> &p2){
//         return (p1.second > p2.second);
//     }

//     int findMaximizedCapital(int k, int w, vector<int>& profit, vector<int>& capital) {
//         int n = profit.size();
//         // { {profit,capital}, diff }
//         vector< pair<pair<int,int>,int> > v(n);
//         for(int i=0; i<n; i++){
//             int diff = profit[i]-capital[i];
//             v[i].first.first = profit[i];
//             v[i].first.second = capital[i];
//             v[i].second = diff;
//         }

//         sort(v.begin(), v.end(), compareCapital);
//         int start=0;
//         for(int i=0; i<n; i++){
//             if(v[i].first.second != v[start].first.second){
//                 sort(v.begin()+start, v.begin()+i, compareDiff);
//                 start = i;
//             }
//         }
//         sort(v.begin()+start, v.end(), compareDiff);

//         // for(auto it:v)  cout<<it.first.first<<","<<it.first.second<<endl;

//         int res=0;
//         for(int i=0; i<n; i++)
//         {
//             int currProfit = v[i].first.first, capReq = v[i].first.second;
//             if(capReq <= w){
//                 w = w - capReq;
//                 res += currProfit;
//                 w = w + currProfit;
//                 k--;
//             }
//             if(k==0)    break;
//         }
//         return res;

//     }
// };

};