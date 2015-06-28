n = int(raw_input())
nums = raw_input().split(' ')
ret = 0
mode = 0
i = 0
while i < len(nums):
    # eat 0's
    while i < len(nums) and nums[i] == '0':
        i += 1
    cnt = 0
    # count all 1
    while i < len(nums) and nums[i] == '1':
        i += 1
        cnt += 1
    if cnt > 0:
        ret += (cnt + mode)
    mode = 1
print ret
