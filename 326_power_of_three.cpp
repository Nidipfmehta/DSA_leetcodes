class Solution {
public:
    bool isPowerOfThree(int n) {
        if(n==1)
        {
            return true;
        }
        else if (n>0 and n%3==0)
        {
            return isPowerOfThree(n/3);
        }
        else
        {
            return false;
        }
    }
};