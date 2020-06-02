def gcd(a, b):
    if (b == 0):
        return a
    return gcd(b, a%b)

T = int(input())
for t in range(T):
    N, L = map(int, input().split())
    mp = list(map(int, input().split()))
    mid = 0
    for i in range(len(mp)-1):
        if mp[i] != mp[i+1]:
            mid = i
            break        
    p_mid = gcd(mp[mid], mp[mid+1])
    p_back = p_mid
    for i in range(mid, -1, -1):
        mp[i] //= p_back
        p_back = mp[i]
    p_for = p_mid
    for i in range(mid+1, len(mp)):
        mp[i] //= p_for
        p_for = mp[i]
    mp.insert(mid+1, p_mid)
    p = list(set(mp))
    p.sort()
    print("Case #" + str(t+1) + ": ", end='')
    for i in mp:
        print(chr(p.index(i)+ord('A')), end='')
    print()
