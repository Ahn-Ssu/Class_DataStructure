#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

/**

< Counting >
    1. count() : 주어진 범위의 원소 중, 특정 값을 갖는 원소의 갯수
    2. count_if() : 주어진 범위의 원소 중, 특종 조건에 맞는(함수 별도 지정해서) 원소의 개수 

*/

int b[10] = { 91, 88, 77, 52, 80, 67, 77, 85, 94, 77 };

vector <int> a ;
for(int k=0; k < 10 ; k ++)
    a.push_back(b[k]);

int n1 = count(a.begin(), a.end(), 77); 

cout << n1 << endl;  // 3 출력 


// count_if() 예제

bool high_score(s_record t){
    return( t.score >= 8.0);
}

int main (){
    vector <s_record> s_list ;

    int n1 = count_if( s_list.begin(), s_list.end(), high_score );

    cout << n1 << endl; // 출력 5 

    return 0 ;
}


/**
< reverse() >
    reverse(p1, p2); 
            : [p1, p2) 범위 원소 순서를 역순으로 재구성 
*/

int b[10] = { 91, 88, 75, 52, 80, 67, 73, 85, 94, 77 };
vector <int> a;
for( int k = 0 ; k < 10 ; k ++)
    a.push_back(b[k]);

reverse( a.begin(), a.end() );


for ( unsigned int j = 0 ; k< a.size() ; j ++)
    cout << a[j] << " : ";
cout << endl;

/** 말 그대로 그냥 반대로 출력
출력 값 
 77 94 85 73 67 80 52 75 88 91 



<make_heap()>
    make_heap (p1, p2);
            : [p1, p2) 범위의 내용을 heap으로 구성
*/

int b[10] = { 91, 88, 75, 52, 80, 67, 73, 85, 94, 77 };
vector <int> a;
for( int k = 0 ; k < 10 ; k ++)
    a.push_back(b[k]);

make_heap( a.begin(), a.end() );


for ( unsigned int j = 0 ; k< a.size() ; j ++)
    cout << a[j] << " : ";
cout << endl;
/**
<for_each()>
    for_each (p1, p2, proc:함수내용);
            : [p1, p2) 범위의 각 원소에 대하여 proc() 함수를 적용
*/
void convert(int &t){
    if(t>90) t = 100;
    if(t<60) t = 0;
}
int b[10] = { 91, 88, 75, 52, 80, 67, 73, 85, 94, 77 };
vector <int> a;
for( int k = 0 ; k < 10 ; k ++)
    a.push_back(b[k]);

for_each( a.begin(), a.end(), convert );
//데이터를 일괄 처리할 떄 유용한 것 

for ( unsigned int j = 0 ; k< a.size() ; j ++)
    cout << a[j] << " : ";
cout << endl;
// 100 88 75 0 80 67 73 85 100 77 

/**
<replace()>
    replace(p1, p2, x1, x2);
            :[p1, p2) 범위의 원소 중, x1을 x2로 변경
*/
int b[10] = { 91, 88, 75, 52, 80, 67, 73, 85, 94, 77 };
vector <int> a;
for( int k = 0 ; k < 10 ; k ++)
    a.push_back(b[k]);

replace (a.begin(), a.end(), 80. 85 );


for ( unsigned int j = 0 ; k< a.size() ; j ++)
    cout << a[j] << " : ";
cout << endl;
// 91 88 75 52 '85' 67 73 85 94 77 

/**
 * < copy () >
 *      replace(p1, p2, p3);
 *              :[p1, p2) 범위의 내용을 p3 위치로 copy 
 */
int b[10] = { 91, 88, 75, 52, 80, 67, 73, 85, 94, 77 };
vector <int> a1, a2(5);
for( int k = 0 ; k < 10 ; k ++)
    a1.push_back(b[k]);

copy (a1.begin(), a1.begin()+5, a2.begin() );


for ( unsigned int j = 0 ; k< a.size() ; j ++)
    cout << a[j] << " : ";
