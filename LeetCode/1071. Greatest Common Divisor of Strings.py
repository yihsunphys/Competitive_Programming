class Solution:
    def gcd(x, y):
        if x>y: x, y = y, x
        if y%x==0: 
            return x
        return gcd(y%x, x)
    def gcdOfStrings(self, str1: str, str2: str) -> str:
        if(str1+str2 != str2+str1):
            return ""
        n = len(str1)
        m = len(str2)
        return str1[:gcd(n,m)]