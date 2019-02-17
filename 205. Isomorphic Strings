class Solution:
    
    # sol1, my, using dic to check unmatch mapping
    # def isIsomorphic(self, s: 'str', t: 'str') -> 'bool':
    #     if len(s) != len(t):
    #         return False
    #     l = len(s)
    #     i = 0
    #     dic = {}
    #     while i < l:
    #         if s[i] in dic.keys():
    #             if dic[s[i]] != t[i]:
    #                 return False
    #         else:
    #             if t[i] in dic.values():
    #                 return False
    #             else:
    #                 dic[s[i]] = t[i]
    #         i += 1
    #     return True
    
    
    # sol2: use property of isomorphism
    # all from: https://leetcode.com/problems/isomorphic-strings/discuss/57941/Python-different-solutions-(dictionary-etc).     
    # def isIsomorphic(self, s: 'str', t: 'str') -> 'bool':
    #     return len(set(zip(s,t)))==len(set(s))==len(set(t))
    
    # sol3: use dict, check all mapping code
    # use dict.get(key[, value]) 
    # def isIsomorphic(self, s: 'str', t: 'str') -> 'bool':
    #     ds, dt = {}, {}
    #     for i, val in enumerate(s):
    #         ds[val] = ds.get(val, []) + [i]
    #     for i, val in enumerate(t):
    #         dt[val] = dt.get(val, []) + [i]
    #     return list(ds.values()) == list(dt.values())

    
    # sol4: use a dictionary-like ASIC list
    # def isIsomorphic(self, s: 'str', t: 'str') -> 'bool':
    #     ds, dt = [[] for _ in range(256)], [[] for _ in range(256)]
    #     for i, val in enumerate(s):
    #         ds[ord(val)].append(i)
    #     for i, val in enumerate(t):
    #         dt[ord(val)].append(i)
    #     return sorted(ds) == sorted(dt)
    
    # sol5: use find index
    # def isIsomorphic(self, s: 'str', t: 'str') -> 'bool':
    #     return [s.find(i) for i in s] == [t.find(j) for j in t]
    
    # sol6: use find in map
    # def isIsomorphic(self, s: 'str', t: 'str') -> 'bool':
    #     return list(map(s.find, s)) == list(map(t.find, t))
    
    # sol7, index for list matching
    def isIsomorphic(self, s: 'str', t: 'str') -> 'bool':
        ds, dt = [0 for _ in range(256)], [0 for _ in range(256)]
        for i in range(len(s)):
            if ds[ord(s[i])] != dt[ord(t[i])]:
                return False
            ds[ord(s[i])] = i+1
            dt[ord(t[i])] = i+1
        return True
