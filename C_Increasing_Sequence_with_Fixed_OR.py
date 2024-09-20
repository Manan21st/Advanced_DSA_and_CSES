def solve():
    n = int(input().strip())
    ans = [n]
    temp = n

    for i in range(64):
        if temp & 1:
            ans.append(n ^ (1 << i))
        temp >>= 1
    
    c = sum(1 for num in ans if num != 0)
    
    print(c)
    ans.reverse()
    for num in ans:
        if num != 0:
            print(num, end=" ")
    print()

def main():
    test = int(input().strip())
    for _ in range(test):
        solve()

if __name__ == "__main__":
    main()
