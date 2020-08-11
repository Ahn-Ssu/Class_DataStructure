/**Queue 구현 
 * 
 * 일회성을 없엔 (circular Queue)
 * char array 사용
 * front와 rear에 % 연산으로 순회성을 부여 
 * full과 empty 논리를 조금 바꿈  
 */

#include <iostream>
#include <string> 

#define SIZE 100 // circluar queue의 한계, 한번에 담을 수 있는 수용량이 100(현 SIZE의 크기)까지 밖에 안됨 

class my_q{
  private : 
  /** 여기는 전체적으로 데이터가 들어가는 슬롯임, class type이 올수 있음 ex> element (name, score);;
   *  data type이 변화하면 array , insert_q의 parameter type, delete_q의 return type 모두 변해야함 */
   char q[SIZE];
   int front; int rear; 
  public : 
   my_q();
   void insert_q(char c);
   char delete_q();
   bool q_full();
   bool q_empty();
};

my_q::my_q(){
  front = 0; 
  rear = 0 ;
}
void my_q::insert_q(char c){
  if(!q_full()) {
  q[rear] = c ; 
    //  rear ++;
   rear = (rear+1) %SIZE; // 증가할때 끝원소 직후 첫 원소로 이어지게끔 구현하는 것 
  } 
}
char my_q::delete_q(){  
 
   if(!q_empty()){
     char t = q[front]; 
   front = (front +1) % SIZE ;  // 증가할때 끝원소 직후 첫 원소로 이어지게끔 구현하는 것 
   //   front ++ ;
   return t ; 
   }
}
bool my_q::q_full(){
   // 순환할때 같은 순환 값으로 충돌할 수도 있으니 
   // rear와 한바퀴 차이가 나는 경우, 그 앞 칸을 비워 empty로 책정 
  if( (rear+1)%SIZE == front)
    return true; 
  else 
    return false; 
}
// full_TEST 로 제한을 걸기 때문에 그를 초과할 수가 없음 
// 그래서 rear == front 
bool my_q::q_empty(){ 
  if(rear == front) 
   return true; 
  else
   return false; 
}
