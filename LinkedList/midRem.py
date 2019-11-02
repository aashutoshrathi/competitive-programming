class Node:
    def __init__(self, val):
        self.val = val
        self.next = None


class LinkedList:
    def __init__(self):
        self.head = None

    def add(self, val):
        temp = self.head
        if temp:
            while temp.next is not None:
                temp = temp.next
            temp.next = Node(val)
        else:
            self.head = Node(val)

    def get_len(self):
        temp = self.head
        cnt = 0
        while temp is not None:
            cnt += 1
            temp = temp.next
        return cnt

    def __str__(self):
        res = ""
        temp = self.head
        # print(temp)
        while temp is not None:
            res += str(temp.val) + " "
            temp = temp.next
        return res


def removeMid(node):
    fast = node
    slow = node
    while fast.next is not None:
        fast = fast.next.next
        slow = slow.next
    print(slow.val)


def main():
    ll = LinkedList()
    ll.add(1)
    ll.add(10)
    ll.add(20)
    ll.add(30)
    ll.add(40)
    print(ll)
    removeMid(ll.head)
    print(ll)


if __name__ == "__main__":
    main()
