class Solution {
public:
    string solve(string a, string b)
    {
        string res = "";
        int diff = a.length()-b.length();
        string temp = "";
        while(diff--)   temp += '0';
        b = temp+b;

        int i=a.length()-1;
        int c=0;
        while(i>=0)
        {
            int sum = (a[i]-'0')+(b[i]-'0');
            if(sum%2==0){
                res = to_string(c) + res;
                c=a[i]-'0';
            }
            else{
                if(c==1)    res = '0' + res;
                else        res = '1' + res;   
            }
            i--;
        }
        if(c==1)    res = '1' + res;
        // reverse(res.begin(),res.end())
        return res;
    }

    string addBinary(string a, string b) {
        if(a.length()>b.length())
            return solve(a,b);
        else
            return solve(b,a);
    }
};