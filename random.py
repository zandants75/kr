import random

list = []
for i in range(100):
    list.append(random.randint(0,1000))          

def max(list):
    #sort list from least to greatest
    answer = list.sort()
    #get last item in list (max value)
    list.pop()

    return max  

print (max(list))
