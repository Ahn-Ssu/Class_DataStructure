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

/** node를 활용한 stack 구현 
 *  이거 구현할때 재밌는게 노드 class가 아래의 활용 class보다 '먼저' 선언 되어야 함 
 */

class my_stack{
        node *top;              // 노드를 가르키는 탑! (다른 곳에서 헤드or테일의 느낌)
    public:
        my_stack();
        void push(node t);      // 데이터 폼이 node 단위로 옮겨짐 
        node pop();             // 노드 단위 리턴 
        bool stack_empty();     // 메모리를 사용하기 때문에 full이 발생하지 않음, 굳이 full check를 구현하지 않음 
};

my_stack::my_stack(){
    top = NULL;                 // top이 포인터가 되었기 때문
}

void my_stack::push(node t){
    node *p;                    // 1-1) 공간을 새로 받기 위한 포인터 노드 선언
    p = new node;               // 1-2) 포인터 노드에 공간을 할당
    *p = t;                     // 2)   노트 포인터 값을 받아온 t에다가 카피 

    if(top==NULL)               
        p->link=NULL;           // 첫 데이터(노드)인 경우 챙기기
    else
        p->link=top;            // 3-1) 새로만든 노드의 링크를 탑이 가르키고 있는 노드에다가 도킹
    
    top = p;                    // 3-2) 새로만든 노드를 탑으로 설정 
}

node my_stack::pop(){
    if(!stack_empty()){           // 1)   empty check, 없으면 아무것도 수행 안함 
        node temp;              // 2-1) 리턴할 데이터를 저장하는 노드 
        node *t;                // 3-1)   free시킬 현 top의 노드의 위치를 저장하는 포인터 노드
        temp = *top;            // 2-2) 탑이 가르키는 노드의 데이터를 temp 노드에다가 받아서 저장
        t = top;                // 2-2) 삭제시킬 현 top의 노드 위치를 저장  
        top = top->link;        // 4)   링크 조정
        delete t;               // 5)   폭파 
        return temp;            // 6)   리턴 
    }
}

bool my_stack::stack_empty(){
    if(top==NULL)
        return true;
    else
        return false;
}