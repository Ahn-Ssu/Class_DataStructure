#include <iostream>
using namespace std;

/**
 *  < Sorting >
 *      : 주어진 일련의 원소를 'key'값의 크기 순서로 나열하는 것
 * 
 *      1. 종류
 *       ★ a. ascending sort : key 값이 작은 순서로 나열 // 이번학기에는 이게 중심
 *          b. descending sort : key 값이 큰 순서로 나열 
 * 
 *      2. Sorting의 필요성 
 *          : 다량의 데이터를 다루는 다양한 응용에서 필요 
 *          ex) search를 용이하게 함
 *              list validation  // 내용 상호 검증(확인)
 * 
 *  < Sorting의 응용, 예시 : Searching >
 *      Searching : sequential search ( = linear search ) // 첫번째부터 찾을떄까지 다음을 탐색하는 것
 *          - 주어진 array의 n개 원소 중, key 값이 k인 원소를 찾는 문제.
 *              원소의 위치(index)를 return, 해당 key 값이 없으면 -1 return; 
 */
int sequential_search(element a[], int k, int n ){
    int j = 0;                              // a[n].key = k : 없는 index
    while ( (j<n) && < (a[j].key != k) )    // while (a[j].key != k ) : 공간 하나를 더 투자하면 검색을 안함 
        j++;
    if(j>=n)
        return -1;
    return j ;
} // linearSearch 의 예, O(n) 
    // cf) binarySearch -> sorting을 먼저, O(log n)
/**
 * < Searching : binary search >
 *      ★주어진 배열이 sort 되어 있을 때 적용 가능
 * 
 *      +) binary search 자체는 많아야 1/2 씩만 찾으면 되기 때문에 O(log n) 이긴 하나
 *          이것은 이미 sort 가 되어있는 상황에서의 전제이므로 sort가 되지 않은 데이터라면
 *          O(nlog n) 이다. sorting algorithm은 o(n) 이기 때문 
 * 
 *      따라서 데이터를 읽는 횟수가 적은 경우에 O(n) 이 좀 더 나은 경우도 있다. 
 */
int binary_search(element a[], int k, int left, int right){
    int middle;
    while (left <=right){
        middle = (left + right) /2;     // 중간 값으로 지정 
        if(a[middle].key==k)
            return middle;
        if(a[middle].key > k)           // 크기에 따라 옆으로 한칸
            right = middle -1 ;
        if(a[middle].key < k)
            left = middle +1;
    }
    return -1 ;
}
/**
 * < Sorting의 응용 : List validation >
 *      :두개의 배열 ( a[], b[] ) 내용에 대하여 다음 3가지의 불일치를 판별
 *          a. a에는 있으나, b에는 없는 원소
 *          b. b에는 있으나, a에는 없는 원소
 *          c. a, b에는 모두 있으나, 내용이 서로 다른 원소 
 * 
 *      i) 일반적으로 a, b가 모두 무작위 순서라면 -> O(n^2) 
 *      ii) a, b가 sort 되어 있다면 -> O(n) 
 *              : sort 시간이 O(nlogn)이라면 O(n^2) 보다는 유리함 
 * 
 * < Sorting algorithm >
 *      O(n^2)
 *      1. Insertion sort
 *      2. Selection sort
 *      3. Bubble sort
 * 
 *      O(nlogn)
 *      4. Quick sort
 *      5. Merge sort
 *      6. Heap sort 
 *
 * 
 * < Insertion sort >
 *      :배열 원소의 순서대로 다음을 반복
 *          i) 현위치 보다 앞쪽에서 자신보다 큰 값을 뒤로 이동,
 *          ii) 더 이상 큰 값이 없거나 맨 앞 위치에 도달하면 그곳에 원소를 넣음 
 * 
 *      Q. 왜 O(n^2) 인가요??
 *          n개의 원소에 대해서, sorting 할때마다 한개 취하면 n-1 개, 하나 더 취하면 n-2 개 
 *          이렇게 되는 것은 n^2 입니다. n번씩 n-1, n-2, n-3 .... 
 * 
 * Programming 실습 
 *      : 다음과 같은 구조의 원소를 '학번' 순서로 sorting
 */
class s_record{
    public: 
        string s_id;
        string name; 
        double score;
        s_record();
        s_record(string s1, string s2, double n);
    
};


void insertion_sort(s_record a[], int n){
    for( int j =1; j<n; j++){
        s_record temp = a[j];
        int k = j-1;
        while ( (k>=0)&&(a[k].s_id > temp.s_id) ){
            a[k+1] = a[k];
            k--;
        }
        a[k+1] = temp;
    }
}
/**
 * < Insertion sort 개선 > ! 참고
 *      1.원소의 비교 연산 횟수 개선
 *          - binary insertion sort : 원소를 넣을 위치를 찾을 때, binary search 과정 사용
 *      2. 원소의 이동 연산 시간 개선
 *          - linked insertion sort : linked list 로 유지하여, 주변 원소 값 이동 없이 insert 연산 가능
 *  // 그러나 완벽한 개선은 아니기 때문에 참고적 지식으로만 알고 있기를 바람 
 */