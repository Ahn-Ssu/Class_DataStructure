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
 * < Bubble sort >
 *      : 배열 원소의 순서대로 다음을 반복
 *          1. 인접한 두 원소를 비교, 앞쪽이 크면 교환
 *          2. 범위를 1씩 감소시키며 반복       .
 */
void bubble_sort(s_record a[], int n){
    s_record temp;

    for (int j = n-1; j >= 1 ; j --){
        for ( int k=0; k <j; k++)
            if(a[k].s_id > a[k+1].s_id){
                temp = a[k];
                a[k] = a[k+1];
                a[k+1]=temp;
            }
    }
};

/** < Selection sort > 
 *      :배열 원소의 순서대로 다음을 반복
 *          1. 대상 범위에서 가장 작은 값을 찾아
 *          2. 대상 범위의 첫 원소와 교환 
 */
void selection_sort(s_record a[], int n){
    s_record temp;
    for (int j = 0 ; j < n ; j++){
        int min_i = j;
        for ( int k = j +1 ; k < n; k++)
            if(a[k].s_id < a[min_i].s_id)
                min_i = k;
            temp = a[j];
            a[j] = a[min_i];
            a[min_i] = temp;
    }
}