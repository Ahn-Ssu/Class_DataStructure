#include <iostream>

using namespace std; 

class node { // 각 노드는 self-referential class type : 자기 자신을 가르키는 포인터 
    public : 
     string name; 
     double score; 
     node *left,*right ;    // 노드를 가르킬 수 있는 포인터, 자기 자신을/자기와 똑같은 것을  가르킬 수 있는 포인터를 멤버로 가지고 있dma
     void set_data(string s, double n); 
};
void node::set_data(string s, double n){
    name = s;
    score = n; 
}

class my_tree{
    public :
        int node_count;                         // 현재 node 수
        node *root;                             // root를 가르키는 pointer
        my_tree() ;                             // Constructure 

        int insert_root(node t);                // root로 node내용 t 추가 
        int insert_left(string tname, node t);  // recursive ) tname의 node 왼쪽에 t추가
        int insert_right(string tname, node t); // recursive ) tname의 node 오른쪽에 t 추가

        double score_sum();                     //  모든 node의 score 합
        double score_average();                 // 모든 node의 score 평균

        void print_data_inorder();              // inorder 순서로 모든 node 의 값 출력
        void print_data_preorder();             // preorder
        void print_data_postorder();            // postorder
};

int node_insert_left(node *p, string tname, node tnode);
int node_insert_right(node *p, string tname, node tnode);
double sum_allnodes(node *p);
void inorder_traverse(node *p);
void preorder_traverse(node *p);
void postorder_traverse(node *p);

my_tree::my_tree(){
    node_count = 0 ;
    root = NULL;
}
int my_tree::insert_root(node t){   // empty 상태에서만 적용, int는 empty가 아닐 경우 약속된 실패를 돌려주기 위함
    if(root!=NULL)                  // 1) root가 이미 있는경우 실패( 0 )을 리턴
        return 0;               
    node *p;                        // 2-1) 루트 노드 포인터한테 찍힐 루트 노드 생성
    p = new node;                   // 2-2) 공간할당
    (*p) = t;                       // 3)   새로운 노드 공간에 받아온 노드데이터 입력
    p->left = NULL;                 // 4) 새로운 노드는 좌우가 모두 NULL 셋업
    p->right = NULL;                // +) 링크가 따로 따라 오기 때문에 null로 한번 더 조정을 해주는 것
    root = p;                       // 5) 루트 포인터를 새로운 루트노드를 가르키게 조정
    node_count ++;                  // 6) 노드카운터 증가
    return 1;                       // 7) 성공을 리턴
}
int my_tree::insert_left(string tname, node t){ // tname 못찾거나 이미 노드가 있으면 int 를 통해 실패 전달 
    int result;  

    result = node_insert_left(root, tname, t); // recursive를 사용하기 위해서 member 접근 후 non-member functions에게 전달
    if(result == 1 ) 
        node_count++;
    return result; 
}
int node_insert_left(node *p, string tname, node tnode){ // p를 root로 하는 tree에서 데이터이름이 tname인 노드를 찾고 해당 노드 왼쪽에 t 추가 
    if(p==NULL)                 // 해당 노드 없음 
        return 0; 
    if(p->name == tname){       // 탐색하는 루트가 찾는 이름데이터가 같은 경우 
        if(p->left !=NULL)          // 해당하는 노드가 있지만 왼쪽에 이미 노드가 있는 경우 식별자 (-1)을 리턴
            return -1;
        node *t;                    // 그 밖에 조건이 모두 준비 된 경우 수행
        t = new node;               // 왼쪽에 새로운 노드 추가
        *t = tnode;                 // 1) 노드공간 확보
        t->left = NULL;             // 2) 데이터 내용 저장
        t->right = NULL;            // 3) 새로운 노드 R L  = NULL로 
        p->left = t;                // 4) 가지고 들어온 root의 왼쪽에 연결 
        return 1;                   // 5) 성공을 return
    }
    else{                       // 가지고 들어온 root가 찾는 node(name이 tname) 아닌 경우 
        int result = node_insert_left(p->left, tname, tnode);   // 해당 노드의 left subtree에 작업 수행 
        if( result != 0 )
            return result;                                      // 해당 노드가 없는게(+ 아직 못찾은 경우가) 아니라면 일단 리턴 
        return node_insert_left(p->right, tname, tnode);        // Right subtree에서도 작업을 수행 한뒤 그 결과 리턴 
    }
}
int my_tree::insert_right(string tname, node t){// tname 못찾거나 이미 노드가 있으면 int 를 통해 실패 전달 
    int result;

    result = node_insert_right(root, tname, t); 
    if(result == 1 )
        node_count++;
    return result; 
}
int node_insert_right(node *p, string tname, node tnode){
    if(p==NULL)
        return 0 ;
    if(p->name == tname){
        if(p->right!=NULL)
            return -1;
        node *t; 
        t = new node; 
        *t = tnode;
        t->left = NULL;
        t->right = NULL;
        p->right = t;
        return 1;
    }
    else {
        int result = node_insert_right(p->left, tname, tnode); // 생각) 왼쪽 먼저 찾는 이유는 binary tree는 왼쪽 먼저 채워지기 때문이라 생ㄱ
        if( result != 0 )
            return result; 
        return node_insert_right(p->right, tname, tnode); 
    }
}
double my_tree::score_sum(){
    return sum_allnodes(root); // 직접적으로 recursive call을 할수가 없어서 member인 root 의 정보만 넘김 
}
double sum_allnodes(node *p){
    if(p==NULL)             
        return 0 ;
    // 각 sub tree에 대해서 recursive 수행을 부른다음, 막타를 침 
    return sum_allnodes(p->left) + sum_allnodes(p->right) + p->score; 
}         

double my_tree::score_average(){
    if(node_count!=0)
        return sum_allnodes(root)/node_count; 
    else 
        return 0 ; 
}
void my_tree::print_data_inorder(){
    inorder_traverse(root); 
}
void inorder_traverse(node *p){
    if(p==NULL) 
        return; 
    
    inorder_traverse(p->left);
    cout << p->name <<" : "<< p->score << endl;
    inorder_traverse(p->right);
}

void my_tree::print_data_preorder(){
    preorder_traverse(root);
}
void preorder_traverse(node *p){
    if(p==NULL) 
        return; 
    
    cout << p->name <<" : "<< p->score << endl;
    preorder_traverse(p->left);
    preorder_traverse(p->right);
}
void my_tree::print_data_postorder(){
    postorder_traverse(root);
}
void postorder_traverse(node *p){
    if(p==NULL) 
        return; 
    
    postorder_traverse(p->left);
    postorder_traverse(p->right);
    cout << p->name <<" : "<< p->score << endl;
}
/** Treaversal Algorithm : Recursive Algorithm */ 
