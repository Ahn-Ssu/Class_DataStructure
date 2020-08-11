/**
 *  Hashing - Overflow handling 
 * 
 * 
 * < Overflow handlig >
 *          1. Linear Open Addression ( = linear probing )
 *              - Hash table 의 해당 주소에 overflow 가 발생하면 -> "closest unfilled bucket"을 찾아서 그 곳에 넣는다.
 * 
 *          !유의사항!
 *              - 삭제된 공간으로 인한 search 과정의 오류 가능성 
 *                      : 초기      empty 공간과 deleted 공간을 구분할 수 있게 함 
 *              - clustering 문제 : 단점 
 *                      뭉쳐서 collision의 발생가능성을 높임 A,B,C 가 있으면 셋 중에 하나라도 충돌하면 점점 뭉탱이가 됨 
 * 
 *          2. quadratic probing 
 *              - overflow가 발생하면, 다음 순서대로 넣을 곳을 찾아 나감
 *                  f(k), ( f(k) + i^2 ) % b,  ( f(k) - i^2) % b,.... (1 <= i <= (b-1)/2 )
 * 
 *              - clustering 문제가 다소 해소 된다.
 *                  : 서로 다른 entry에서 시작된 search 과정은 그 경로가 달라짐.
 * 
 *          3. Rehashing 
 *              - b개의 hash function을 두어 순서대로 적용 
 *                  f1(k), f2(k), f3(k) .... fb(k)
 * 
 *              - table의 모든 entry를 채울 수 있도록 하는 문제가 고려되어야함 // b개의 함수는 다 썻는데 빈공간이 있는경우,,
 * 
 *          4. Chaining // 컴퓨터공학 -> linked List 
 *              - Table의 각 entry를 Linked list로 구성 
 *              - Key 값에 위치에 해당하는 linked list에 insert 
 * 
 *              - linear probing의 단점을 개선 
 *                      : 서로 다른 hash value를 생성한 원소들 간의 영향이 없음 
 * 
 *              // 최근에 저장한 것을 가장 많이 쓰게 된다는 것에 기반하여 
 *              // linked list의 경우는 앞에다가 연결하기 떄문에 서로 상호적이긴 하나 
 *              // 꼭! 의무는 아니여도 보통 저렇게 한다는 것을 알아야함. 
 * 
 * 
 * < Hashing : summary > 
 *      key 값으로 저장되어 있는 위치를 단번에 찾을 수 있는 direct addressing 의 장점이 있음 
 * 
 *      1. Loading density 
 *          a = n / s*b         (n : 저장된 원소 수
 *                               s : bucket 당 slot 수
 *                               b : bucket 수 )
 *          : loading density가 클 수록, 공간 활용도가 높으나 collision이 많이 발생 
 * 
 * 
 *      2. Hash table size의 결정 
 *          - too large : 공간의 낭비
 *          - too small : 성능의 저하, collision 발생 증가 
 * 
 *      3. Hash function의 요건(목표)
 *          - 신속한 계산
 *          - Collision의 최소화 
 * 
 *      4. Hash의 장점
 *          - search, insert, delete 연산이 효율적 
 * 
 *      5. Hash의 단점
 *          - worst case의 가능성 (동명이인이 계속해서 입력되는 경우, collision만 발생)
 *          - sorted order로 traverse 하는 기능이 어려움(key 값 순서로 조회, key 값의 범위로 조회 등)
 *          // 특정한 key 값을 찾는 것은 좋으나, key가 범위로 주어지거나 나열을 해야되는 경우에는 어려움.
 *          // Hash function을 적용할 대상을 못만듬,, 
 */