# import numpy as np, multiprocessing as mp
# def fun1(l): 
#     return (0,np.array(l.split(',')[:-1], dtype=np.float64)) if l[-2] == '0' else (1,np.array(l.split(',')[:-1], dtype=np.float64))
# def fun2(l): 
#     return {0:'0\n',1:'1\n'}[np.linalg.norm(v1-np.array(l.split(','), dtype=np.float64),axis=1).argmin()]
# file1, file2, flie3  =  "./train", "./test.txt", "./result.txt"    
# v0 = mp.Pool().map(fun1,[v for i,v in zip(range(1500),open(file1))])
# v1 = np.array([np.sum(np.array([i[1] for i in v0 if not i[0]]), axis=0)/(1500-sum(map(lambda x:x[0],v0))), np.sum(np.array([i[1] for i in v0 if i[0]]), axis=0)/(sum(map(lambda x:x[0],v0)))])
# open(flie3, 'w').write(''.join(mp.Pool().map(fun2,open(file2))))
""" """ """ """ """ """ """ """ """ """ """  """ """ """ """ """ """ """ """ """ """ """

string = "MCMXCIV"

class Solution:
    def romanToInt(self, s):
        r = {'I':1, 'IV':3, 'V':5, 'IX':8, 'X':10, 'XL':30, 'L':50, 'XC':80, 'C':100, 'CD':300, 'D':500, 'CM':800, 'M':1000}
        return sum(r.get(s[max(i-1, 0):i+1], r[key]) for i, key in enumerate(s))

s = Solution()
test = s.romanToInt(string)