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
1. Using BFS for finding shortest path in weighted graph?
We can't do this by using normal BFS since when we visit
a node once, we marked it as visited and doesn't visit again.
To compute shortest path, we need to investigate different paths
to certain node to get an answer.
2. Dijsktra's algorithm
Dijsktra's algorithm is finding shortest path by greedy choice.
Starting from a certain vertex, it updates distance to all
adjacant vertex and push the weight from start vertex to 
priority queue. We select edges in greedy manner like this so that
we are choosing minimum weight path from start vertex at any moment.
When all the vertexes are visited(priority queue is empty)
, loop is terminated. One problem in Dijsktra's algorithm is that
it cannot deal with negative edge because it does not necessarily
several paths to the destination vertex. The path found first is regarded
as the shortest path in Dijsktra's algorithm.
3. Bellman-Ford algorithm
Bellman-Ford algorithm is finding shortest path by recursively update
all the reachable paths
*/