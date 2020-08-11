/*
 새로운 데이터 구조
1) 구조와 특징
2) 연산과 구현
3) 응용 
- 의 순서로 학습 */

/*
<정의>

Empty거나, 다음을 만족하는 Binary Tree
 1) 각 노드는 서로 다른 key 값을 가진다.  
    ★ 중요한 점 : 서로다른 키 값, key 값이 고유하다, binary tree에는 중복되서 나타나지 않음.
 2) left subtree에 속한 모든 노드의 key 값은 루트의 key 값보다 !작다.! 
 3) right subtree에 속한 모든 노드의 key 값은 루트의 key 값보다 !크다.!
 4) 모든 subtree는 binary search tree이다. : 모든 위치에서 조건을 만족한다는 것. 
 */

/* 
Binary Search Tree ADT 
 > Key 값을 포함하는 원소를 저장 : search를 용이하게 하는 데이터 구조 
  ex) 일련의 원소를 저장해 놓고 key 값으로 search를 함. 어떤 값을 가지는 원소의 내용을 알고 싶다. 

<연산>
 ★ Search() : 어떤 key 값을 갖는 원소 조회
    Insert_node() : 원소를 추가
    Delete_node() : 원소를 삭제
    Size() : 현재 원소수를 조회
    Empty() : 현재 empty 여부 체크

 이 외에도 필요한 것에 따라 구현은 나뉨 
 */



/*
<delete_node() 연산>
    binary tree의 특정 node를 삭제 

- Algorithm
 삭제할 노드의 case마다 다른 logic 시행 ( 경우의 수  3개)
 1) Treminal node(= leaf) 이면
    parent의 해당 link를 null로 변경
 2) degree가 1인 node 이면
    parent의 해당 link에 child를 연결 ( = 해당 노드 삭제한담에 그자식이 가지고 있던걸 게또)
 3) degree가 2인 node 이면
    해당 노드를 
        left subtree의 largest node (왼쪽 서브트리의 오른쪽 끝 원소 )또는
        right subtree의 smallest node( 오른쪽 서브트리의 왼쪽 끝 원소 ) 를 대체. 
*/

#include <iostream>

using namespace std;

class bst_node {
    public :
        string name;
        string s_id;
        double score;

        bst_node *left, *right;
        bst_node();
        bst_node(string id, string studentName, double n);
        void set_data(string id, string studentName, double n);
};

bst_node::bst_node(){
    name = "None";
    s_id = "00000000";
    score = 0.0;
}
bst_node::bst_node(string id, string studentName, double n){
    name = studentName;
    s_id = id;
    score = n;
}

void bst_node::set_data(string id, string studentName, double n){
    name = studentName;
    s_id = id;
    score = n;
}

/*
class s_record{
    public:
        string name;
        string s_id;
        double score;
};

class  bst_node {
    public : 
        s_record s_data;
        bst_node *left, *right;
}
*/

class bst_tree {
        bst_node * root;
        int csize;
    public :
        bst_tree();
        void insert_node(bst_node t);
        bst_node delete_node(string key);
        bool empty();
        int size();
        bst_node search(string tid);
        // or s_record search(string s);

        void show_inorder();
};

void inorder_traverse(bst_node *p);

bst_tree::bst_tree(){
    root = NULL;
    int csize = 0 ; 
}

 /* 
<Search 연산 >   -- binary serch랑 유사.
    주어진 어떤 key 값 (k)을 갖는 원소를 찾는 연산, (해당 원소의 data 값을 return) 

    Q. 왜 binary search라는 말을 사용하였는가?
    A. 우리가 알고 있을때 한번 search 할때마다 대상 공간을 2등분함, 못찾는 경우에 계속 절반으로 등분하는데
       최악의 경우로 최대 시행을 해도 시행 횟수는 O(logn)이기 때문에. 
       
       +) 그러나 입력 순서에 따라 complete tree가 될수도 있고 linear tree가 될 수도 있다.  
       이상적으로는 complete가 되어야 한다. lenaer form을 가지면 skewed tree라고 하는데 이것은 
       O(n) 폼을 갖는다. (tree를 사용하는 장점 x )

- Algorithm 
 1) 주어진 tree(root)가 empty면 실패처리
 2) root의 key값이 k이면, root의 data 값 return 
 3) root의 key 값보다 k가 작으면, left subtree에서 찾은 결과를 return
 4) root의 key 값보다 k가 크면  , right subtree에서 찾은 결과를 return 
 */
