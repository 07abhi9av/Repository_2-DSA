class ListNode:
    def __init__(self, data):
        self.data = data
        self.next = None

def merging(l1, l2):
    head = ListNode(-1)
    dummy = head
    t1 = l1
    t2 = l2
    
    while t1 and t2:
        if t1.data < t2.data:
            dummy.next = t1
            dummy = t1
            t1 = t1.next
        else:
            dummy.next = t2
            dummy = t2
            t2 = t2.next
            
    if t1:
        dummy.next = t1
    elif t2:
        dummy.next = t2
        
    return head.next

def create_ll(nums):
    head = ListNode(-1)
    curr = head
    for i in nums:
        curr.next = ListNode(int(i))
        curr = curr.next
    return head.next

def print_ll(head):
    t = head
    while t:
        print(t.data, end=" ")
        t = t.next

n1 = int(input())
list1 = input().split()
n2 = int(input())
list2 = input().split()

l1 = create_ll(list1)
l2 = create_ll(list2)

res = merging(l1, l2)
print_ll(res)