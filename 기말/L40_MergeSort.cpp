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
 * < Merge Sort >
 *      : 두 개의 sorted list를 병합하여 한 개의 sorted list 생성 
 * 
 *      1. Merge sort 
 *              : 전체의 길이가 s 인 sorted list가 연속된 형태로 고려하여, 
 *                두 개의 list를 한 개로 merge 하는 과정을 반복
 *                  i) s를 1로 시작하여 2배로 증가 시켜 반복
 *                  ii) s가 전체 길이가 되면 종료 
 * 
 *              ex) 15 11 8 14 5 12 19 17               // s =1 
 *                  [11,15] [8,14] [5,12] [17,19]       // s =2
 *                  [8,11,14,15] [5,12,17,19]           // s =4 
 *                  [5,8,11,12,14,15,17,19]             // s =8
 */
// Merge 연산 구현
void merge(s_record a[], s_record b[], int n1, int n2, int n3, int n4){
    int i,j,k,t;

    i=n1;
    j=n3;
    k=n1;

    while( (i<= n2) && (j<=n4)){ // 한 파티션이 고갈되면 멈춤
        if(a[i].s_id<=a[j].s_id) 
            b[k++]=a[i++];
        else
            b[k++] = a[j++];
    }
    if(i>n2)
        for(t=j; t<= n4; t++)   // 앞쪽이 고갈된 상황
            b[t]=a[t];
    else
        for(t=i;i<=n2;t++)      // 뒷쪽이 고갈된 상황 
            b[k+t-i] = a[t];
}
/** 
 * < Algorithm Merge > 
 *      : Size(s)를 1부터 시작하여 2배로 증가시키며 다음을 반복
 *          i) 주어진 list를 크기 s의 subList로 고려하여 2개씩 merge
 *          ii) s가 전체 크기가 될 때 까지 반복 
 * 
 *      1. 고려사항
 *          i) 주어진 list의 크기가 s의 정수배로 결정되지 않을 때 마지막 segment의 처리
 *          ii) 주어진 list를 merge한 결과를 저장하는 공간
 *                  : 주어진 list와 동일 크기의 공간을 선언하여 반복과정마다 번갈아 저장 
 *                      원래 사용했던 배열도 다시 다음번에 사용, 번갈아가면서 배열 2개를 통해 merge 
 * 
 * < Merge Sort 구현 >
 *      : ex. 3단계로 고려하여 3종류의 function으로 구현 
 * 
 *          1. merge_sort()
 *              - 주어진 list를 sort하는 function
 *              - s를 1부터 시작하여 2배씩 증가시키면서 merge_pass를 call
 * 
 *          2. merge_pass()
 *              -  주어진 list를 길이 s의 연속된 subList로 고려하여 2개씩 merge하여 
 *                  새로운 list 생성
 * 
 *          3. merge()
 *              - 주어진 두 개의 sorted list를 merge 하는 function. 
 */
void merge_sort(s_record a[], int n){
    int s = 1;
    s_record b[S_SIZE];

    while (s<n){
        merge_pass(a,b, n-1, s);
        s*=2;
        merge_pass(b,a,n-1,s); // 1회차에서 n을 넘는 경우에 a[]에 돌려줘야 하기 때문에 한번 더 수행 
        s*=2; 
    }
}

/**
 * < Merge Pass 구현 >
 *      : 주어진 list(a)의 n개 원소에 대하여, 길이 s 단위로 merge 하여 새로운 list(b) 생성
 * 
 *      1. 알고리즘
 *          i) a의 첫 위치부터 길이 s의 subList가 두개 미만의 길이가 남을 때까지, 두개 씩 merge하여 b를 생성
 *          ii) 남은 list의 길이가
 *                  s보다 크면 -> 두 sublist를 merge
 *                  s보다 작거나 같으면 -> 남은 내용을 그대로 copy 
 */

void merge_pass(s_record a[], s_record b[], int n, int s){
    int i, j;
    
    //온전히 두쌍이 페어가 될때 이 for에서 처리
    for(i=0; i<(n-2*s +1); i+=2*s) // 2*s + 1 : 두개 미만이 될 때 까지 
        merge(a,b,i,i+s-1,i+s,i+2*s-1);
    //두쌍이 미만이 되어 한쌍남짓 있는 경우 이 쪽에서 처리
    if( i + s <= n) // i에서 끝까지 갔는데, s만큼 건너 뛰어도 n보다 작은 경우에!
        merge(a,b,i,i+s-1,i+s,n);
    else// 한개 미만인 경우 그냥 처리 
        for (j=i;j<=n;j++)
            b[j] = a[j]; 

}

