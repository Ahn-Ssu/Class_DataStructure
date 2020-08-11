#include <iostream>
#include <cstdlib>

using namespace std;

/**
 * C 언어의 standartd library를 이용한 sorting 
 * 
 *      특별히 직접 sort 알고리즘을짜야하는 경우가 아니면 
 *      이미 있는(ex. lib) 알고리즘을 사용해서 (주: 함수) 하는게 더 안전하고 빠름
 * 
 * 
 * < C언어의 standard Library : qsort >
 *      특징 : 적용하는 array에 대해서 sort를 하는데 원소의 type에 상관없이 사용가능 
 * 
 *      - #include <stdlib.h>        : C언어 
 *          : #include <cstdlib>    : C++ 언어 
 * 
 *      - qsort( list, n, size, comp); 
 *          list : array의 이름 
 *          n : 원소의 갯수
 *          size : 원소의 단위 크기 
 *          comp : 비교하는 함수  // 이건 프로그래머가 구현하야하는 함수
 * 
 *          : 'list' 위치부터 'size'크기의 단위 원소 'n'개에 대하여,
 *            'comp' 라는 비교함수를 적용하여 quick_sort 수행 
 */
// ??void 타입 포인터 ?? = 아직 베이스타입이 결정되지 않은 포인터라는 것, 받는 쪽에서 캐스팅해서 의미부여를 함  
int comp(void *a, void *b){
    /**
     * (ascending sort:오름차순 위하여)
     * 'a가 가리키는 곳'이 'b가 가르키는 곳'보다 작으면 음수 (-1)
     * 'a가 가리키는 곳'이 'b가 가르키는 곳'보다 크면   양수 (+1)
     * 'a가 가르키는 곳'이 'b가 가르키는 곳'과 같으면  0을 return 
     *
     *  ! 비교 대상은 응용에 따라서 지정 ! 
     */

    return 1;
    return -1;
    return 0;
} 

/** 예제 1 
 * 
 *      - int 원소 10개의 배열 { 25, 32, 17, 24, 22, 41, 87, 33, 16, 44 }을 sort
 */

int main(){
    int t_list[10] =  { 25, 32, 17, 24, 22, 41, 87, 33, 16, 44 };

    qsort(t_list, 10, sizeof(int), compare); 

    for( int k = 0 ; k < 10; k++)
        cout << t_list[k] << endl ; 


    return 0 ;
}
// const는 변수에 사용하면 그 변수가 상수화 되어서 값을 수정할 수 없게 된다! 
int compare(const void *a, const void *b){
    int *p1 =(int *) a;
    int *p2 =(int *) b;

    if(*p1 == *p2)
        return 0;
    if(*p1 < *p2)
        return -1;
    if(*p1 > *p2)
        return 1; 
}
/** 
 * qsort를 사용할 때 해야하는 일!! 
 *      1. 함수를 정확하게 구현하는 것
 *      2. qsort를 부를 때 parameter를 정확하게 배치해주는 것 
 * 
 *      // 검증되었기 때문에 안전하고 빠름 
 */



class s_record {
public:
    string s_id;
    string name;
    double score;
    s_record();
    s_record(string s1, string s2, double n);
};

// { 학번, 성명, 점수} 의 class struct - Object array를 '학번' 순으로 sort  
int main_2(){
     s_record s_list[12] = { {"21900013", "Kim ", 6.5}, {"21900136", "Lee ", 8.8 }, {"21900333", "Park", 9.2 },
                                { "21800442", "Choi", 7.1}, {"21900375", "Ryu ", 5.4  }, {"21700248", "Cho ", 6.3 },
               { "21700302", "Jung", 8.3}, {"21800255", "Han ", 6.9  }, {"21800369", "Kang", 6.3 },
               { "21900401", "Yang", 9.1}, {"21800123", "Moon", 8.1  }, {"21700678", "Seo ", 7.9 } };


    qsort(s_list, 12, sizeof(s_record), compare_sid);
    //  배열할 리스트, 리스트의 크기(길이), 리스트의 form, 비교하는데 사용할 함수
    show_thelist(s_list, n);

    return 0;
}

int compare_sid(const void *a, const void *b){
    s_record *p1 = (s_record *) a;
    s_record *p2 = (s_record *) b;

    if(p1->s_id < p2->s_id)
        return -1;
    if(p1->s_id == p2->s_id)
        return 0;
    if(p1->s_id > p2->s_id)
        return 1;    
    // 앞에 있는 친구가 클때 1을 리턴하는 케이스는 오름차순 
    // 만약 내림 차순을 하고 싶으면 1과 -1의 return을 서로 교환하면 됨
}