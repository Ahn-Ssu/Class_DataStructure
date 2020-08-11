/**Queue 구현 
 * 
 * 처음배운 기본 구조 
 * char array 사용 
 */

#include <iostream>
#include <string> 

#define SIZE 100  // 최대 수용량이 100 밖에 안됨 

class my_q{
  private : 
  /** 여기는 전체적으로 데이터가 들어가는 슬롯임, class type이 올수 있음 ex> element (name, score);;
   *  data type이 변화하면 array , insert_q의 parameter type, delete_q의 return type 모두 변해야함 */
   char q[SIZE];
   int front; int rear; 
  public : 
   my_q(); // construct 클래스 private 초기화 
   void q_insert(char c);
   char q_delete();
   bool q_full();
   bool q_empty();
};

my_q::my_q(){
  front = 0; 
  rear = 0 ;
}
void my_q::q_insert(char c){ // 단점) 이 경우 rear는 처음에 확보한 공간 (SIZE) 까지 밖에 사용할 수 밖에 없음 
  if(!q_full()) {
  q[rear] = c ; 
    rear ++; 
  } 
}
char my_q::q_delete(){
   if(!q_empty()){
     char t = q[front]; 
    front ++ ;
   return t ; 
   }
}
bool my_q::q_full(){
  if( rear >=SIZE )
    return true; 
  else 
    return false; 
}
bool my_q::q_empty(){
  if( rear == front ) 
   return true; 
  else
   return false; 
}

