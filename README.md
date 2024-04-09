## HW CH.17 Solution
## Aggregate Method:
In the aggregate method, we calculate the total cost of performing n insertions and then divide it by n to get the average cost per insertion.
1.	Doubling Cost: When the table is resized, it takes O(n) time to copy elements from the old table to the new table.
2.	Insertion Cost: Inserting into the table itself takes O(1) time.
Given that the table doubles in size, after k insertions, the table will be resized k times.
Let's denote T(n) as the total time taken forn insertions.
T(n)=Doubling Cost+Insertion Cost×n
T(n)=n+O(n)×n
T(n)=n+O(n2)
T(n)=O(n2)
Dividing by n:
Amortized Time per Insertion=O(n2)/n=O(n)
## Accounting Method:
In the accounting method, we assign a certain "credit" or "debit" to each operation such that the sum of credits always covers the cost of the operations. In this case, we'll assign a cost of 2 to each insertion operation, where 1 is used for the operation itself, and 1 is stored for potential future resizing.
1.	Insertion Cost: We charge 2 units for each insertion operation.
2.	Doubling Cost: We don't directly charge for doubling since we prepay for it during insertions.
Given that the table doubles in size, after k insertions, the table will be resized k times. We charge 2k for the k insertions and k for resizing. Thus, the total cost is 2n+n=3n.
Dividing by n:
Amortized Time per Insertion=n3n=3
So, for both methods:
a) Aggregate Method: O(n)
b) Accounting Method: O(1)

