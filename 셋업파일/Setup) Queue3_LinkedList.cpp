#include <iostream>


using namespace std;


class node { // 각 노드는 self-referential class type : 자기 자신을 가르키는 포인터 
    public :
     string name; 
     double score; 
     node *link ;  // 노드를 가르킬 수 있는 포인터, 자기 자신을/자기와 똑같은 것을  가르킬 수 있는 포인터를 멤버로 가지고 있음
     void set_data(string s, int n); 
};

void node::set_data(string s, int n){
    name = s;
    score = n; 
}

/** node를 활용한 Queue 구현 
 */


class my_q{
  private : 
   node *front, *rear; 
  public : 
   my_q(); // construct 클래스 private 초기화 
   void insert_q(node t);
   node delete_q();
   bool q_empty();
};


my_q::my_q(){
    front = NULL;
    rear = NULL;
}

void my_q::insert_q(node t){
    node *p;                    // 1-1) 새롭게 데이터를 받아들일 공간을 위한 포인터 노드 생성
    p = new node;               // 1-2) 새 노드에 공간할당 
    *p = t;                     // 2)   새 노드에 데이터 복사(전달)
    
    if(rear==NULL){             // +) 해당 작업 수행이 첫수행인 경우 
        rear = p ;              //    front와 rear를 동시에 새 위치에 고정
        front = p ;
    }
    else                        // 처음이 아닌 경우 rear만 작업
        rear->link = p ;        // 3-1) rear가 가르키던 노드의 링크(null 상태)를 p를 가르키게함
        rear = p;              // 3-2) rear를 새 노드 p를 가르키게 함 
}

node my_q::delete_q(){
    if(!q_empty()){             // 1) q가 empty 인 경우 수행 X 
        node temp;              // 2-1) 삭제할 공간의 노드 데이터를 받을 노드 변수 생성
        node *p;                // 3-1) 삭제할 공간을 가르킬 포인터 노드 생성 
        temp = *front;          // 2-2) 삭제할 공간의 데이터 복사 
        p = front;              // 3-2) 삭제할 공간을 가르킴 
        front = front->link;    // 4)   front를 그 다음 q로 조정
         if(front==NULL)        // +) 마지막 노드인 경우 rear도 NULL로 셋팅(empty position)
            rear = NULL;
        delete p;               // 5) 공간 폭파
        return temp;            // 6) 리턴 
    }
}

bool my_q::q_empty(){
    if(front==NULL  && rear ==NULL)
        return true;
    else
        return false;
    
}