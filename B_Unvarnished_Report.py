s = input()
t = input()

if s == t:
    print(0)
else:
    flag = False
    min_len = min(len(s), len(t))
    for i in range(min_len):
        if s[i] != t[i]:
            print(i + 1) 
            flag = True
            break
    if not flag:
        print(min_len + 1)
