class Solution {
public:
   bool isPalindrome(const string& s, int left, int right) {
    while (left < right) {
        if (s[left] != s[right]) return false;
        left++;
        right--;
    }
    return true;
}
    string longestPalindrome(string s) {
        if(s.empty()) return "";
       int maxlen=0,startind=0;
       for(int i=0;i<s.size();i++){
        for(int j=i;j<s.size();j++){
            if((j-i+1)>maxlen && isPalindrome(s,i,j)){
                maxlen=j-i+1;
                startind=i;
            }
        }
       }
        return s.substr(startind,maxlen);
    }
};