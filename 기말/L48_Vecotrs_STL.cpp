/**
 * Vectors 
 *  - STL 에서 가장 많이 사용되는 container class 
 * 
 * < Vector class >
 *      : 임의 type의 원소를 저장할 수 있는 dynamic array 
 *      // 타입 어떤것이든, 크기는 유동적인 점이 장점 
 * 
 *          - 원소 개수 제약의 없음 -> 수시로 자동 relocation (알아서 위치 조정 후 재구성) 
 *          - 원소의 type 제약이 없음
 *          - indexing 기능(연속공간의 할당) : array의 장점 - index로 바로 접근이 가능함 
 *          - ★끝위치에 insert, delete가 효율적
 *          - 중간 위치 insert/delete가 비효율적 
 *          - 원소 개수가 증가하면 relocation(메모리 위치 재조정) 발생 -> iterator 사용에 유의
 * 
 * 
 *      #include <vector>
 * ------------------------------------------------
 *          vector <int>       a;
 *          vector <double>    b;
 *          vector <s_record>  c; 
 * 
 *              //별도의 표기 없이 생성하면 
 *              // empty vecotr 가 생성이 됨 
 * 
 * ------------------------------------------------
 *          vecotr <int> a(5);      // 원소 5개를 갖는 vector a 
 *          vector <int> a(5, 0);   // 원소 5개를 0으로 초기화
 *          vecotr <int> a(b);      // vecotr b와 동일 내용을 갖는 a 생성
 * 
 *              // overloading 되어 있어서 필요에따라 알맞게 구현
 *              //
 * 
 * < member functions, vecotr class >
 *      1. push_back() : 끝 위치에 원소 추가
 *      2. pop_back() : 끝 위치 원소 삭제
 *      3. back() : 끝 위치 원소 읽기
 *      4. front() : 첫 위치 원소 읽기
 *      5. begin() : 첫 원소의 위치 (iterator)  // container type에서는 pointer가 아닌 iterator
 *      6. end() : 끝위치 (끝 원소의 다음위치)
 *      7. clear() : 모든 원소 삭제 - empty vector.
 *      8. empty() : empty 여부 check 
 *      9. size() : 현재 원소 수
 *      10. insert() : 원소 추가 -> 다양한 형태의 overloading
 *      11. erase() : 원소 삭제 
 */


#include <iostream>
#include <vector>

using namespace std;

//예제
int main(){
    vector <int> a;

    a.push_back(2);
    a.push_back(4);
    a.push_back(6);

    cout << a.size() << endl; // 3출력
    cout << a[1] << endl;     // 4출력

    a.pop_back();
    a.push_back(8);
    cout << a.front() << endl; // 2출력
    cout << a.back() << endl;  // 8출력


/** 
 * subscripting operator 사용 가능 : []  // a[i];
 *  --------------------
 *  vecotr <int> a(5);
 * 
 *  a[3] = 2; 
 *      : index 변수는 'unsigned int' type 
 *      // 컴파일러에 따라 경고가 나올 수도 있기 때문에 알아 둘것
 * 
 * 예제 
 *  "vecotr a"의 현재 원소 값을 모두 출력
 */
    unsigned int k;

    for( k =0 ; k < a.size(); k ++)
        cout << a[k] << endl;

/**
 * < Iterator > 
 *      : vercot, list 등 container class의 원소를 가르키는 일종의 pointer 
 *          (유의사항 : *p, p-> 가능, p = &a[2] 불가능, 주소연산자의 치환은 불가능)
 */

    vector <int> a(10);
    vector <int> :: iterator p; 

    for( unsigned k =0; k< 10; k++)
        a[k] = k;

    for( p = a.begin(); p < a.end(); p++)
        cout << *p << endl;
    
/* 유의사항 :
        p1 = a.begin(); // a의 첫 원소 위치
        p2 = a.end() ;  // a의 끝 원소 다음 위치 
        범위 지정 [p1, p2)
*/

/**
 * < vector class 의 member functions > 
 *      1. a.insert(p, t)       // p의 앞쪽에 t 추가
 *      2. a.insert(p, n, t);   // p의 앞쪽에 n개의 t추가
 *      3. a.insert(p, p1, p2); // p의 앞쪽에 [p1, p2) 범위의 원소 추가
 *      
 * ---------------------------------------------------
 * 
 *      4. a.erase(p);          // p 위치의 원소 삭제
 *      5. a.erase(p1, p2);     // p1부터 p2까지 (p2이전까지) 원소 삭제
 */

    vector <int> a;
    vector <int>:: iterator p;
    unsigned int k;

    a.push_back(3);
    a.push_back(4);
    a.push_back(7);

    p = a.begin() + 2;
    a.insert(p, 3, 5);

    for(k=0;k<a.size();k++)
        cout<<a[k]<< " : ";
    cout << endl;

    vector <int> b(a);
    b.insert(b.begin() +3 , a.begin(), a.begin()+3 ); // 이거 이해하셈
    // 원래 데이터 앞에 ~ 

    for (k-0; k<b.size();k++)
        cout<<b[k]<<" : ";
    cout << endl;

    p = b.begin() + 2;
    b.erase(p, p+2);

    for(k=0;k<b.size();k++)
        cout<<b[k]<<" : ";
    cout << endl;

/*
 a.swap(b); // 두 vecotr a,b 내용을 서로 swap 
 if(a==b)   // 두 vecotr a,b의 내용이 서로 동일 하면 
*/

    vector <int> a;
    unsigned int k;

    a.push_back(3);
    a.push_back(4);
    a.push_back(7);
    
    vector <int> b(a);

    if(a==b)
        cout<<"YES"<<endl;
    else
        cout << "NO\n";
    
    b.push_back(8);

    if(a==b)
        cout<<"YES"<<endl;
    else
        cout << "NO\n";
        
    a.swap(b);

    for(k=0;k<a.size();k++)
        cout<<a[k]<<" : ";
    cout << endl;
    for(k=0;k<b.size();k++)
        cout<<b[k]<<" : ";
    cout << endl;



}