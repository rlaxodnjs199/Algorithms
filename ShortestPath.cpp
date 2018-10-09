/*
->Finding shortest path in unweighted graph
In unweighted graph, the shortest path means
smallest number of edges needed to reach from
source vertex to destination vertex.
There for BFS, which goes through the vertexes
based on level of number of edges, is the optimized
strategy for finding shortest path. When using DFS,
it is possible that we can find shortest path but we
should need to measure all the possibilities, updating
'smallest num of edges' and return that path.
This is absolutely inefficient.

->Finding shortest path in weighted graph

*/