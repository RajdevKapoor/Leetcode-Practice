class Solution:
    def isPrefixOfWord(self, sentence: str, searchWord: str) -> int:
        
        lis = sentence.split(" ")
        s = searchWord

        for i in lis:
            if i.startswith(s):
                return lis.index(i) + 1
        return -1