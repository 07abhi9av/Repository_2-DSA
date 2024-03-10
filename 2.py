# Definition for singly-linked list.
class ListNode(object):
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next

class Solution(object):
    def mergeKLists(self, lists):
        stack = []
        dummy = ListNode(0)
        curr = dummy

        for x in lists:
            while x:
                stack.append(x.val)
                x = x.next

        stack.sort()
        while stack:
            newNode = ListNode(stack.pop(0))
            curr.next = newNode
            curr = curr.next

        return dummy.next

def process_input():
    k = int(input())
    input_data = []
    for _ in range(k):
        size = int(input())
        elements = list(map(int, input().split()))
        input_data.append(elements)
    return k, input_data

def main():
    solution = Solution()
    
    k, input_data = process_input()
    lists = [None] * k  # Initialize with None instead of an empty ListNode
    for i in range(k):
        current = ListNode()  # Create a new ListNode
        for val in input_data[i]:
            if not lists[i]:  # If the list is empty, assign the current node as the head
                lists[i] = current
            current.next = ListNode(val)
            current = current.next

    # Merging the lists
    merged_list = solution.mergeKLists(lists)

    # Printing the merged list
    result = []
    current = merged_list
    while current:
        result.append(str(current.val))
        current = current.next

    print(" ".join(result))

if __name__ == "__main__":
    main()


2
4
1 4 5 6
3
1 2 4 5
0 0 1 1 2 4 4 5 5 6
