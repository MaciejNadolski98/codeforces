
interactive = True
ans = None
S = {}
queries = 0

def sol(n):
    MAX = (2 ** n)-1
    print(0)
    S[0] = True
    if insert(0) == 1:
        k = 1
        res = 0
        count = 1
        for i in range(n):
            if insert(2 ** i) == count + 1:
                count += 1
                res += 2 ** i
        return k, res
    else:
        start, stop = 1, MAX
        while start < stop:
            mid = (start + stop + 1) // 2
            if query(mid) == 1:
                start = mid
            else:
                stop = mid - 1
        c = start
        if c == MAX:
            if insert(1) == 2:
                return 2, MAX
            else:
                return 3, MAX
        insert(MAX)
        if query(MAX) == 1:
            return 2, c
        else:
            return 3, c



def f(x):
    k, c = ans
    ggg = [
        x & c,
        x | c,
        x ^ c,
    ][k-1]
    return ggg


def insert(x):
    if interactive:
        print("I", x)
        c = int(input())
        return c
    S[f(x)] = True
    return len(S)

def query(x):
    if interactive:
        print("Q", x)
        c = int(input())
        return c
    count = 0
    for z in S.keys():
        if z >= x:
            count += 1
    return count

if __name__=="__main__":
    t = int(input())
    for _ in range(t):
        n = int(input())
        if not interactive:
            k, c = map(int, input().split())
            ans = k, c
            S = {}
        k, c = sol(n)
        print("A", k, c)


# 011
# 100 -> 110