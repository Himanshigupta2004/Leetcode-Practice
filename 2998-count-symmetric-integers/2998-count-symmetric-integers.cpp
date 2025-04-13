class Solution {
public:
    int countSymmetricIntegers(int low, int high) {
        int count=0;
        for(int i=low;i<=high;i++){
            string s=to_string(i);
            if(s.size()%2==0){
                int mid=s.size()/2;
                int left=0,right=0;
                for(int lefty=0;lefty<mid;lefty++) left+=s[lefty]-'0';
                for(int righty=mid;righty<s.size();righty++) right+=s[righty]-'0';
                if(left==right) count++;

            }
        }
        return count;
    }
};