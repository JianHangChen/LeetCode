def decodeString(self, s: str) -> str:
    stack = [["", 1]]
    num = ""
    for c in s:
        if c.isdigit():
            num += c
        elif c == "[":
            stack.append(["", int(num)])
            num = ""
        elif c == "]":
            string, count = stack.pop()
            stack[-1][0] += string * count
        else:
            stack[-1][0] += c

    return stack[-1][0]


