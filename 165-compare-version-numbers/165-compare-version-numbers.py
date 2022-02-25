class Solution(object):
    def compareVersion(self, version1, version2):
        """
        :type version1: str
        :type version2: str
        :rtype: int
        """
        v1, v2 = list(map(int, version1.split('.'))), list(map(int, version2.split('.')))
        
        #making len equal if not
        l1=len(v1)
        l2=len(v2)
        
        if(l1>l2):
            for _ in range(l1-l2):
                v2.append(0)
                
        elif(l1<l2):
            for _ in range(l2-l1):
                v1.append(0)
                
        for i in range (max(l1,l2)):
            if(v1[i]>v2[i]):
                return 1
            
            if(v1[i]<v2[i]):
                return -1
        
        return 0