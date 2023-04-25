# DSA-SegTree
Segment trees are a powerful data structure used in many applications, such as range queries, and are often used in competitive programming. They are essentially a binary tree, where each node represents a segment of an array.

The root node of the tree represents the entire array, and each child node represents half of the array, and so on. Each node keeps track of the minimum, maximum, or sum of the elements within its segment.
(Parent Node)
A parent node in a segment tree is a node that has at least one child. For example, in a segment tree with four elements {1, 2, 3, 4}, the root node would represent the entire array and would be the parent node of its two child nodes. The two child nodes would each represent a segment of the array: one would represent elements {1, 2} and the other would represent elements {3, 4}.
(Child Node)
A child node in a segment tree is a node that is directly below another node (its parent node). For example, in the same segment tree with four elements, the child nodes of the root node would each have their own child nodes. The left child node would represent elements {1, 2}, and it would have its own left and right child nodes representing elements {1} and {2}, respectively. The right child node would represent elements {3, 4}, and it would have its own left and right child nodes representing elements {3} and {4}, respectively.

To implement a segment tree in C++, we can define a struct or a class to represent each node. The struct or class would contain information about the segment it represents, such as the starting and ending indices of the array, as well as the minimum, maximum, or sum of the elements within that segment.
Start and end indices
Min, Max, sum of elements in the segment
Pointers, to point to the left and right child node

When working with segment trees, there are several important concepts and techniques that one should be familiar with. Some important things to know when working with them are...

1. Query and update operations: Knowing how to implement query and update operations for the specific problem you are trying to solve. 
2. Building the segment tree: Knowing how to build the segment tree from the original array.
3. Segment tree node structures: Knowing the contents of each node in the segment tree and the information contained within each range of indices they represent.
4. Range minimum/maximmum queries: Effectively and efficiently implementing a range minimum/maximum query operation to take advantage of a segment trees structure.
5. Lazy propagation: A technique used to significantly reduce the time complexity of some update operations.
6. Space and time complexity: Knowing the importance to consider the space and time complexity of the operations that are being performed. Such as O(n log n) space to store the structure and support queries and updates. 

# Running the Code
To use our program there are 3 main files, a main.cpp, SegTree.cpp, and SegTree.h; in addition, we will be using a text file containing camera records of the number of cars recorded at a particular timestamp. From the text file a vector of nodes containing the data are used to make the segment tree.\
The following command line is used to run the prgram.\
```g++ -std=c++11 main.cpp -o main && ./main SegTree.cpp traffic.txt```
