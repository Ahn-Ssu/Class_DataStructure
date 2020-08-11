/**
 * Hashing 
 *  > Key 값을 갖는 원소를 저장
 * 
 * < Hashing >
 *      : Key 값에 어떤 연산을 적용하여 해당 key 값의 저장된 위치를 찾아 내는 방식 
 *          Key -> hash function(저장위치를지정/알아냄) -> hash table (저장공간)
 * 
 * 
 *      1. 용어
 *          - Hash table : 일정 갯수의 buckets으로 이루어진 연속적인 공간(key값을 갖는 원소가 저장되는 공간)
 *                          buckets : 개별공간의 단위,   연속적인~ 일련번호로 주소가 부여될 수 있음을 나타냄 
 *          - Hash function :   주어진 key와 hash table 상의 address를 mapping 하는 함수 
 *          - Collision : 서로 다른 key 값이 동일 bucket 주소로 mapping 되는 현상  (충돌)
 *          - Overflow : 어떤 bucket에 slot의 수보다 많은 수의 원소가 저장되려 할 때  (collision이랑 관계가 있음) // bucket의 수용량이 한개가 아닐 수도 있음 
 * 
 * 
 * 
 * < Hashiing : 예제 >
 *      : Key 값 k의 집합, { 3, 5, 10, 2, 6, 9 } 에 대하여 다음 hash function을 적용
 *                  F(k) = (k*3)%7; 
 * 
 *                  -------------------
 *                      3  ->  2   C
 *                      5  ->  1
 *                      10 ->  2   C
 *                      2  ->  6   C
 *                      6  ->  4
 *                      9  ->  6   C
 *                  -------------------
 * 
 *      1. Hasing 의 구현에 관한 issues
 *          - Hash function design
 *          - overflow handling method  (일관된)
 * 
 * < Hash Functions >
 *      1. Hash function의 요건
 *          - easy to compute   // 애초에 시간을 절약하기 위해서 만든 것인데, 계산이 복잡하다면 collision 이 덜 나도 소용이 없음 
 *          - minimize the number of collisions 
 * 
 *      2. 개념 (특징)
 *          - mid - square
 *                  :주어진 key값을 제곱한 결과에서 중간의 일정 수 bit를 선택 
 *                      ex) 010[111100101]011010 -> [111100101] 선택된 비트들 
 * 
 *          - folding
 *                  : key 값의 2진수 string을 몇 개의 part로 나누고, 겹쳐서 덧셈 
 *                      ex) 11010/00101/11101 
 * 
 *          - division
 *                  : modulus operator (%) 사용
 *                      ex) f(k) = k % M (M 값은 table size) 
 *                              // M값의 선택 : 2의 제곱수는 좋지 않다. 
 *                                      -> prime number 또는 20 이하의 정수로 나누어 지지 않는 수 
 * 
 *          - analysis ( digit analysis )
 *                  : key  값을 임의의 진수로 변환한 수, 적절한 digit을 선택
 *                    static file인 경우에 유용 // 규격화 된 데이터!
 *                    모든 key 값의 형태를 사전에 알 수 있는 경우 
 * 
 *                    ex) 학번 뒷자리 
 * 
 */