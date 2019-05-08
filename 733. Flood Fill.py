    def floodFill(self, image: List[List[int]], sr: int, sc: int, newColor: int) -> List[List[int]]:
        color = image[sr][sc]
        lr = len(image); lc = len(image[0])
        
        def dfs(sr, sc):
            if image[sr][sc] == newColor:
                return
            else:
                if image[sr][sc] == color:
                    image[sr][sc] = newColor
                    if sr + 1 < lr:
                        dfs(sr + 1, sc)
                    if sr - 1 >= 0:
                        dfs(sr - 1, sc)
                    if sc + 1 < lc:
                        dfs(sr, sc + 1)
                    if sc - 1 >= 0:
                        dfs(sr, sc - 1)
        
        dfs(sr,sc)
        return image
