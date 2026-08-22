class Solution:
    def reverse(self, x: int) -> int:
        z=0
        sign= -1 if x<0 else 1
        x=abs(x)
        while(x>0):
            t=x%10 
            z=(z*10)+t
            x=x//10
        z=sign*z

        if z< -2**31 or z>2**31:
            return 0
        return z
