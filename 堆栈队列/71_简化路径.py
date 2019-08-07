class Solution:
    def simplifyPath(self, path: str) -> str:
        path_list = path.split('/')
        print(path_list)
        stack = []
        res = ""
        for item in path_list:
            if item not in ['', '..', '.']:
                stack.append(item)
            if item == '..' and stack:
                stack.pop()
        if stack == []:
            return "/"
        for item in stack:
            res += '/' + item
        return res

if __name__ == "__main__":
    string = '/a/./b/../../c/'
    sol = Solution()
    print(sol.simplifyPath(string))