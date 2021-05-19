# BinPacking
This is a very straightforward greedy approximation algorithm. The algorithm processes the items in arbitrary order. For each item, it attempts to place the item in the first bin that can accommodate the item. If no bin is found, it opens a new bin and puts the item within the new bin.

非常直覺的貪婪近似演算法
物品排放的順序為隨意
對每一件物品來說,它會將其放置在第一格可以裝得下這件物品的箱子裡,如果找不到裝的下的箱子則會另外再開一個新的箱子

箱子體積大小為1
## Input
第一行代表物品的個數N
第二行開始有N個大於0且小於等於1的物品的體積,以空白間隔
## Output
請輸出最少需要用多少箱子才可以裝得下所有的物品

## Sample input
5

0.3 0.5 0.8 0.2 0.4
## Sample output
3
