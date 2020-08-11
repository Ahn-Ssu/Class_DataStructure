/*{성명, 점수}로 이루어지는 원소를 저장하는 Linked list를 구현하고, 다음 main 함수에

포함되는 내용을 모두 완성하시오.
*/
#include <iostream> 
#include <string> 

using namespace std; 

class node{
  public : 
    string name;
    double score;
    node *link;
    void set_data(string s, double n); 
};

void node::set_data(string s, double n){
  name = s;
  score = n;
}

class my_list{
    node *head, *tail;
  public :
    my_list();
    void add_to_head(node t);
    void add_to_tail(node t);
    node delete_from_head();
    int num_nodes();
    bool list_empty();
    double score_sum();
    double get_score(string t_name);
    int remove_a_node(string t_name);
};

my_list::my_list(){
  head=NULL;
  tail = NULL;
}

void my_list::add_to_head(node t){
  node *p;
  p = new node; 
  (*p) = t ;
  p->link = head; 
  head = p; 
  if(tail==NULL)
   tail = p ; 
}

void my_list::add_to_tail(node t){
  node *p;
  p = new node; 
  (*p) = t; 
  p->link= NULL;
  if( tail != NULL)
   tail->link = p; 
  else 
    head = p ;
  tail = p; 
}

node my_list::delete_from_head(){
  node temp;
  node *t;
  t = head ; 
  temp = *head; 
  head = head->link;
  delete t;
  if (head == NULL) 
    tail = NULL;
  return temp;
}

int my_list::num_nodes(){
  node *t ;
  int count = 0 ; 
  for ( t=head ; t!=NULL; t= t->link) // 링크드 리스트를 한번 쭉 훑는 로직 
   count++;
  return count; 
}



bool my_list::list_empty(){
  if(head==NULL)
   return true; 
  else 
   return false; 
}

double my_list::score_sum(){
  node *t ;
  double sum = 0.0 ; 
  for ( t=head ; t!=NULL; t= t->link)
   sum += t->score; 
  return sum;  
}

double my_list::get_score(string t_name){
  node *t; 
  for ( t =head; t!=NULL; t = t->link){
    if(t_name==t->name)
     return t->score; 
  }
 return -1 ; 
}

int my_list::remove_a_node(string t_name){ // 받은 string 변수를 가진 node를 찾아내서 지워버림 
  node *t, *pre;
    pre = NULL;
    t = head; 
  
  while ( (t != NULL) && ( t->name != t_name) ){    // 현재 위치한 노드(t)가 NULL이 아니고 동시에 현재 위치한 노드가 찾는 노드가 아닐때 
    pre = t ;                           // 1) 이전 노드를 현재 노드로 최신화 하고
    t = t->link;                        // 2) 현재 가르킬 노드를 다음노드를 가르키게 조정 
  }

  if( t == NULL)                                    // t가 마지막 노드면 못찾았다고 알림
     return 0; 

  if(pre != NULL)                       // pre가 null이여서 첫번째 노드가 찾는 노드였던 경우의 판정
   pre->link = t->link;                 // 1) 널이 아닌경우 지금 t link에 이어저 있는 노드를 pre가 가지고 있던 이전 노드의 link로 연ㄱㄹ 
  else  
   head = t->link;                      // 2) 널인경우 이새끼 지우면 되니까 head 를 조정

   delete t;                            // t 삭제 
  
  if(head == NULL)
    tail = NULL; 
  if( t == tail)
    tail = pre; 

    return 1;
}




int main( )
  {
   my_list    a;
   node   tmp;
 tmp.set_data("Kim", 83.5);
    a.add_to_head(tmp);
    tmp.set_data("Lee", 78.2);
    a.add_to_head(tmp);           // head 위치로 2개의 원소 추가
               cout << a.num_nodes() << " : " << a.score_sum() << "\n";  // 1단계 점검
              tmp.set_data("Park", 91.3);  
    a.add_to_tail(tmp);             // tail 위치로 1개의 원소 추가
               cout << a.num_nodes() << " : " << a.score_sum() << "\n";  //2단계 점검
               tmp = a.delete_from_head();
               cout  << tmp.name << " is deleted.\n";   // 3단계 점검
               tmp.set_data("Choi", 85.1);  
    a.add_to_tail(tmp);             
 tmp.set_data("Ryu", 94.3);  
    a.add_to_head(tmp);             // 2개의 원소 추가

               cout << a.num_nodes()<< " : " << a.score_sum() << "\n";  
               cout << "Park’s score : " << a.get_score("Park")<< "\n";  // 4단계 점검
               if ( a.remove_a_node("Kim") == 1)
                   cout << "Kim is deleted from the list. \n";     // 5단계 점검
               cout << a.num_nodes()<< " : " << a.score_sum() << "\n";  // 최종 점검      
                return 0;
  }