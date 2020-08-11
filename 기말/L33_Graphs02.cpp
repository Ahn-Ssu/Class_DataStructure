/**
 * < Spanning trees >
 *      Graph G의 spanning tree
 *          : G의 모든 vertex를 연결하는 Cycle이 없는 subgraph, Spanning tree는 n-1개의 edge를 갖는다. 
 *              (모든 것을 연결'만' 수행)
 *          
 *   1. 종류 
 *      DFS spanning tree    // serch 과정이랑 똑같음
 *      BFS spanning tree 
 * < Biconnected components >
 *      : articulation point를 갖지 않는 connected graph 
 * 
 *      + Articulation point
 *          : 해당 vertex를 삭제 했을 떄, 원래의 graph가 두 개 이상의 
 *              biconnected component로 분리되는 vertex
 * 
 * < Minimum cost spanning tree >
 *      : Weighted(가중) graph에서 cost의 합이 최소인 spanning tree를 찾는 문제 
 * 
 *      1. that's Algorithm 
 *          i) Kruskal's Algorithm
 *              : 전체 edge 집합을 cost 순서로 sort하고, cost 순서대로 edge를 판단
 *          ii) Prim's Algorithm
 *              : Start vertex에서 시작하여 현재 유지되고 있는 connected component와 연결된 edge를 고려
 *          iii) Sollin's Algorithm
 *              : 각 node를 개별 connected component로 고려하여, 한 개씩 edge를 선택하여 추가\
 * 
 * 
 * 
 * 
 *          I) Kruskal 
 *              a. 전체 edge의 집합을 cost 순서로 sorting 
 *              b. Cost 순서로, 해당 edge가 cycle을 이루지 않으면 선택 // 오름차순으로 선택, cycle 되면 버리고 다음꺼 수행
 *              c. (n-1)개의 edge가 선택될 때까지 반복 
 * 
 *          II) Prim 
 *              a. start vertex로 부터 시작
 *              b. 현재 구성되는 connected component와 (외부로) 연결된 edge 중에서 최소 cost edge를 선택
 *              c. (n-1)개의 edge가 선택될 때 까지 반복
 *  
 *          III) Sollin
 *              a. 각 vertex를 서로 다른 connected component로 고려 
 *              b. 각 connected component에 대하여 최소 cost edge를 한 개씩 추가
 *              c. 전체가 한 개의 connected component가 되면 종료 
 */