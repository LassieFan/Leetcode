//暴力穷举法，反转比较是否相同，时间复杂度O(n^3)，超时
class Solution {
public:
    string longestPalindrome(string s) {
        string temp="";            //存放临时子串
        string res= "";           //存放最终子串
        for(int i=0;i<s.length();i++)
        {
            for(int j=i;j<s.length();j++)
            {
                temp=temp+s[j];
                string tmp=temp;
                std::reverse(tmp.begin(),tmp.end());    //反转子串判断是否相等
                if(temp==tmp)
                    res=res.length()>temp.length()?res:temp;
            }
            temp="";
        }
        return res;
    }
};