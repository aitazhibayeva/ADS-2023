class Node:
    def __init__(self, data):
        self.data = data
        self.next = None  # make None as the default value for next.


def count_nodes(head):
    # assuming that head != None
    count = 1
    current = head
    while current.next is not None:
        current = current.next
        count += 1
    return count


nodeA = Node("A")
nodeB = Node("B")
nodeC = Node("C")
nodeD = Node("D")
nodeE = Node("E")

nodeA.next = nodeB
nodeB.next = nodeC
nodeC.next = nodeD
nodeD.next = nodeE

print("This linked list's length is: " ) 
print (count_nodes)
print(count_nodes(nodeA))