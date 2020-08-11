#include <iostream>
using namespace std;

class s_record{
    public: 
        string s_id;
        string name; 
        double score;
        s_record();
        s_record(string s1, string s2, double n);
    
};
!! heap sort 복습하면서 손으로 그려볼 것 !! 
/**
 * <Heap Sort>
 *      : complete tree
 *      : max tree (parent가 child 보다 큰 값을 가지는 것 ) -> array를 가짐 
 * 
 *      1. Algorithm
 *          초기 heap 구성
 *              - 다음을 (n-1)회 반복
 *                  i) heap 에서 첫 원소와 끝 원소의 위치를 교환
 *                  ii) heap의 size를 1 감소 시킴
 *                  iii) root를 기준으로 reheaping(adjust)
 * 
 *      힙의 루트 -> 저장된 값 중에 제일 큰 값, 큐에다가 제일 뒤에 넣고 재구성 
 *                   재구성한 루트를 다시 가져오고, 다시 재 구성하면
 *                  n번 가져오고, 재구성 할떄 log n 번 하니 n log n
 * 
 *      루프) root원소를 가져다가 맨 뒤에 놓고,  root가 잘못된 것을 재구성 
 */

// 1번째 원소부터(배운대로) 채워진 heap의 경우
void heap_sort(s_record a[], int n){ // 앞에서 구현할 때 루트는 1부터 기준 잡았음
    int i;
    s_record b[S_SIZE], temp;       // 그래서 배열 하나를 더 잡아서  

    for ( i = 0 ; i<n; i++)         // 1부터 n번째 까지로 위치 조정  0->1
        b[i+1] = a[i];

    for ( i = n /2; i > 0 ; i--)    // 주어진 입력에 대하여 heap '재'구성 
        adjust(b,i,n);
    
    for(i=n-1;i>0;i--){
        temp = b[1];
        b[1] = b[i+1];
        b[i+1] = temp;
        adjust(b,1,i);
    }
} 
// 0번째 원소부터 채워진 heap의 경우{}
void heap_sort2(s_record a[], int n){
    int i;
    s_record temp;

    int size = n-1;

    for ( i = (size-1) / 2 ; i >= 0 ; i--)
        adjust2(a, i, size);
    
    for ( i = size -1 ; i >=0; i--){ // 루트가 0인 것에 대해 주의!
        temp = a[0];
        a[0] = a[i+1];
        a[i+1] = temp;
        adjust2(a,0,i);
    }
} 
/** cf) 0번째 부터 시작되는 heap에서
 *      k번째 원소의
 *          parent = (k-1)/2
 *          left child = 2*k + 1
 *          right child = 2*k + 2
 */