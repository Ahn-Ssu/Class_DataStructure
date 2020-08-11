#include <iostream>
#include <string> 

using namespace std; 


int main(){

    string st1();       //default 
    string st2("Test"); // 직접입력으로 초기화
    string st3(st2);    // 다른 string obj.를 끌고와서 똑같이 초기화 

    cout<< "String st1() : " << st1<<endl;
    cout<< "String st2(""Test"") : " << st2<<endl;
    cout<< "String st1(st2) : " << st3<<endl;
    /** 출력 결과
     * String st1() : 1 
     * String st2(Test) : Test
     * String st3(st2) : Test 
     */

    string st4("1234"); 
    //insert는 끼워넣기
    st4.insert(3, "kk");  // String object의 3번째 위치에 kk를 넣을 것
    cout<< "String st4(""1234""), insert(3, kk) : " << st4<<endl;
    st4.insert(3, "program", 4, 2); // String object의 3번째 위치에 / 주어진 string의 4번째부터 2문자 넣을 것
    cout<< "String st4(""1234""), insert(3, program, 4,2) : " << st4<<endl;
    /**출력 결과
     * String st4(1234), insert(3, kk) : 123kk4
     * 
     * String st4(123kk4), insert(3,program,4,2) : 123rakk4
     */

    string st5("Handong"); 
    //replace는 대체, replace (시작위치,넣을 문자열 길이,대체스트링)
    st5.replace(2,2,"kk"); //!!해보니까 다름!! 
    // replace(시작할 위치, 지울 기존 문자열의 문자 수, 넣을 문자열;다들어감)
    cout<<"String st5(Handong), replace (2,2,kk) : "<<st5<<endl;
    /**출력 결과
     * String st5(Handong), repalce (2,2,kk) : Hakkong  
     */

    string st6("Apple"); 
    st6.erase(3,2); //3번째부터 2개 지움 + 원소 시작은 0부터 
    cout<<"string st6(Apple),erase(3,2) : "<<st6<<endl;
    /**출력 결과
     * "string st6(Apple),erase(3,2) : App
     */
    int lenght = 0 ; 
    string st7 = ("123 567 9");
    lenght = size(st7); 
    cout<<"String st7(123 567 9), size : "<< lenght<<endl;
    /**출력 결과
     * String st7(123 567 9), size(st7) : 9
     * 빈칸도 센다는 것입니다. & null(\0) 안셈.
     */
    return 0 ; 
}