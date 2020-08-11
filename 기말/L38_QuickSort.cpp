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

/**
 * < Quick sort >
 *      1. Algorithm ( a recursive algorithm )
 *          pivot -> 기준원소 
 *          pivot을 기준으로  큰 것은 뒤로, 작은 것은 모두 앞으로 보냄 
 *          수행 후, 주어진 데이터가 작은 두개의 그룹으로 나뉨 
 * 
 *          두개로 나누어 수행함으로 logn 
 *          이것을 n번 수행함으로 "n log n"
 * 
 *          a. 대상 범위의 원소수가 1 이하이면 return
 *          b. 대상 범위의 첫 원소를 기준 원소(pivot)로 하여
 *              i) pivot 보다 key key 값이 큰 원 소는 뒤로, 작은 원소는 앞으로 이동하여 
 *                 list를 분리 ( = partitioning )
 *          c. 앞 부분과 뒷 부분을 다시 quick sort 실행
 */

void quick_sort(s_record a[], int left, int right){
    s_record pivot, temp;
    int i, j;

    if(left >= right ) return ;

    i = left;
    j = right + 1;
    pivot = a[left];
    do{
        do{
            i++;
        }while ( (i <= right) && ( a[i].s_id<pivot.s_id) );
        do{
            j--;
        }while ( a[j].s_id > pivot.s_id );

        if(i<j)
            swap(a[i],a[j]);

    }while ( i< j);

    swap( a[left], a[j] );                  // swap 함수는 알아서 구현이 되어 있음. ..
    quick_sort(a, left, j-1);
    quick_sort(a, j+1 ,right);
}

/**
 *     [해석]
 *      1. 왼쪽 끝 원소를 pivot으로 취한다
 *      2. 그보다 큰 것을 만나면 멈춘다 
 *      3. 뒤에서 작은 것을 만나면 멈춘다
 *      4. 2,3 서로 교환
 *      5. i와 j가 서로 교차하면 뒤에서 온 j원소랑 pivot을 교환한다. 
 * 
 * < Algorithm efficiency > : 여러가지 sorting 알고리즘 중에 가장 평균적 특성이 좋은 알고리즘 
 *      1. 평균 : O ( n log n) 
 *      2. Worst case : O(n^2)
 *          - 이미 sort 된 list (또슨 역순으로 sort된 list) 가 입력 될 때
 * 
 *      - 개선 방안!
 *          1. 중간 위치의 원소를 pivot 으로 선택
 *          2. 첫 원소, 중간 위치 원소, 끝위치 원소 중 중간 값을 pivot으로 선택
 *                  median-left ( median-of_three)
 * 
 * 
 *    +) 비교와 교환으로 이루어지는 sort 방식에서 
 *          최적의 time complexity 는 O( n log n) 이다. // 수학적으로 증명이 되어 있음 
 * 
 */
