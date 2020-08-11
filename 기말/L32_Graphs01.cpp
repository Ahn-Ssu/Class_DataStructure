/**
 * Graphs 란?? 
 *  A nonempty set of vertices and a set of edges 
 *    : Graph G 는 Vertex의 집합(V)과 Edge의 집합(E)으로 이루어진다. 
 *      ex) V(G) = { a,b,c,d,e } 
 *          E(G) = { (a,b), (a,c), (a,d), (b,e), (d,e) }   : a에서 b에 이르는 엣지가 존재한다. 
 * 
 *  < 용어 >
 *  0. Vertex(=node), edge(=arc) 
 *  1. Adjacent : 두 vertex간의 edge가 존재함  // 직접 연결이 존재하는가? 에 대한 이야기 
 *  2. Path : 두 vertex간에 edge로서 연결되는 vertex의 sequence 
 *  3. Length of a path : path를 구성하는 "edge 개수"
 *  4. Connected : 두 vertex간에 path가 존재함  // adjacent랑 다른 것은 직접연결이 아니고 간접 연결이여도 표현함
 *  5. Connected components : 상호 연결된 sub-graph 
 *  6. Cycle : 시작과 끝이 동일 vertex인 path  
 *  7. Strongly connected : directed graph에서 양방향 path가 존재 
 *  8. Degree of a vertex : 그 vertex와 연결된 edge의 수 
 *      i) indegree : directed graph 에서 incoming edge의 수       ->ㅇ<-
 *      ii) outdegree : directed graph에서 outgoing edge의 수       <-ㅇ->
 *  9. Fully connected graph의 edge 수 : n*(n-1)/2
 * 
 * 
 *    +) 한붓 그리기가 가능한 graph의 형태 
 *          -> degree가 홀수인 vertex가 없거나, 2개인 경우
 *  < 표기 > 
 *  1. Edge의 표기
 *      (v1, v2) : 방향성이 없는 edge -> graph ( = undirected graph)
 *      <v1, v2> : 방향성을 갖는 edge -> directed graph (= digraph) 
 * 
 * 
 *  < Graph representations >
 *   1. Adjacency matrix 
 *   
 *                  1 : adjacent // 대각선을 기준으로 상호 대칭 (방향성이 없는 경우!)
 *          
 *                                  to
 *                          0   1   2   3   4
 *                         ㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡ
 *                       0 ㅣ0   1   1   1   0   
 *            from       1 ㅣ1   0   0   0   1  
 *                       2 ㅣ1   0   0   1   0   
 *                       3 ㅣ1   0   1   0   1   
 *                       4 ㅣ0   0   0   1   0   
 * 
 *  2. Adjacency lists 
 * 
 *                  0 -> 1 -> 2-> 3             : 0에는 1,2,3이 인접해있다.
 *                  1 -> 0 -> 4                 : 1에는 0과 4가 인접해 있다.
 *                  2 -> 0 -> 3
 *                  3 -> 0 -> 2 -> 4
 *                  4 -> 1 -> 3 
 *  3. A weighted graph 
 *      각 path 에 가중치가 있음 (ex. 시간, 거리 등)
 * 
 * < 연산 >
 *  1. Search 
 *      - DFS (Depth First Search)      : 파고드는 것을 우선으로 하고, 더이상 불가능할때 back tracking 
 *      - BFS (Breadth First Search)    : 폭 우선, 인접한 것 먼저하고, 그 후에 인접한 것에서 다시 그것에 대해 인접한 것 수행 
 * 
 *      A. DFS(Depth First Search) 
 *      - Algorithm 
 *          i) statr vertex를 방문하고, 'stack'에 넣는다.
 *          ii) stack empth일 때까지 다음을 반복
 *              : Stack의 top원소와 adjacent한 vertex 중에 아직 방문하지 않은 vertex를 한 개 선택하여 방문하고,
 *                stack에 넣는다. 더 이상 선택할 원소가 없다면, stack에서 원소 한 개를 pop 한다. 
 * 
 *      B. BFS(Breadth First Search)
 *      - Algorithm
 *          i) Start vertex를 qkdansgkrh, 'queue'에 넣는다.
 *          ii) queue empty일 때까지 다음을 반복
 *              : Stack의 front 원소와 adjacent한 vertex 중에 아직 방문하지 않은 vertex를 한 개 선택하여 방문하고,
 *                queue에 넣는다. 더 이상 선택할 원소가 없다면, queue에서 원소 한 개를 delete 한다. 
 * 
 * 
 *      FAQ 
 *          1. 각 vertex에 대하여 처리(방문)여부 판단
 *              i) 각 vertex에 대한 falg 배열 -> 모두 0으로 초기화
 *              ii) vertex를 방문하면, 해당 flag를 1로 변경
 * 
 *          2. adjacent한 vertex가 여러개일 때 선택 순서
 *              i) Graph의 표현 형태에 따라 순서가 결정됨 (구현에 따라 달라짐) 
 *              ex) Edge 데이터 입력순서
 *                  Vertex에 부여된 일련 번호 순서 
 */