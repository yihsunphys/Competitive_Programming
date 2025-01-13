class Solution(object):
    def kidsWithCandies(self, candies, extraCandies):
        """
        :type candies: List[int]
        :type extraCandies: int
        :rtype: List[bool]
        """
        mx = max(candies)
        ans = [False] * len(candies)
        for i in range(len(candies)):
            if candies[i]+extraCandies >= mx:
                 ans[i] = True
        return ans
        