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
    lists = [ListNode() for _ in range(k)]
    for i in range(k):
        current = lists[i]
        for val in input_data[i]:
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