bst_node bst_tree::delete_node (string key){
    bst_node *p, *parent;
    bst_node *temp;

    p = root;

    if(root == NULL) {
        printf("없떵");
    }
    /*
    temp = *p;
    delete(p);
    return temp;
    */
    while(1){
        if(p->s_id==key){
            // 1 : degree 0
            if(p->left==NULL && p-> right == NULL){
                if(p->s_id > parent->s_id){
                    parent->right = NULL;
                    delete(p);
                }
                else{
                    parent -> left =NULL;
                    delete(p);
                }
            }//2 : degree 1
            else if(p->left==NULL && p->right != NULL){
                if(p->s_id > parent->s_id){
                    parent->right = p->right;
                    delete(p);
                }
                else{
                    parent->left = p->right;
                    delete(p);
                }
            }//3 : degree 1 
            else if(p->left!=NULL && p->right == NULL){
                if(p->s_id > parent->s_id){
                    parent->right = p->left;
                    delete(p);
                }
                else{
                    parent->left = p->left;
                    delete(p);
                }
            }//4 : degree 2
            else if(p->left!=NULL && p->right != NULL){
                bst_node *last;
                
                last = p->left;

                while(last->right!=NULL)
                    last = last->right;
                
                p->s_id = last->s_id;
                delete_node(last->s_id);
            }

            if(p->s_id > key){
                parent = p;
                p = p->left;
            }
            else if (p->s_id < key){
                parent = p ;
                p = p-> right;
            }

        }
    }
}















bst_node bst_tree::search(string tid){
    bst_node *p;
    p = root;
    if(root==NULL){
        //해당 node 없음 처리 예 
        bst_node tmp;
        tmp.set_data("00000000", "None", -1); // 일종의 약속
        cout << "The key" << tid << "dose not exist"<<endl;
        return tmp;
    }

    while(1){
        if(p->s_id == tid)
         return (*p);
        if(p->s_id < tid) {
            if(p->right == NULL){
                bst_node tmp;
                tmp.set_data("00000000", "None", -1); // 일종의 약속
                cout << "The key" << tid << "dose not exist"<<endl;
                return tmp;
            }
            else  
                p= p-> right;
            }
            else{
                if(p->left == NULL){
                    bst_node tmp;
                    tmp.set_data("00000000", "None", -1); // 일종의 약속
                    cout << "The key" << tid << "dose not exist"<<endl;
                    return tmp;
                }
                else
                    p = p->left;
                    
            }
    }
}



/* 
<Insert_node() 연산 >
    주어진 어떤 key 값(k)을 갖는 원소를 넣는 연산

- Algorithm
 1) 주어진 key 값이 추가될 위치를 찾는다. ( 찾을때 같은 key 값을 가진 원소가 당연히 없어야함 )
                            위치를 찾을 때 rearch logic 과 동일하게 수행함 
 2) Node를 생성하여 주어진 값을 넣고, 해당 위치에 연결시킨다. 
 */

void bst_tree::insert_node(bst_node t){
    bst_node *p;
    bst_node *tmp; // 새로 넣을 임시 공간 

    tmp = new bst_node;
    *tmp = t;
    tmp -> left = NULL;
    tmp -> right = NULL;

    // 비어 있던 경우 
    if(root==NULL){
        root = tmp; 
        return ; 
    }

    //비어 있지않은 경우 
    p = root; 
    while (1) {
         if(p->s_id == t.s_id){
             cout << "Insertion Failed : the Key " << t.s_id << " already exists." << endl; 
             return ; 
         }
         if( (p->s_id) < t.s_id ){
             if(p->right == NULL ){
                 p->right = tmp;
                 return ; 
             }
             else 
                p = p->right; 
         }
         else{
             if(p->left == NULL) {
                 p->left = tmp;
                 return; 
             }
             else 
                p = p->left;
         }
    }
}

 void bst_tree::show_inorder(){
     inorder_traverse(root);
 }

void inorder_traverse(bst_node *p){
    if(p==NULL) 
        return; 
    
    inorder_traverse(p->left);
    cout << p->s_id <<" "<< p->name <<" : "<< p->score << endl;
    inorder_traverse(p->right);
}