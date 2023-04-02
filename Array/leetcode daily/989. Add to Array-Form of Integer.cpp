class Solution {
public:
    vector<int> addToArrayForm(vector<int>& num, int k) {
        int digits =  (log10(k) + 1);
        int len = num.size();
        int n = max(digits, len);

        vector<int> num1(n);
        for(int i=n-1; i>=0; i--){
            // if(n-i+1 > len) num1[i] = 0;
            // else            num1[i] = num[i];
            if(num.size()>0){
                num1[i] = num.back();
                num.pop_back();
            }
            else    num1[i] = 0;
        }

        vector<int> num2(n);
        for(int i=n-1; i>=0; i--){
            if(k==0){
                num2[i]=0;
                continue;
            }
            num2[i] = k % 10;
            k=k/10;
        }
        int i=n-1, carry=0;
        while(i>=0)
        {
            int sum = carry + num1[i] + num2[i];
            carry = sum/10;
            num1[i--] = sum % 10;
        }
        if(carry==0)    return num1;
        vector<int> res;
        res.push_back(carry);
        for(auto it: num1)   res.push_back(it);
        return res;
    }
};