class Solution {
public:
    string convert(string s, int numRows) {
        if(numRows==1)
            return s;
        
        int len = s.length();
        string res="";
        int k=2*(numRows-1); 
        for(int i=0;i<numRows;i++)
        {   
            for(int j=0;j+i<len;j+=k)
            {
                res=res+s[j+i];
                   if(i!=0&&i!=numRows-1&&j+k-i<len)
                       res=res+s[j+k-i];
            }
        }
        return res;
    }
};