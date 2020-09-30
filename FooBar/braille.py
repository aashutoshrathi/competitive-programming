'''
FooBar Level 1 P1
Solved in 1Hr (as was literally confused if I needs harcode stuff)
returns braille ascii for a english char
'''

d = {
    'a': '100000',
    'b': '110000',
    'c': '100100',
    'd': '100110',
    'e': '100010',
    'f': '110100',
    'g': '110110',
    'h': '110010',
    'i': '010100',
    'j': '010110'
}
t = 'a'
for c in 'klmnopqrst':
    d[c] = d[t][:2]+'1'+d[t][3:]
    t = chr(ord(t) + 1)

t='k'
for c in 'uvxyz':
    d[c] = d[t][:5]+'1'
    t = chr(ord(t) + 1)

d['w'] = '010111'

def brascii(c):
    return d[c]

def solution(s):
    res=''
    for c in s:
        if c == ' ':
            res += '000000'
        else:
            if c.isupper():
                res+= '000001'
                c=c.lower()
            res += brascii(c)
    print(res)

if __name__ == "__main__":
	s = input()
	solution(s)