cout << endl;
// 오브젝트가 달라도 iterator를 이용하여 옮길 수 있음 
// 91 88 75 52 80 

/**
 * < remove_copy() >
 *      remove_copy( p1, p2, p3, x); 
 *              :[p1, p2)  범위의 내용 x를 제외한 내용을, p3 위치로 copy 
 */
int b[10] = { 91, 88, 75, 52, 80, 67, 73, 85, 94, 77 };
vector <int> a1, a2(10);
for( int k = 0 ; k < 10 ; k ++)
    a1.push_back(b[k]);

copy (a1.begin(), a1.end(), a2.begin(), 77);


for ( unsigned int j = 0 ; k< a.size() ; j ++)
    cout << a[j] << " : ";
cout << endl;
// 91 88 52 80 67 58 94 0 0 0 

/**
 * < replace_copy() >
 *      replace_copy(p1, p2, p3, x1, x2);
 *              :[p1, p2) 범위의 내용 중, x1을 x2로 변경하여, p3위치로 copy
 */
int b[10] = { 91, 88, 75, 52, 80, 67, 73, 85, 94, 77 };
vector <int> a1, a2(10);
for( int k = 0 ; k < 10 ; k ++)
    a1.push_back(b[k]);

replace_copy (a1.begin(), a1.end(), a2.begin(), 77, 100);


for ( unsigned int j = 0 ; k< a.size() ; j ++)
    cout << a[j] << " : ";
cout << endl;
// 91 88 100 52 80 67 100 85 94 100

/**
 * < transform() >
 *      : transform ( p1, p2, p3, proc);
 *              : [p1, p2) 범위 원소에 대하여, proc() 함수를 적용한 결과 값(return 값)을 p3에 저장
 */

int convert(int t){
    return (t + 5) ;
}
int b[10] = { 91, 88, 75, 52, 80, 67, 73, 85, 94, 77 };
vector <int> a1, a2;
for( int k = 0 ; k < 10 ; k ++)
    a1.push_back(b[k]);

transform (a1.begin(), a1.end(), a2.begin(), convert);
//for_each랑 유사하지만 차이점이 있음, proc 적용 vs proc 적용 값을 적용 

for ( unsigned int j = 0 ; k< a.size() ; j ++)
    cout << a[j] << " : ";
cout << endl;

/**
 * < unique_copy () >
 *      unique_copy(p1, p2, p3);
 *              : [p1, p2) 범위의 내용 중 연속하여 같은 값이 나타나는 원소는 한 개로 고려하여 p3 위치로 copy
 */

int b[10] = { 91, 91, 75, 88, 88, 88, 77, 77, 94, 94};
vector <int> a1, a2(10);
for( int k = 0 ; k < 10 ; k ++)
    a1.push_back(b[k]);

unique_copy (a1.begin(), a1.end(), a2.begin());


for ( unsigned int j = 0 ; k< a.size() ; j ++)
    cout << a[j] << " : ";
cout << endl;
// 91 75 88 77 94 0 0 0 0 0 0
// 전체 학부 가짓수출력 

/**
 * < random_shuffle() >
 *      random_shuffle (p1, p2);
 *              : [p1, p2)  범위의 내용을 무작위 순서로 바꿈 
 */
int b[10] = { 0 ,1 ,2 ,3, 4, 5, 6, 7, 8, 9 };
vector <int> a
for( int k = 0 ; k < 10 ; k ++)
    a.push_back(b[k]);

transform (a.begin(), a.end());

for ( unsigned int j = 0 ; k< a.size() ; j ++)
    cout << a[j] << " : ";
cout << endl;

/**
 * < STL : algorithms >
 *      - 총 60종류 이상의 다양한 algorithm 지원 
 *      - iterator의 사용으로 대상 데이터 지정이 용이 
 *      - 각 algorithm (function) 은 
 *              a. functions overloading과 default parameter 의 사용으로 다양한 call형식 지원
 *              b. parameter 형식에 따라 다양한 의미의 연산을 수행 
 */
     
