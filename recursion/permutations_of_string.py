"""
Permutations are different than combinations in the way that even if same characters are present in a different order, it makes a new permutation.
Find all permutations of a string.
"""
    
def permute(s):
    # Select each character from the string one by one. 
    # Find permutations for rest of the string.
    # Stick the select element in front of every such permutated string.
    outlist = []
    if len(s) == 0 or len(s) == 1:
        outlist.append(s)
    else:
        for idx in range(len(s)):
            l = list(s)
            selected = l.pop(idx)
            rest = ''.join(l)
            permutations = permute(rest)
            for each in permutations:
                outlist.append(selected+each)
    return outlist

        
if __name__ == '__main__':
    p = permute('abcd')
    assert(len(p) == 24)
    print p
    

