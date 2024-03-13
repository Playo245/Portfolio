#!usr/bin/env python3

def move_vow(senc):
    vowels = []
    nvowels = []
    for i in senc:
        if i in "aeiouAEIOU":
            vowels.append(i)
        else:
            nvowels.append(i)
    return "".join(vowels) + "".join(nvowels)

print(move_vow('This is DCU!'))
