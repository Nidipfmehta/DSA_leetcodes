class Solution {
public:
    bool isPowerOfTwo(int n) {
        if(n==1)
        {
            return true;
        }
        else if (n > 0 and n%2==0)
        {
            return isPowerOfTwo(n/2);
        }
        else
        {
            return false;
        }
    }
};