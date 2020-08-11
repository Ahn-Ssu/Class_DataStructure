#include <iostream>
#include <list>

using namespace std;

/**
 * List, container class 
 * 
 * < List class >
 *      : Sequential access(순차적으로, 순서대로)를 고려한 데이터 저장 형태
 * 
 *  
 *      #include <list>
 *          list <int>      a;
 *          list <double>   b;
 *          list <s_record> c;
 *              // empty list 생성 
 * 
 *  1. 특징
 *      - 양방향 순차적 access 허용  // 이 전것과 이 다음 것에 대한 접근(이동)만 가능 
 *      - [ ] 사용 불가
 *      - iteraotr 사용에 제약
 *          ㅣ ++, -- 연산 사용 가능
 *          ㅣ p = p + 3 ;(불가능) 
 *          ㅣ ==, != 사용 가능
 *          ㅣ >, < 사용 불가 (연속저장 공간이 아님)
 */
 *  for( p = a.begin(); p !- a.end() ; p++)
 *      cout << *p << endl;
 /* 
 * < member functions, list > 
 *      1. push_front() : 첫 위치에 원소 추가
 *      2. push_back() : 끝 위치에 원소 추가
 *      3. pop_front() : 끝 위치 원소 삭제
 *      4. pop_back() : 끝위치 원소 삭제
 *      ------------------------------------
 *      5. back() : 끝 위치 원소 읽
 *      6. front() : 첫 위치 원소 읽기
 *      7. begin(): 첫 원소 위치 (iterator)
 *      8. end() : 끝위치 (끝 원소의 다음 위치)
 *      9. clear() : 모든 원소 삭제 -> empty list로 
 *      10. empty() : empty 여부 check
 *      11. size() : 현재 원소 수
 *      12. insert() : 원소 추가 // vector 와 동일
 *      13. erase() : 원소 삭제
 * 
 * < 고유한 member functions, list class >
 *      1. push_front(), pop_front() : 벡터는 지원 x
 *      2. a.merge(b);
 *              - ordered list a 와 b 를 merge 하여 a 로 구성 
 *              - 수행 후 b는 empty로 됨
 *              - 입력이 ordered list가 아니면 error
 *              - key 값 중복 허용 
 * 
 *      3. a.remove(x);
 *              - 원소 중 x값 원소 삭제 ( 해당 type의 값에 대하여 == 연산 결과가 true면 삭제)
 *              - 해당 값의 원소가 여러 개이면 모두 삭제
 * 
 *      4. a.reverse();
 *              - 원소의 순서를 역순으로 재배열
 * 
 *      5. a.sort();
 *              - 원소의 값 순서로 sorting
 *              - 기본적으로 ascending sort
 *              - < 연산이 적용 가능한 원소이거나
 *              - user defined class 원소이면, < 연산자를 overloading 해야 함
 * 
 *      6. a.splice(p, b);
 *              - list a의 p 위치에 list b의 내용을 끼워 넣음
 *              - 연산 후 b는 empty가 됨
 */

void main(){

    list <int> a;
    list <int>:: iterator p;

    a.push_back(25);
    a.push_back(17);
    a.push_back(33);
    a.push_back(19);

    a.sort();

    for(p=a.begin();p!=a.end();p++)
        cout << *p << " : " ;
    cout << endl;

    // 17 : 19 : 25 : 33
}


/**
 * < operator overloading, 연산자 오버로딩 >
 *      : 표준 연산자(연산 기호) 를 user defined class object에도 사용 가능하도록 설정 
 */
class weight {
    int kg;
    int gram;
    weight operator+(const weight & t);
};

weight weight::operator+(const weight &t){

    weight tmp;

    tmp.kg = kg + t.kg;
    tmp.gram = gram + t.gram;

    if(tmp.gram >= 1000){
        tmp.kg += tmp.gram /1000;
        tmp.gram = tmp.gram % 1000;
    }

    return tmp;
}

int main2(){
    weight a,b,c;

    a.kg = 2;
    a.gram = 5000;
    b.kg = 3;
    b.gram = 700;
    
    c = a + b; // 뜻 : c = a.operator+(b);

    cout << c.kg << " kg and " << c.gram << "grams. " << endl;

    return 0;
}

// 예제 user defined class 를 원소로 하는 list의 sort 
// ->>> 부등호 연산자 오버로딩


class s_record {
public:
    string s_id;
    string name;
    double score;
    s_record();
    s_record(string s1, string s2, double n);

    bool operator<(const s_record & t);
};

bool s_record::operator< (const s_record &t){
    if(s_id<t.s_id)
        return true;
    else
        return false;
}


void main3(){

     list <s_record> a = { {"21900013", "Kim ", 6.5}, {"21900136", "Lee ", 8.8 }, {"21900333", "Park", 9.2 },
                                { "21800442", "Choi", 7.1}, {"21900375", "Ryu ", 5.4  }, {"21700248", "Cho ", 6.3 },
               { "21700302", "Jung", 8.3}, {"21800255", "Han ", 6.9  }, {"21800369", "Kang", 6.3 },
               { "21900401", "Yang", 9.1}, {"21800123", "Moon", 8.1  }, {"21700678", "Seo ", 7.9 } };

    a.sort();

    list <s_record>::iterator p;

    for(p=a.begin(); p!=a.end(); p++)
        cout << p->s_id << endl;

/* output
21700248~~~~ 무튼 정렬됨*/
}
// list class에는 sort가 되기때문에 vector와 사용의 구분이 명확함!