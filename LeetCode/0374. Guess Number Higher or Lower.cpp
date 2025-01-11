// 簡單的binary search
/** 
 * Forward declaration of guess API.
 * @param  num   your guess
 * @return 	     -1 if num is higher than the picked number
 *			      1 if num is lower than the picked number
 *               otherwise return 0
 * int guess(int num);
 */

class Solution {
public:
    int guessNumber(int n) {
        int l = 1, r = n;
        int m = (l+(r-l))/2;
        int result = guess(m);
        while(result){
            if(result==1)  l = m+1;
            else r = m-1;
        }
        return m;
    }
};