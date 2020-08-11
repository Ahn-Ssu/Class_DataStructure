#include <iostream>


using namespace std;


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

        double score_sum();             // 모든 원소의 score 합을 계산
        double score_average();         // 현재 heap에 저장된 원소의 score 평균 값을 계산 
 };

double summation(element a[], int troot, int n);


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

 double my_heap::score_sum(){
     return summation(h,1,csize);
 }

 double summation(element a[], int troot, int n){
     if(troot > n)
      return 0 ;
    
    return (a[troot].score + summation(a,2*troot,n) + summation(a,2*troot + 1, n) );
 }

 double my_heap::score_average(){
     if(csize == 0) 
        return 0 ; 
    return score_sum() / csize; 
 }