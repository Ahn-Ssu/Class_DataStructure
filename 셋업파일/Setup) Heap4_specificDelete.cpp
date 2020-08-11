#include <iostream>


using namespace std;

/** <정의>
 *  1) Complete binary tree :: 중간에 빠진 것 없이 왼쪽부터 오른쪽 순으로 꽉 채워져 있는 것 (cf. full)
 *  2) Max-tree : Parent의 key 값이 children의 key 값 보다 크다. 
 *                  즉, 어떤 노드의 key값은 그의 모든 desendents의 key 값 보다 크다. 
 *             +) key : 해당원소를 조회할때 근거가 되는 원소의 특정 내용 (ex. 학생을 찾아라 i. 학번 , ii.이름 ) */

/** <특징>
 *  저장된 원소 중 key 값이 가장 큰 원소를 제공하는 데이터 구조 
 *  원소의 insert와 delete가 모두 O(logN)에 이루어 진다. ; 상당히 효율적인 포맷 logn > n 
 *  i)   정수 원소를 넣고 출력할때는 가장 큰 원소를 찾아 돌려주는 기능을 제작
 *  ii)  들어오는 순서대로 막 넣거나, 들어오면 크기에 따라 sort해서 넣는 구조는 insert 혹은 delete 과정에서 O(n)의 시간이 걸림 나머지는 O(1) 
 *  iii) !! Heap !! 은 insert와 delete 모두 O(logn) 만큼 걸림 */

/** <표현>
 * 1) 일반적으로 array를 사용하여 표현 : compelte binary tree이므로 연속으로 채워지게 됨 
 * 2) root의 위치를 1로 했을 때
 *      a) left child : 2*k 번째 원소
 *      b) right child : 2*k + 1 번째 원소
 *      c) parent : k/2 번째 원소 (나머지가 버려지는 정수형 나눗셈) */ 


class element{
    public:
     string name;
     double score;  //key 값으로 고려 
     void set_data(string s, double n);
};

void element::set_data(string s, double n){
    name = s;
    score = n; 
}
#define HSIZE 100

 class my_heap{                         // key 값을 갖는 원소를 저장하는 공간
        element h[HSIZE];
        int csize;                      // the number of elements
    public:
        my_heap();
        int h_size();                   // 현재 원소수 조회
        void insert_heap(element t);    // 원소를 추가
        element delete_heap();          // heap으로 부터 원소 한개를 가져옴(삭제)
        bool heap_full();               // full 여부 check
        bool heap_empty();              // empty 여부 check       

        //주어진 이름에 해당되는 노드를 찾아서 그것을 삭제하고 그 후에도 heap의 구조를 유지 
        int node_delete_by_name(string tname);   // 현재 heap에서 특정 값 원소를 삭제 
 };

int delete_node(element a[],  int troot, string tname, int n ); 
void heap_adjust(element a[], int troot, int size); 

 my_heap::my_heap(){
     csize = 0;
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
 void my_heap::insert_heap(element t){
     int k;    
     csize++;                                           // 1) size를 1 증가 시킨다.
     k = csize;                                         // 2) 끝 원소 위치부터 시작하기 위해 저장
     
     while( (k!= 1) && (t.score>h[k/2].score) ){        // 3-0) root에 도달하거나, parent 원소의 값이 큰 경우 루프 중지, 현위치로 확정
         h[k] = h[k/2];                                 // 3-1) parent 원소 값을 현위치로 이동시킴 (우리가 넣을 값은 t에 있어서 swap 안함)
         k /=2;                                         // 3-2) parent의 위치로 이동하여 다음 비교를 준비한다.
     } 
     h[k] = t;                                          // 4)   루프로 찾은 위치에 주어진 값을 넣는다. 
 }
 element my_heap::delete_heap(){
      element t;                                // root의 원소를 저장할 원소 선언
      element tmp;                              // 끝 원소 저장, 위치를 조정할 원소
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

 int my_heap::node_delete_by_name(string tname){
     if(csize==0)
        return 0;
     if( delete_node ( h , 1 , tname, csize) ==1){
         csize -- ;
         return 1;
     }
     else return 0 ;
 }

 int delete_node(element a[],  int troot, string tname, int n ){
    // 1) 주어진 root가 empty면 (troot가 n보다 크면 ) return 0 l 
     if(troot>n)
        return 0 ; 
    
    element temp;

     // 2) root가 찾는 node 이면
            // root와 끝 원소를 서로 교환하고 root이하 subtree를 adjust 한다, return 1
     if(a[troot].name == tname){
         temp = a[n]; 
         a[n] = a[troot];
         a[troot] = temp; 
         heap_adjust(a, troot, n);
         return 1 ;
     }
     
     if(delete_node(a,troot*2,tname,n)==1)
        return 1;

       return (  delete_node(a, troot*2+1, tname, n)  ) ;
     
    
     // 3) root가 찾는 원소가 아니면
        // left subtree에서 동일작업을 수행 -> 결과가 1이면 return 1 
        // right subtree에서 동일 작업을 수행한 결과를 return; 
 }
 void heap_adjust(element a[], int troot, int size){
     double tmpkey;
    int child;
    element temp;

    temp = a[troot];                   // root의 원소를 저장
    tmpkey = a[troot].score;           // 지금 잘못되어있는 root의 key값을 저장
    child = 2*troot;                   // root의 왼쪽(left) child 를 기준잡고 아래의 루프 시행 

    while( child <= size){             // 어디상 child가 없으면, 루프 시행X 현위치로 결정
            //right child가 있고, right가 크면 child로 기준 잡고 내려감
        if( (child<size) && (a[child].score < a[child+1].score) )
            child++;
        if( tmpkey > a[child].score)    // 지금 저장했던 root의 key값이 child보다 크면 루프 종료
            break;
        else                            // child가 크면,
        {   
            a[child/2] = a[child];      //child의 값을 parent로 끌어 올리고 
            child *= 2;                 // 위치를 child로 이동 
        }
    }
    a[child/2] = temp; 
     // member 함수의 adjust() 기능을 일반함수로서 구현
     // 주어진 배열과 주어진 size에 대하여 적용하도록 변경할 것
 }