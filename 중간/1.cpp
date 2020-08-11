#include <iostream>


using namespace std;

/** <약술>
 * 문제 : 임의의 순서로 되어 있는 array 내용을 heap으로 구성
 *        주어진 노드를 root로 하는 subtree에서 root의 위치를 조정하여 heap을 구성 
 * 1) constructor의 parameter로 설정
 * 2) 유용한 private member 함수 고려 : !! adjust();
 *      root node의 위치가 잘못된 tree에 대하여 root의 위치를 재조정하여 heap을 재구성하는 연산 */


class element{
    public:
     string name;
     int score;  //key 값으로 고려 
     void set_data(string s, int n);
};

void element::set_data(string s, int n){
    name = s;
    score = n; 
}
#define HSIZE 100

 class my_heap{                         // key 값을 갖는 원소를 저장하는 공간
        int h[HSIZE];
        int csize;                      // the number of elements
        void adjust(int t_root);
    public:
        my_heap();
        my_heap(int a[], int n);
        int h_size();                   // 현재 원소수 조회
        void insert_heap(int t);    // 원소를 추가
        int delete_heap();          // heap으로 부터 원소 한개를 가져옴(삭제)
        bool heap_full();               // full 여부 check
        bool heap_empty();              // empty 여부 check    

        void show_all();      
 };

 my_heap::my_heap(){
     csize = 0;
 }
my_heap::my_heap(int a[], int n){
    int k;

    for( k =1; k<=n ; k++)          //주어진 배열원소를 heap 공간으로 저장 ( 0 -> 1번째부터)
         h[k] = a[k-1];
    csize = n;                      // heap의 size를 n으로 설정
    // 마지막 internal node(child를 갖는 노드) 부터 시작하여 역순으로 root까지 
    // n/2를 하면 마지막 internal node가 나오고, -1 씩 줄이면 같은 레벨에 있는 node한테 감 
    for( k= n/2 ; k>=1 ; k--)       
     adjust(k);                     // 해당 노드를 root로 하는 subtree에 대하여 adjust() tngod 
  }
 bool my_heap::heap_empty(){
     if(csize == 0)
        return true;
     else
        return false;
 }
 bool my_heap::heap_full(){
     if(csize >= HSIZE-1)  
        return true;
     else
        return false;
 }
 int my_heap::h_size(){
     return csize; 
 }
 void my_heap::insert_heap(int t){
     int k; 
     csize++;                                           // 1) size를 1 증가 시킨다.
     k = csize;                                         // 2) 끝 원소 위치부터 시작하기 위해 저장
     
     while( (k!= 1) && (t.score>h[k/2].score) ){        // 3-0) root에 도달하거나, parent 원소의 값이 큰 경우 루프 중지, 현위치로 확정
         h[k] = h[k/2];                                 // 3-1) parent 원소 값을 현위치로 이동시킴 (우리가 넣을 값은 t에 있어서 swap 안함)
         k /=2;                                         // 3-2) parent의 위치로 이동하여 다음 비교를 준비한다.
     } 
     h[k] = t;                                          // 4)   루프로 찾은 위치에 주어진 값을 넣는다. 
 }
 int my_heap::delete_heap(){
      int t;                                // root의 원소를 저장할 원소 선언
      int tmp;                              // 끝 원소 저장, 위치를 조정할 원소
      int parent, child;

      t= h[1];                                  // root의 원소를 저장
      tmp = h[csize];                           // 제거할 위치의 원소 key를 저장
      csize--;                                  // 위치의 유효 제거 ( 위치 제거) 
      parent = 1;                               
      child = 2;                                // root의 left child를 먼저 선택 

      while ( child <= csize) {                 // 'child가 존재하고' + size와 같거나 안쪽에서만 (유효한 heap에서) 놀 수있도록 제한 
            // child < cisze : 오른쪽이 있고,라는 뜻 
            // 오른쪽이 존재하고, 오른쪽의 key가 크면! 이라는 논리 
          if( (child < csize) && (h[child].score < h[child+1].score) )
            child++;                            // 조건에 해당하면 오른쪽을 선택
          if( tmp.score >= h[child].score)      // 해당원소의 key 값과 비교하여 child가 작으면 현위치(parent)로 결정 
            break;
          h[parent] = h[child];                 // child가 크면, 해당 child 원소 값을 parent로 이동시키고 (끌어올림)
          parent = child;                       // 위치를 child로 이동하여 다시 반복 
          child *= 2;                           // left로 내려가는 것임 
      } 
      h[parent] = tmp;                          // 찾은 위치에다가 주어진 값을 넣는다. 
      return t; 
 }
// delete랑 유사 
void my_heap::adjust(int t_root){
    double tmpkey;
    int child;
    int temp;

    temp = h[t_root];                   // root의 원소를 저장
    tmpkey = h[t_root].score;           // 지금 잘못되어있는 root의 key값을 저장
    child = 2*t_root;                   // root의 왼쪽(left) child 를 기준잡고 아래의 루프 시행 

    while( child <= csize){             // 어디상 child가 없으면, 루프 시행X 현위치로 결정
            //right child가 있고, right가 크면 child로 기준 잡고 내려감
        if( (child<csize) && (h[child].score < h[child+1].score) )
            child++;
        if( tmpkey > h[child].score)    // 지금 저장했던 root의 key값이 child보다 크면 루프 종료
            break;
        else                            // child가 크면,
        {   
            h[child/2] = h[child];      //child의 값을 parent로 끌어 올리고 
            child *= 2;                 // 위치를 child로 이동 
        }
    }
    h[child/2] = temp; 
}
void my_heap:: show_all( )
{
for (int k=1; k<=csize; k++)
cout << h[k].score << " : " ;
cout << endl;
}