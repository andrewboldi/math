import itertools

string = "AAABBBCCC"
arr = []
count = 0
bl = True


string_permutations = itertools.permutations(string)
string_permutations = list(string_permutations)
string_permutations = [''.join(permutation) for permutation in string_permutations]
for stri in string_permutations:
    for i, letter in enumerate(stri):
        if letter == string[i]:
            break
        if i == 8:
            arr.append(stri)
print(len(arr))

seen = set()
result = []
for item in sorted(arr):
    key = item
    if key not in seen:
        result.append(item)
        seen.add(key)

print(seen)
