//1. Expression의 infix표현을 postfix로 변환하는 프로그램을 작성

#include <iostream>
#include <string>
#define SIZE 100
#define EOS '$'

using namespace std; 

class my_stack{ 
    char s[SIZE]; 
    int top; 
  public : 
    my_stack();  //constructor (초기화 function)
    void push(char x); 
    char pop(); 
    char top_element(); 
    bool stack_full(); 
    bool stack_emtpy(); 
};

my_stack::my_stack(){
  top = 0;
}
void my_stack::push(char x){
  if(stack_full()){
    cout<<"the Stack is full";
  }
  else{
   s[top] = x;
   top ++;
  }
}
char my_stack::pop(){
 if(stack_emtpy()){
   cout<<"the Stack is empty"<<endl;
   return NULL; 
 }
 else{
    top --;
  return s[top];
 }
}
char my_stack::top_element(){
  return s[top-1];
}
bool my_stack::stack_emtpy(){
  if(top==0)
   return true;
  else
   return false;
}
bool my_stack::stack_full(){
  if(top >=SIZE) // 이것도 있고  (top ==SIZE) 이것도 있음 
   return true;
  else 
   return false; 
}

bool is_operand(char cc){
  if( cc=='(' || cc==')' || cc =='+' || cc =='-'|| cc =='*'|| cc =='/'|| cc =='%'|| cc =='$')
   return false; 
  else 
   return true;
}

int op_priority(char c){
  if(c =='%' ||c== '*' ||c== '/')
   return 2;
  else if (c =='+'||c=='-')
   return 1;
  else 
   return 0;  
}



int main() {
  string input,output; 
  my_stack s1; 

  std::cout << "Input an infix :" ;
  std::cin >> input; 
  
  input += EOS;
  s1.push(EOS);

  for(int i=0; i<input.size();i++)
  {
    if(is_operand(input[i])) //operand 면 바로 출력 
      output += input[i];

    else if(input[i] == '(')  // 여는 괄호의 경우
      s1.push(input[i]);

    else if(input[i]==')') {   // 닫는 괄호의 경우
     while(s1.top_element()!='('){  
       output += s1.pop();
     }
     s1.pop();  // 여는 괄호 삭제 
    }

    else if( op_priority(input[i]) > op_priority(s1.top_element()) ) // 해당 op가 우선순위가 높은 경우 스택
           s1.push(input[i]);

    else if( op_priority(input[i]) <= op_priority(s1.top_element()) ) { // 해당 op 우선순위가 top보다 낮아질때까지 pop 
    while ( op_priority(input[i]) <= op_priority(s1.top_element())){  
       if(s1.top_element()==EOS)   // EOS를 만나면 지구 끝까지 pop을 해서 제한걸기
        break; 
       output += s1.pop(); 
       std::cout<<"top :  "<<s1.top_element()<<std::endl;  // top에 뭐있나 체크 
     }
     s1.push(input[i]); // 이제 자기보다 높은 애 없으면 들어감 
    }

    std::cout<<"top :  "<<s1.top_element()<<std::endl;  // top에 뭐있나 체크 
    std::cout<<"output : "<<output<<std::endl;  // 변환과정
  }


  std::cout<<"\n\n Postfix : "<<output; 


return 0;
}


// 9-6/3+8*(2+1)
// 963/821+*+- 
// 답 963/-821+*+


//a*(b+c)-d/e
//abc+*de/-