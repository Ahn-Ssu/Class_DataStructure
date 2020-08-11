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


        void invert();                                  //현재 가지고 있는 데이터 노드 순서를 역순으로 연결하여 재구성
        friend bool list_eqaul(my_list a, my_list b);   //일반함수 (friend) 두 개의 리스트 내용이 동일한가 
};

// 내가 잘못한게 있음 new head, old head를 굳이 class member로 선언을 안했어도 괜찮은데;;
void my_list::invert(){ 
    node *newhead,*oldhead;                     // swap 과정에서 과정의 head를 구분하기 위한 두 포인터 노드 선언 
    node *temp;                                 // 새로운 list를 가르킬 newhead가 새로 들어온 노드를 잡으러갈때 링크를 받아야하니까 기억하는 노트 포인터 
    newhead = NULL;                             // 1-1) 초기연산, 새로운 헤드는 아직 가르킬 곳이 없음 
    oldhead=head;                               // 1-2) 초기연산, 기존 member head에서부터 시작으로 한 노드씩 넘기기 위해 헤드에서 시작
   /* for(oldhead=head;oldhead!=NULL;oldhead = oldhead->link){
        temp = newhead;
        newhead = oldhead ;
        newhead->link = temp; 
    } */

    while(oldhead!=NULL){                       // oldhead가 tail에 닿아서
        temp = newhead;
        newhead = oldhead ;
        oldhead = oldhead->link; 
        newhead->link = temp; 
    }

    tail = head ;
    head = newhead; 
}

bool list_eqaul(my_list a, my_list b){
    return (equal_test(a.head,b.head));
}
// recursive algorithm 
bool equal_test(node *n1, node *n2){ 
    if(n1 == NULL && n2 ==NULL)                     // 1-1) 두 리스트가 모두 empty(NULL) 이면 ture return
        return true;                                
    if(n1 == NULL || n2 == NULL)                    // 1-2) -1에서 걸러져 둘 중에 하나만 empty면 false return 
        return false;
    if(eqaul_data(*n1,*n2))
        return equal_test(n1->link, n2->link);      // 2)   모든 경우에 해당하지 않고 비교한 노드가 같으면 다음노드 비교(재귀)
    else
        return false;                               // 1-3) 각 노드끼리 가지고 있는 데이터가 다르면 false retrun
}

bool eqaul_data(node n1, node n2){
    if(n1.name!=n2.name)
        return false;
    if(n1.score!=n2.score)
        return false;
    return true;
}


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
    *p = t;             // 2)   확보한 포인터에다가 '깂 (*p)'을 줌 : 노드를 가르키는 포인터 변수니까 노드의 포맷 그대로 데이터를 받아옴  
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