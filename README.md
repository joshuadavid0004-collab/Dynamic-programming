EB3/67259/23 
JOSHUA DAVID 

Understanding Problems (0/1 Knapsack)

You have:
n items
Each item has:
weight w[i]
value v[i]
A knapsack with capacity W

 Objective: maximize overall value, but not over capacity.
 
 Constraint:
Each item is either:
taken (1) 
not taken (0) 

Simple Explanation of How the Algorithm Works.

Imagine it is filling a table:
Rows = items
Columns = capacity
At each cell:
 You decide:
Take the item
Leave the item

Select the better alternative (max value) then.
Metrics Collected
From program:

Number of operations = (n+1)*(W+1)
No. of comparisons = inside max ()
Steps = DP table filling

Time Complexity
Best Case:
O(nW)

Average Case:
O(nW)
Worst Case:
O(nW)

 Space Complexity
O(nW)

 Running with Altered sizes of inputs.
n	W	Operations
1	10	~20
2	10	~30
5	10	~60
10	50	~550
250	100	~25,100
999	500	~500,000
9999	1000	~10 million [?][?]
1.78M	large	 impractical

 Important:
Knapsack is not linear.
Not capacity-dependent, but capacity-dependent.
 Discussion of Results
Efficiently operated on small/medium inputs.
Becomes slow when:
capacity is large
many items

 For very large inputs - need:
Greedy (approximation)
Branch & Bound
 Key Takeaways
Dynamic Programming eliminates repetition.
Stores intermediate results in use.
Ensures best solution.
trade-off = increased memory usage.
