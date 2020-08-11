/**
 * < Selection tress >
 * 
 * 1. 필요성
 *   k 개의 ordered sequence를 한 개의 ordered sequence로 merge(합병)하는 문제 
 *    (k개의 무더기/데이터가 있는데 각각은 이미 정렬되어 있는 상태, 
 *      이것을 모두 결합해서 하나의 정렬된 리스트를 만들자는 것 )
 * 
 * 2. 알고리즘 
 *      k개의 run에서 가장 작은 값을 찾는 과정을 n회 반복  
 * 
 *      1) linear search -> (k-1) 회 비교 : O(k) 
 *      2) selection tree로 구성하는 경우 : O(log k)
 * 
 *  3. 트리 종류 
 *   A. Winner tree 
 *      각 sub tree에서 값(key)를 비교 하여 작은 값을 root의 방향으로 올라감 
 *  
 *   B. Loser tree 
 *      prof) winner 트리랑 동일하게 승부하는 로직은 동일함, 작은 사람이 이기는 것이고 
 *      큰 값을 가진 쪽이 졌고, 승부에서 '진' 값을 parent로 올리는 것! 승부 로직, 결과와 올라가는 것은 다름 
 *      
 *      Q. 왜 이렇게 구현을 했는가??
 *          다시 작업을 할때, 새로운 원소는 child 끼리가 아니고 child와 parent 와 비교할 수 있는 효율이 있음 
 * 
 * 개념 정확히 알고 있을것
 * 
 * < Counting binary trees >
 *      N개의 node로 이루어진 ninary tree 의 형태는 총 몇가지 인가??? 
 *     
 *      +) N개의 원소로 이루어진 stack permutation 문제 
 *      ex) 3 개의 원소에 대한 stack permutation {1,2,3} 
 *             
 *              1,2,3/1,3,2/2,1,3/2,3,1/3,2,1      -> 5개
 *          
 *      +) N+1 개의 matrix(행렬)를 곱하는 방법의 수 
 *      ex) 4 개 ( 3 + 1) 의 matrix를 곱하는 방법의 수  = > 괄호의 묶일 수 있는 조합의 갯수는 ?
 *                                          -> 5개 
 * 
 *      ! 이 세 문제 모두 같은 문제임 
 * 
 *      다음 3가지의 문제는 서로 equivalent한 문제이다.
 *      1. n개의 node로 이루어진 binary tree의 형태는 총 몇 가지 인가?
 *      2. n개의 원소로 이루어진 stack permutation 문제 
 *      3. n+1개의 matrix를 곱하는 방법의 수 
 * 
 *          답 :  1/(n+1) * 2n C n          
 *    
 *          !!! 컴공에서 외워라 라고 하는 경우는 없는데 이것은 외우기를 권장!!!     
 */      