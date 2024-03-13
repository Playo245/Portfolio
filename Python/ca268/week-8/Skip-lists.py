CA268: Lab - Maps, Hash Tables, and Skip Lists
Q1. One of the functions that can result in collision is getindex()
that acts as a hash function containing hash code calculation and compression. The compression which is performed in Line 18, return hash %
len(self.store) is the division method. This can be replaced by MAD.
You can use the following function to calculate p which is a prime number
greater than N.
1 def nextprime ( n ) :
2 if n < 0:
3 raise ValueError
4
5 for i in range ( n + 1 , n + 200) :
6 if i > 1:
7 pr = True
8 for j in range (2 , i ) :
9 if ( i % j ) == 0:
10 pr = False
11 break
12 if pr :
13 return i
14 return ’not found ’
Next, select a, b to be random integers in the range [0, p − 1]. Construct
the MAD equation and change Line 18 of the code.


Q2. You can replace Line 17 with the following function:
1 def compute_hash ( s ) :
2 a = 31
3 n = len( s )
4 hash_value = 0
5 for i in range (len ( s ) ) :
6 hash_value = hash_value + (ord( s [ i ]) *( a **( n -1) ) )
7 n = n -1
8 return hash_value
1


Q3.
1 def num_shift (n , p , d ) :
2 bin_val = format (n , ’08b’)
3 if d == ’l’:
4 shifted_val = bin_val +("0" * p )
5 else :
6 shifted_val = bin_val [: len( bin_val ) - p ]
7
8 return int ( shifted_val , 2)

Q4. Refer to slides 34-38 of Lecture #7 on random item selection for
the insertion process.

Q5. Refer to v2 implementation of Skip list uploaded on Loop.