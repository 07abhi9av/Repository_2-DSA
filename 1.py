class Node(object):
    def __init__(self, x):
        self.item = x
        self.next = None
     
def isPalindrome(head):
    stack = []
    temp = head
    while temp:
        stack.append(temp.item)
        temp = temp.next
    n = len(stack)   
    i = 0 
    j = n - 1
    
    while i < j:
        if stack[i] != stack[j]:
            return False
        i += 1
        j -= 1
    return True
    
def createLL(length, value):
    dummy = Node(0)
    current = dummy
    
    for i in value:
        current.next = Node(i)
        current = current.next
    return dummy.next
    
if __name__ == "__main__":
    n = int(input())
    value = list(map(int, input().split()))
    head = createLL(n, value)
    
    print(isPalindrome(head))



LONGEST SUBSTRING WITHOUT REPEATING CHARACTERS
You are given a string s. Your task is to find the length of the longest substring that contains each character at most once.
A substring is a contiguous sequence of characters within a string.
Input
Enter the String without any space
Output
Return the length as integer
Example
Input:

xyzxyzyy
Output:

3
