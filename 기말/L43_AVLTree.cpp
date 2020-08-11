/**
 * Binary Search Tree의 특수한 케이스 
 *  Key - search의 효율성을 지원하는 것
 * 
 * <AVL search Trees>
 * 
 *  1. 정의
 *      Binary Search Tree 제약을 동시에 만족해야함.
 *          - left subtree에 속한 모든 node의 key 값은 root의 key 값보다 작고
 *          - right subtree에 속한 모든 node의 key 값은 root의 key 값보다 크다
 * 
 *      Height-Balanced tree (AVL 의 추가적인 제약 조건)
 *          - left subtree와 right subtree의 height의 차이가 1보다 같거나 작다.
 *          //왼쪽과 오른쪽의 차이를 줄여서, search 시간을 O(logn)에 준하게 셋업하는 것
 * 
 *      Balance facotr
 *          -Left subtree의 height - right subtree의 height 
 *              > ABL tree는 모든 node의 balance factor 는 { -1, 0 , 1 } 중의 하나 
 * 
 * < 원소의 추가 연산 >
 *          - Binary Search Tree에서 원소 추가 연산과 유사
 *          - 원소 추가 후 tree의 형태가 balanced tree조건이 위배 되면!!
 *              : Tree의 구조를 balanced tree가 되도록 수정함 
 * 
 *          Unbalanced tree의 판단
 *              - imbalance 가 발생한 "minimal subtree"에 대하여 다음의 4가지 형태를 구분
 * 
 *          [minimal subtree의 root를 기준으로 하여]
 *              a. Left subtree의 Left가 길어진 경우 : LL type
 *              b. Left subtree의 right가 길어진 경우 : LR type
 *              c. Right subtree의 left가 길어진 경우 : RL type
 *              d. Right subtree의 right가 길어진 경우 : RR type
 *          // 타입별로 교정 
 *          // 불균형이 발생한 것이 루트일 수도 아니면 루트의 sub tree 일 수도 있기 때문에 유심히 봐야함 
 * 
 *     !주의사항!
 *          1. RL - type 
 *              : minimal subtree기준으로 판단
 * 
 *          2. RR - type
 *              : root와, 그의 좌우 child node 를 기준으로 길어진 위치를 판단
 * 
 * < Unbalanced tree -> balanced tree 변환 >
 *          - Rotate 연산
 *              : imbalance 가 발생한 반대 방향으로 rotate 
 * 
 *          (일치한 방향의 unB는 발생한 방향의 반대방향으로 수행)
 *          1. LL type
 *              - root 기준으로 right-rotation
 *          2. RR type
 *              - root 기준으로 left-rotation 
 * -----------------------------------------
 *          3. LR type (아랫쪽을 먼저 해결하고 윗쪽을  해결하면 됩니다)
 *              - Right sub tree 기준으로 left-rotation
 *              - root를 기준으로 right-rotation
 *          4. RL type
 *              - left sub tree 기준으로 right-rotation
 *              - root를 기준으로 left-rotation 
 * 
 * 
 *      예제) 정수(int) Key를 갖는 AVL tree의 초기 empty 상태에서,
 *            원소 { 11, 15, 20, 5, 3, 9, 7, 10, 8 } 가 순서대로 입력 된 후 
 *            Tree의 형태를 보이시오 
 * 
 * 
 * 
 * 
 *          //rotation은 말 그대로 기준 root 방향으로 친구들이 한칸씩 밀리는 것
 */