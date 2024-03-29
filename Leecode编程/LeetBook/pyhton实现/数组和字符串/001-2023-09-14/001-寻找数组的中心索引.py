class Solution:
    def pivotIndex(self, nums: List[int]) -> int:
        all = sum(nums)
        left = 0
        for i in range(len(nums)):
            if left * 2 + nums[i] == all:
                return i
            else:
                left += nums[i]
        return -1