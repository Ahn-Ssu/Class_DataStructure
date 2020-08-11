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
 * <Radix Sort>
 *      : Sorting on Several Keys
 *          - 여러 개의 key에 대하여 sort
 *          - Key의 종류에 우선 순위
 * 
 *      ex) 학생 명단을 sorting
 *          - 학부 > 성명 > 학번
 *            학부 순으로 정렬하고, 
 *            동일한 학부에서는 성명 순 
 *            동명이인은 학번 순으로 
 * 
 *          most significant key -> '학부'
 *                   ...
 *          Least significant key -> '학번'
 * 
 * 생각) 그룹을 3중으로 나눈 것 
 * 경경 -> 국제 -> 기계 의 학부 그룹 정렬 
 * 학부 내에서 학부생의 이름으로 그룹 정렬
 * 이름이 같은 경우에는 학번 순서로 정렬
 * 
 * <Sorting on several keys : 예제 >
 *      : 학생 명단을
 *        학부 순 ( 동일 학부에서는 학번 순)으로 sort 
 * ---------------------------------------------
 *      1. most significant key에 대하여 먼저 sort 
 *          - 전체 명단을 학부별로 분리
 *          - 각 학부별 명단을 학번 순으로 sort 
 *          - 각 file 을 학부 순서대로 한 개로 결합 
 * 
 *      2. least significant key에 대하여 먼저 sort 
 *          - 전체 명단을 학번 순으로 sort 
 *          - 각 원소를 순서대로 학부 별 queue에 넣음 
 *          - 학부 순서로 queue의 내용을 한 개로 결합 
 * 
 * ---------------------------------------------
 * 
 * <Radix Sort>
 *      : 일정 자릿수의 int 값을 key로 할 때, 각 자릿수를 서로 다른 key로 고려할 수 있음 
 * 
 *      ex) 4자리 정수를 key로 하는 데이터의 sort 문제
 *          { 3258, 2143, 3920, 5627, 3342 ...}
 * 
 *              3   2   5   8
 *              k1  k2  k3  k4
 * 
 *      천 단위 자리수 -> most significant digit (MSD) 3258 
 *      일 단위 자리수 -> least significant digit(LSD) 3258
 * 
 * 
 * <Radix Sort  : 두 가지 방법>
 * 
 *      1. MSD (Most Significant Digit) sort
 *          MSD 우선 순서로 적용하여 sort하는 방법
 * 
 *      2. LSD (Least Significant Digit) sort 
 *          LSD 우선 순서로 sort하는 방법 
 * 
 * 
 * < MSD sort : 예제 >
 *      - 3자리 정수 key 값을 갖는 배열
 *          { 357, 88, 259, 724, 130, 825, 532, 212, 313, 678, 159, 53, 442, 253}
 * 
 *      1. MSD sort algorithm
 *          a. 각 원소에 대하여 백단위 digit를 기준으로 10개의 배열로 구분 
 *          b. 각 배열 원소에 대하여 십단위 digit 기준 10개의 배열로 구분
 *          c. 각 배열을 sort( 또는 1단위 기준으로 다시 구분 )
 *          d. 각 배열을 순서대로 결합하여 전체를 한 개로 결합하면 종료 
 * 
 * < LSD sort : 예제 >
 *      - 3자리 정수 key 값을 갖는 배열
 *          { 357, 88, 259, 724, 130, 825, 532, 212, 313, 678, 159, 53, 442, 253}
 * 
 * 
 *      1. LSD sort algorithm
 *          a. 각 원소에 대하여 1단위 digit를 기준으로
 *                  : 10개의 queue에 넣고, 전체를 재구성
 *          b. 각 배열 원소에 대하여 십단위 digit 기준으로
 *                  : 10개의 queue에 넣고, 전체를 재구성
 *          c. 각 원소에 대하여 백단위 digit를 기준으로
 *                  : 10개의 queue에 넣고, 전체를 재구성        
 * 
 */
