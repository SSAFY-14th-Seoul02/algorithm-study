N = int(input())

if N > 1022:
    print(-1)
    exit()

nums = list(range(10)) 

idx = 0
while idx < len(nums):
    current_num = nums[idx]
    
    if len(nums) > N and idx > N:
        break

    last_digit = current_num % 10
    
    for next_digit in range(last_digit):
        new_num = current_num * 10 + next_digit
        nums.append(new_num)
        
    idx += 1

print(nums[N])