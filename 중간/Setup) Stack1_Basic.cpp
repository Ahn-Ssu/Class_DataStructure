/**Stack 구현 
 * 
 * 처음배운 기본 구조 
 * char array 사용 
 * top 기준 0 : 넣을 위치
*/

#include <iostream>

#define SIZE 100 // 문제 안에서 범위를 미리 지정해 놓는 것 

using namespace std;


class my_stack{ 
 /** 여기는 전체적으로 데이터가 들어가는 슬롯임, class type이 올수 있음 ex> element (name, score);;
   *  data type이 변화하면 array , insert_q의 parameter type, delete_q의 return type 모두 변해야함 */
    int s[SIZE];  
    int top; 
  public : 
    my_stack();  //constructor (초기화 function)
    void push(int x); 
    int pop(); 
    int top_element(); 
    bool stack_full(); 
    bool stack_emtpy(); 
};

my_stack::my_stack(){
  top = 0;
}
void my_stack::push(int x){
  if(stack_full){
    cout<<"the Stack is full";
  }
  else{
   s[top] = x;
   top ++;
  }
}
int my_stack::pop(){
 if(stack_emtpy){
   cout<<"the Stack is empty"<<endl;
   return NULL; 
 }
 else{
    top --;
  return s[top];
 }
}
int my_stack::top_element(){
  return s[top-1];
}
bool my_stack::stack_emtpy(){
  if(top==0)
   return true;
  else
   return false;
}
bool my_stack::stack_full(){
  if(top >=SIZE) // 이것도 있고  (top ==SIZE) 이것도 있음 
   return true;
  else 
   return false; 
}