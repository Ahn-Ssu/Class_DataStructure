/**
 * < Activity Networks >
 *      1. AOV (activity on vertex) networks 
 *          a. a directed graph
 *          b. vertex : 어떤 task나 activity를 의미
 *          c. edge : activity 간의 선후 관계(rpecedence relation)를 의미
 * 
 *      2. AOE ( activity on Edge ) netwoks
 *          a. edge가 activity를 의미하며, vertex는 시작과 종료 event 를 의미
 * 
 * 
 *      
 * 
 * < AOV networks >
 *      : 다음 조건을 만족하는 directed graph 
 *          a. vertex : 어떤 task 나 activity를 의미
 *          b. edge : activity 간의 선후 관계(precedence relation) 를 의미 
 * 
 *      1. Topological sort
 *          : Topological order를 찾는 문제 // *위상적인
 * 
 *       - 다음을 반복 (모든 vertex가 선택될 때 까지)               'pre'
 *          :   predecessor 가 없는 vertex를 선택                   ㅇ - > ㅇ 
 *          :   해당 vertex와 그 vertex의 outgoing edge를 삭제       
 *          !!! 모든 vertex가 선택되지 않는 경우 : cycle이 존재하는 경우
 * 
 * < AOE networks >
 *      : Edge가 activity 의미, weighted edge(ex. 소요시간)                                 
 * 
 * 
 *      1. Critical path        : 어느 작업때문에 전체의 작업이 느려지고 있는가. 전체 성능에 영향을 주는 부분이 어디인가?
 *      2. Earliest start time
 *      3. Latest start time
 * 
 *      1. Critical path
 *          a. start vertex부터 finish vertex 까지의 longest path
 *          b. 전체 성능에 영향을 주는 activities
 *          c. Project performance 를 평가하여 bottleneck(*병목) 을 알아냄
 *          // ciritical path를 개선하고 개선하다보면 the path가 다른 곳으로 바뀔 수 있음 
 * 
 *      2. Earliest start time
 *          : 해당 activity가 시작될 수 있는 가장 빠른 시간 
 *          ex) earliest(a7) = 8
 *              earliest(a8) = 13
 *              earliest(a11) = 17
 *          // 직전 vertex에서 끝나자마자 바로 시작하는 것이라고 생각
 * 
 *      3. Latest start time
 *          : 해당 acitivity가 시작될 수 있는 가장 늦은 시간
 *          // 다음 vertex가 수행되어야할 최소 시간 전에 (due 안에) 수행을 시작하는 것  
 * 
 * 
 *          +) critical path는 E.time 과 L.time이 동일함, 바로바로 회전 시켜야함 
 */

