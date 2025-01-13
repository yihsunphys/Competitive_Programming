class Solution(object):
    def findMaxAverage(self, nums, k):
        """
        :type nums: List[int]
        :type k: int
        :rtype: float
        """
        tmp = 0.0
        for i in range(k):
            tmp+=nums[i]
        ans = tmp/k
        for i in range(k, len(nums)):
            tmp-=nums[i-k]
            tmp+=nums[i]
            ans = max(ans, tmp/k)
        return ans
        