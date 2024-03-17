uclass Node(object):
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


def longest_substring(s: str) -> int:
    char_index = {}
    max_length = 0
    start = 0

    for end in range(len(s)):
        if s[end] in char_index:
            # If the character is already in the current substring,
            # update the start of the substring to the next position after the previous occurrence.
            start = max(start, char_index[s[end]] + 1)

        # Update the index of the current character.
        char_index[s[end]] = end

        # Update the maximum length of the substring.
        max_length = max(max_length, end - start + 1)

    return max_length

# Example usage:
s = input("Enter the string without any space: ")
print(longest_substring(s))
