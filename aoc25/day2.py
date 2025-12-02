def parse(filename: str):
    with open(filename) as f:
        return f.read().split(',')
    
def part1(content):
    ans = 0
    for line in content:
        start, end = map(int, line.split('-'))
        for num in range(start, end + 1):
            s = str(num)
            if len(s) % 2 == 0 and s[:len(s)//2] == s[len(s)//2:]:
                ans += num
    return ans

def part2(content):
    ans = 0
    for line in content:
        start, end = map(int, line.split('-'))
        for num in range(start, end + 1):
            s = str(num)
            l = len(s)
            for interval in range(1, l//2 + 1):
                if l % interval != 0: continue
                if s[:interval] * (l//interval) == s:
                    ans += num
                    break
    return ans

content = parse("input.txt")
print(part1(content))
print(part2(content))
