a,b=map(int,input().split())
if a>=0 and b<=2:print("nova")
elif b>a and b<=96:print("crescente")
elif a>=b and b<=96:print("minguante")
else:print("cheia")
