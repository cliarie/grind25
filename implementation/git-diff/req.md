## part 1: given 2 lists of strings, return all the strings that appear in both lists

## part 2: given 2 lists remove the common prefixes and common suffixes, and return the remaining

## part 3: given 2 lists of lines return the git diff

list a: [a, b, c, f,  d, e]
list b: [a, b, w, f, e]

you return: [a,b] [e] [c, f, d] [w, f]
[prefix][suffix][remaining a][remaining b]

algo is remove prefix and suffix
find unique and split
recursively call diff on both

a
b
- c
+ w
f
- d
e
