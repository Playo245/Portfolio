def search_q1(Y, n, x):

    for i in range (0, n):
        if Y[i] == x:
            return i
    return -1


Y = ['apple', 'banana', 'mango', 'grapes', 'pineapple', 'durian']
x = "pineapple"

n = len(Y)
result = search_q1(Y, n, x)
if result == -1:
    print("Element is not present in the list")
else:
    print("Element", x, "is present at index", result)

//O(n)

def search_q2(X, item):
    first = 0
    last = len(X)-1
    found = False
    while first<=last and not found:
        mid = (first + last)//2
        if X[mid] == item:
            found = True
            print("The element item", item, "was found at index ", X.index(60))
        else:
            if item < X[mid]:
                last = mid - 1
            else:
                first = mid + 1
    return found


print(search_q2([10, 15, 35, 42, 60, 70, 82, 94], 60))

//O(logn)

test = 0
n = 10
for i in range(n):
   test = test + 1

for j in range(n):
   test = test - 1

//O(n)

mat = [[1, 2, 3], [1, 1, 1], [5, 7, 8]]
add = 0
for i in range(len(mat)):
    for j in range(len(mat[0])):
        add += mat[i][j]
print(add)

//O(n^2)

def fibonacci(n):
    if n<2:
        return n
    return fibonacci(n-1) + fibonacci(n-2)


for n in range(2,12,2):
    print("Series sum for {} is {}".format(n, fibonacci(n)))

//O(2^n)

Skip list.

//O(logn)

