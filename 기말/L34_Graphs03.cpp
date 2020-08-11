/**
 * 그래프 응용!
 * 
 * < Shortest path >
 *      : Weighted Graph에서 특정 vertex에서 다른 모든 vertex에 이르는 최단 거리 path를 구한 문제 
 *          (single source all destination)
 * 
 *      1. 알고리즘
 *          i) 초기화
 *              : Adjacency matirx 에서 기준 vertex에 해당하는 행(row)을 초기값으로 설정
 *          ii) 반복, 다음을 n-2회 수행  // 자기자신에 대해선 안하고, 맨 마지막도 안하기 때문 
 *              : 아직 방문하지 않은 vertex 중에서 가장 가까운 vertex 선택
 *              : 해당 vertex를 거쳐서 가는 path가 현재 알려진 path보다 짧으면 수정
 * 
 * 
 *      2. Bellman & Ford 알고리즘
 *          : 기준 vertex(v)에서 다른 모든 vertex에 이르는 shortest path 를 찾는 문제
 *          : [방법] 모든 edge에 대하여 다음 과정을 (n-2)회 반복
 *              그 dege를 거치면, 현재 알려진 length보다 짧아지면, length를 수정
 * 
 *          구현)
 *              for(k=0; k<n ; k++)
 *                  dist[k] = cost[v][k]; 
 *              for(k=2;k<= n-1; k++)
 *                  for( each edge(v1,v2) in the graph)
 *                      if(dist[v2]> dist[v1] + cost[v1][v2] )
 *                          dist[v2] = dist[v1] + cost[v1][v2]
 * 
 * 
 * 용어) 
 * < Transitive closure >
 *      Adjacency matrix : A
 *          - vertex 간에 edge가 존재하면 1, 아니면 0
 *      Transitive closure : A+
 *          - Vertex 간에 path가 존재하면 1, 아니면 0 
 *      Reflexive transitive closure : A* 
 *          - 자신과의 path도 고려한 transitive closure  
 */