def solve(s):
    MOD = 1000000007
    
    n = len(s)
    
    zero_count = [0] * n
    one_count = [0] * n
    
    z_prefix = 0
    o_prefix = 0
    
    for i in range(n):
        if s[i] == '0':
            z_prefix += 1
        zero_count[i] = z_prefix
        
        if s[i] == '1':
            o_prefix += 1
        one_count[i] = o_prefix
    
    count_map = {0: 1}
    ans = 0
    
    for i in range(n):
        diff = zero_count[i] - one_count[i]
        
        if diff in count_map:
            diff_count = count_map[diff]
            remaining = n - i
            
            partial_ans = (diff_count * remaining) % MOD
            ans = (ans + partial_ans) % MOD
            
            count_map[diff] = (diff_count + (i + 2))
        else:
            count_map[diff] = (i + 2)
    
    print(ans)

def main():
    import sys
    input = sys.stdin.read
    data = input().split()
    
    index = 0
    t = int(data[index])
    index += 1
    
    for _ in range(t):
        s = data[index]
        index += 1
        solve(s)

if __name__ == "__main__":
    main()
