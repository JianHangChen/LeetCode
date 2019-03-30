
def fizzBuzz(self, n):
    """
    :type n: int
    :rtype: List[str]
    """

    # sol1
    result = []
    for i in range(1,n+1):
        if i % 3 == 0:
            if i % 5 == 0:
                result.append('FizzBuzz')
            else:
                result.append('Fizz')
        elif i % 5 == 0:
            result.append('Buzz')
        else:
            result.append(str(i))
    return result

    # sol2: one line
def fizzBuzz(self, n):
    return ['Fizz'*(not i % 3) + 'Buzz'*(not i % 5) or str(i) for i in range(1,n+1)]

# sol3: hash
def fizzBuzz(self, n):
    hashmap = {3:"Fizz", 5: "Buzz"}
    res = []

    for i in range(1, n+1):
        ans = ""

        for key in hashmap.keys():
            if i % key == 0:
                ans += hashmap[key]

        if not ans:
            ans += str(i)

        res.append(ans)

    return res
        
