#include <iostream>

using namespace std;


void main(){

    int *p, *q; 

    p = new int; // int 1개 공간을 할당하고 그 위치를 줌 
    p = new int(3); // int 1개의 공간을 할당하고 초기화를 3으로 함 

    q = new int[10]; // int 10개의 공간을 할당하고, 이녀석을 array처럼 사용이 가능 
    
    delete p ; // p의 공간을 free 
    delete [] q ; // q가 가르키는 array를 free  위치를 잘 봐야함 

    int a[5][3]; // 3개짜리 배열이 5개 모인 배열 

    int **p; // int pointer를 기본으로 하는 pointer p (더블 포인터)

    int *(a[10]); // int pointer 원소 10개로 이루어진 array 
    // = int *a[10]; 
    int (*a)[10]; // 정수 10개 배열을 referenced type으로 하는 pointer 변수 a, 단위가 int의 10배임


    //다차원 어레이 동적할당 
    //ex. a[3][4]; 동적할당 

    typedef int* IntArrayPtr; 
    IntArrayPtr *m = new IntArrayPtr[3]; // 그럴싸 하지만 더블포인터, int 포인터 타입으로 3개를 할당 
    for(int i =0 ; i < 3 ; i++)
        m[i] = new int[4];          //m의 123에다가  int4 크기만큼 각각 할당해줌 

        int d1,d2 ; 

        cout << "Enter the row and column D of the array : " ; 
        cin >> d1 >> d2 ; 


        
        // d1에 입력한 int값에 따라서 그만큼 공간을 뽑아 내는거임 
        // 값을 입력 받은 후에 공간을 만들때 사용하는 것
        IntArrayPtr *m = new IntArrayPtr[d1]; 
        int i,j;

        for( i= 0 ; i <d1; i++)
         m[i] = new int[d2];   // d2개 짜리(단위 int) 배열이 d1개 모인 2차원 배열 생성 

        cout<<"Enter "<<d1<<" rows of "<<d2 << " integers each"; 
        for(i=0;i<d1;i++) // 2차원 배열에다가 원소 박는거 
            for(j=0;j<d2;j++)
                cin>>m[i][j]; 
        
        cout<< "Echoing the 2-D array :"; 
        for(i=0;i<d1;i++){
            for(j=0;j<d2;j++)
             cout<<m[i][j] << " "; // 2차원 배열 출력 
            cout << endl; 
        }


        //사용이 끝난 메모리 free 과정 
        for(i=0;i<d1;i++)
            delete [] m[i];  // 달아놓은 방을 없에고 

        delete [] m ; // 세워놓은 층도 부숨 

 }