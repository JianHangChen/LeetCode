看到这题让我想到了小时候玩的一个暴露年龄的小游戏机：

def towerOfHanoi(self, n):
    ans = []
    def move(n,a,b,c):
        if n == 1:
            ans.append("from "+a+" to "+c)
        else:
            move(n-1,a,c,b)
            ans.append("from "+a+" to "+c)
            move(n-1,b,a,c)

    move(n,"A","B","C")
    return ans
