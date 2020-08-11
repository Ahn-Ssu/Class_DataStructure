#include <iostream>

using namespace std; 


// 관리할 데이터 포맷의 예시 
class element{
    public:
     string name;
     double score;
     void set_data(string s, double n);
};

void element::set_data(string s, double n){
    name = s;
    score = n; 
}



/** Linked List 의 구현 (아래)
 *  !!!!node!!!! 를 사용함 */ 
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

/**노드에는 헤드(head)와 테일(tail)이 있음
 * 노드는 필요한 시점에 '동적할당'으로 생성
 * 마지막 노드의 링크는 null로써 끝노드임을 알게 한다 
 */

class my_list {
        //첫노드와 끝노드를 가르키는 노드타입(노드를 가르킬 수 있는)의 포인터 head, tail
        node *head, *tail; 
    public:
        my_list();
        void add_to_head(node t); // '노드'단위로 삽입 to head
        void add_to_tail(node t); // '노드'단위로 삽입 to tail
        node delete_from_head();  // '노드' 단위로 데이터를 가져옴 (노드 안의 구조 ex. name, score)
        int num_nodes();          // '노드'가 몇 개 있는가 
        bool list_empty();        // 데이터'노드'가 있는가 
};

my_list::my_list(){ 
    //처음 class, 혹은 object(instance)를 만들었을 때는 당연히 받은 데이터 값도 없고 가르킬 곳도 없음 
    head = NULL;
    tail = NULL;
}

/** add node 연산 
 *  1) 동적할당을 통한 노드만큼의 공간 확보
 *  2) 확보한 노드 공간에다가 데이터 값을 저장 
 *  3) 확보한 노드의 Link를 조정, head와 tail의 위치를 조정 */ 
void my_list::add_to_head(node t){
    node *p;            // 1-1) 노드를 가르키는 포인터 변수 선언 
    p = new node;       // 1-2) 노드의 주소에 대해서 공간을 새로 줘야함 
    *p = t;             // 2)   확보한 포인터에다가 '값 (*p)'을 줌 : 노드를 가르키는 포인터 변수니까 노드의 포맷 그대로 데이터를 받아옴  
    //'->' : 포인터가 가르키는 타입에 속한 member를 가르킬때 사용 
    p->link = head;     // 3-1) 머리에다가 추가, 새로생긴 노드의 링크를 기존 헤드에다가 링크
    head = p;           // 3-2) 헤드를 최신의 새로생긴 노드를 가르키게 조정 
    if(tail==NULL) 
        tail = p;       // 처음이면 꼬리도 챙겨야함
}
void my_list::add_to_tail(node t){
    node *p;            // 1-1) 포인터 타입 노드 선언
    p = new node;       // 1-2) 새 노드에 원룸 내어주기
    *p = t;             // 2)   새로운 공간에다가 데이터 채우기
    tail->link = p;     // 3-1) 테일(포인터타입)이 가르키고 있는 노드의 링크가 새로운 노드를 가르키게 설정
    tail = p ;          // 3-2) 꼬랑지가 바뀌었으니 테일도 조정
    if(head==NULL)
        head = p ;      // 처음이면 머리도 챙겨줘야함 
}

node my_list::delete_from_head(){
    node temp;          // 값을 저장할 노드 타입 변수
    node *t;            // 지울 공간을 가르키는 노드타입 포인터 변수, 헤드가 옮기면 기억을 못하니까 붙잡고 있는 것
    t = head;           // 1) 지울 공간의 주소를 copy! 
    temp = *head;       // 2) temp에는 head의 값을 받아감 
    head = head->link;  // 3) 헤드를 원래 헤드가 없어졌으니까 1.헤드가 가르키던 2.노드의 링크가 3.가르키는 곳으로 감 
    delete t;           // 4) 잡아둔 공간을 free 시킴 (좌표를 알려주어 공간파괴)
    if(head == NULL)    // +) 만약에 마지막 노드였으면 테일도 널로 둬야함
        tail = NULL; 
    return temp;        // 5) 가져온 데이터를 노드 타입으로 리턴 
}

int my_list::num_nodes(){
    node *t;
    int count = 0 ; 
    for( t = head; t!=NULL; t= t->link) // ★★ 노드를 쭉 훑는 로직  
        count ++;
    return count ; 
}

bool my_list::list_empty(){
    if(head==NULL && tail==NULL)
     return true;
    else
     return false;  
}