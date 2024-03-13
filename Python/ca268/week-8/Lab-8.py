Data Structure	Time Complexity	Space Complexity
Average	Worst	Worst
                    Access	Search	  Insertion	    Deletion	    Access	Search	Insertion  Deletion  SC
Array	            Θ(1)	Θ(n)	  Θ(n)	        Θ(n)	        O(1)	O(n)	O(n)	   O(n)	     O(n)
Stack	            Θ(n)	Θ(n)	  Θ(1)	        Θ(1)	        O(n)	O(n)	O(1)	   O(1)	     O(n)
Queue	            Θ(n)	Θ(n)	  Θ(1)	        Θ(1)	        O(n)	O(n)	O(1)	   O(1)	     O(n)
Singly-Linked List  Θ(n)	Θ(n)	  Θ(1)	        Θ(1)	        O(n)	O(n)	O(1)	   O(1)	     O(n)
Doubly-Linked List  Θ(n)	Θ(n)	  Θ(1)	        Θ(1)	        O(n)	O(n)	O(1)	   O(1)	     O(n)
Skip List	        Θ(log(n))Θ(log(n))Θ(log(n))	    Θ(log(n))	    O(n)	O(n)	O(n)	   O(n)	     O(n log(n))
Hash Table	        N/A	    Θ(1)	  Θ(1)	        Θ(1)	        N/A	    O(n)	O(n)	   O(n)	     O(n)
Binary Search Tree  Θ(log(n))Θ(log(n))Θ(log(n))	    Θ(log(n))	    O(n)	O(n)	O(n)	   O(n)	     O(n)
AVL Tree	        Θ(log(n))Θ(log(n))Θ(log(n))	    Θ(log(n))	    O(log(n))O(log(n))O(log(n))O(log(n)) O(n)

Algorithm	Time Complexity	                                Space Complexity
                Best	        Average	        Worst	        Worst
Quicksort	    Ω(n log(n))	    Θ(n log(n))	    O(n^2)	        O(log(n))
Mergesort	    Ω(n log(n))	    Θ(n log(n))	    O(n log(n))	    O(n)
Bubble Sort	    Ω(n)	        Θ(n^2)	        O(n^2)	        O(1)
Insertion Sort	Ω(n)	        Θ(n^2)	        O(n^2)	        O(1)
Selection Sort	Ω(n^2)	        Θ(n^2)	        O(n^2)	        O(1)
Tree Sort	    Ω(n log(n))	    Θ(n log(n))	    O(n^2)	        O(n)
Bucket Sort	    Ω(n+k)	        Θ(n+k)	        O(n^2)	        O(n)
Radix Sort	    Ω(nk)	        Θ(nk)	        O(nk)	        O(n+k)
Counting Sort	Ω(n+k)	        Θ(n+k)	        O(n+k)	        O(k)
