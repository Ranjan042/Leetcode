class Solution {
public:
    bool isPalindrome(int x) {
           if(x<0){
            return false;
        }

        int rev=0;
        int n=x;

        while(n>0){
              if (rev > (INT_MAX - n % 10) / 10) {
                return false; 
            }
            rev=rev*10+n%10;
            n=n/10;
        }

        if(rev==x){
            return true;
        }

        return false;
    }
};