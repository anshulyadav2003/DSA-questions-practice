class Solution {
public:
    string gcdOfStrings(string str1, string str2) {
        // whether gcd String exist or not
        if(str1+str2 != str2+str1)  return "";
        // now only case left is that gcd string exists
        // : therefore calculate the gcd_LENGTH
        int gcdLength = gcd(str1.length(), str2.length());
        return str1.substr(0,gcdLength); 
    }
};



// class Solution {
// public:
//     int computeGCD(int a, int b)
//     {
//         if (a == 0) return b;
//         if (b == 0) return a;
//         if (a == b) return a;
//         // a is greater
//         if (a > b)
//             return gcd(a-b, b);
//         return gcd(a, b-a);
//     }
//     string gcdOfStrings(string str1, string str2) {
//         int n1=str1.length(), n2=str2.length();
//         string gcd="";
//         int x = computeGCD(n1,n2);
//         for(int k=0; k<x; k++)
//         {
//             if(str1[k]!=str2[k]) return "";
//             gcd.push_back(str1[k]);
//         }

//         // check gcd by divding for both strings
//         if(gcd.length()==0) return "";
//         if(n1%gcd.length()!=0 || n2%gcd.length()!=0)   return "";
        
//         int i=0;
//         while(i<n1){
//             for(int k=0; k<gcd.length(); k++){
//                 if(str1[i]!=gcd[k]) return "";
//                 else    i++;
//             }
//         }
        
//         int j=0;
//         while(j<n2){
//             for(int k=0; k<gcd.length(); k++){
//                 if(str2[j]!=gcd[k]) return "";
//                 else    j++;
//             }
//         }
//         return gcd;
//     }
// };