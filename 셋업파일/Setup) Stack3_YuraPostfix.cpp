#include <stdio.h>
#include <string>
#define SIZE 100
#define EOS '$'
#include <iostream> 
using namespace std;

class op_stack {
   char s[SIZE];
   int top;
public:
   op_stack();
   void push(char x);
   char pop();
   bool empty();
   char top_element();
};
op_stack::op_stack() {
   top = 0;
}
void op_stack::push(char x) {
   s[top] = x;
   top++;
}
char op_stack::pop() {
   top--;
   return(s[top]);
}
bool op_stack::empty() {
   return(top == 0);
}
char op_stack::top_element() {
   return (s[top - 1]);
}
bool operand(char op) {
   if ((op == '(') || (op == ')') || (op == '+') || (op == '-') || (op == '*') || (op == '/') || (op == '%') || (op == '$'))
      return false;
   else
      return true;
}
int get_precedence(char op)
{
   if ((op == '$') || (op == '('))
      return(0);
   if ((op == '+') || (op == '-') )
      return(1);
   if ((op == '*') || (op == '/') || (op == '%') )
      return(2);
}

int main() {
   int i;
   int pre, pre1;
   string input, output;
   op_stack s1;
   char now;
   cout << "Infix expression: ";
   cin >> input;
   
   s1.push(EOS);
   for (i = 0; i < input.size(); i++) {
      if (operand(input[i]))
         output += input[i];
      else if (input[i] == '(')
         s1.push(input[i]);
      else if (input[i] == ')') {
         while (1) {
            now = s1.pop();
            if (now != '(')
               output += now;
            else {
               break;
            }
   
         }
      }
      else if (!operand(input[i])) {
         pre = get_precedence(input[i]);
         pre1 = get_precedence(s1.top_element());
         if (pre >= pre1)
            s1.push(input[i]);
         else {
            while(1){
               if (pre > get_precedence(s1.top_element())){
                  s1.push(input[i]);
                  break;
               }
               else
                  output += s1.pop();
               
            }
         }

      }

   }
   while (!s1.empty())
      output += s1.pop();

   cout << output;
}

//9-6/3+8*(2+1)
//963/-821+*+  