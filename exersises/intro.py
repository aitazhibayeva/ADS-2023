import sys

stack = []


for str in sys.stdin:

    lst = list(str.split())

    if lst[0] == "push":

        n = int(lst[1])

        stack.append(n)

        print("ok")

    elif lst[0] == "pop":

        print(stack.pop())

    elif lst[0] == "back":

        print(stack[-1])

    elif lst[0] == "size":

        print(len(stack))

    elif lst[0] == "clear":

        stack.clear()

        print("ok")

    else:

        print("bye")

        break
