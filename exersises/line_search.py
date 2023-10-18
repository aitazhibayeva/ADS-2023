L = [1,5,4,2,3]
e = 5

def linear_search(L,e):
    index, found = -1, False
    for i in range(len(L)):
        if e == L[i]:
            found = True
            index = i
        return found.index
    
print(linear_search(L,e))