/**
 * Standard Template Library(STL) in C++
 *  C++ 에서 지원하는 라이브러리 
 *
 *  + 첨언
 *  교수님과 이번학기 내내 배운 data structure 는 이미 구현이 대부분 되어 있음
 *
 * 
 * < STL을 이용한 data structure and algorithm >
 *      - Template : type의 종류에 관계없이 (어떤 type의 data에도) 사용가능한 
 *                   data structure 또는 functions 
 *          // 틀을 만들어 놓고 사용할때 form을 지정 
 * 
 *      -STL(standart template library)
 *          : C++ 언어에서 지원되는 template library 
 * 
 *              a. containers : 안전하고 효율적인 data 관리
 *              b. algorithms : container 의 data에 적용하는 연산
 *              c. iterators : container 원소를 가리키는 pointer 기능 
 *
 * 
 * < Stack class >
 * 
 *  #include <stack> 
 *          : 선언시 원소 type 지정
 * 
 *      stack <int>      s1;
 *      stack <double>   s2;
 *      stack <s_record> s3;
 * 
 *          >>> empty stack이 자동으로 생성됨 
 * 
 * < member functions, stack class > // 대표적인 것만
 *      1. push() : 원소를 넣는 함수, void type 
 *      2. pop() : 원소를 삭제(만)하는 함수, ★void type임에 유의
 *      3. top() : 현재 top 위치의 원소를 읽는 함수
 *      4. size() : 현재 원소 개수를 return 
 */

using namespace std;

#include <iostream>
#include <stack>
#include <queue>


class s_record {
public:
    string s_id;
    string name;
    double score;
    s_record();
    s_record(string s1, string s2, double n);
};

void main(){
// 기본 primitive type 
    stack <int> s1;

    s1.push(3);
    s1.push(4);
    s1.push(5);

    s1.pop();

    int n1 = s1.top();
    int n2 = s1.size();

    cout << n1 << ", " << n2 << endl; // 4, 2 출력 

//------------------------------------------------------
// strucure로 구성함
    stack <s_record> s2; 
    s_record temp;

    temp.set_data("21900013", "Kim ", 6.5);
    s2.push(temp);
    temp.set_data("21900136", "Lee ", 8.8);
    s2.push(temp);
    temp.set_data("21800442", "Choi", 7.1);
    s2.push(temp);

    s1.pop();
    temp = s2.top();
    cout << s1.size() << endl; // 2 출력
    cout <<temp.s_id << endl;  // 21900136 출력


/**
 * < Queue class > 
 *      : 선언시 원소 type 지정
 * 
 *  #include <queue>
 *      queue <int> q1;
 *      queue <double> q2;
 *      queue <s_record> q3;
 * 
 * < merber functions, queue class > // 대표적인 것만
 *      1. push() : 원소를 넣는 함수, void type
 *      2. pop() : 원소를 삭제(만)하는 함수 
 *      3. front() : 현재 front 원소를 읽는 함수
 *      4. back() : 현재 back(rear) 원소를 읽는 함수
 *      5. size() : 현재 원소 개수를 return 
 *     
 */

    queue <s_record> q1;
    s_record temp;

    temp.set_data("21900013", "Kim ", 6.5);
    p1.push(temp);
    temp.set_data("21900136", "Lee ", 8.8);
    p1.push(temp);
    temp.set_data("21800442", "Choi", 7.1);
    p1.push(temp);

    q1.pop();

    temp = q1.front();
    cout << temp.name << endl; 
    temp = q1.back();
    cout << temp.name << endl;

}



