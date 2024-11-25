def solve(arr, idx, A, B):
    if idx == n:
        return max(A, B)

    add_A = solve(arr, idx + 1, A + arr[idx], B)
    add_B = solve(arr, idx + 1, A, B + arr[idx])

    return min(add_A, add_B)


n = int(input())
arr = list(map(int, input().split()))

ans = solve(arr, 0, 0, 0)
print(ans)
