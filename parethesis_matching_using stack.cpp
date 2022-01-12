#include<iostream>
using namespace std;
class stack{
char*a;
int top;
public:
   stack(){
   top=-1;
   }
   void createstack(int size){
   a=new char[size];
   }
   void push(int data){
    top++;
    a[top]=data;
   }


   bool isempty(){
   if(top==-1){
    return true;
   }else{
   return false;
   }
   }
   void pop(){
   if(top==-1){
    cout<<"stack undeflow\n";
   }else{
       top--;
   }

   }
   char peek(){
   return a[top];
   }
 bool check(string name){
int i;
char x;
for(i=0;i<name.length();i++){
    if(name[i]=='('||name[i]=='{'||name[i]=='['){
        push(name[i]);
       }
    if(isempty()){
        return false;
    }
    switch(name[i]){
case ')':
    x=peek();
    pop();
    if(x=='['||x=='{'){
        return false;
    }
    break;
case ']':
x=peek();
pop();
if(x=='{'||x=='('){
    return false;
   }
   break;
case '}':
    x=peek();
    pop();
    if(x=='['||x=='('){
        return false;
       }
       break;
    }

}
return true;
}

};
main(){
stack obj;
string name="{()}[]";
obj.createstack(name.length());
if(obj.check(name)){
    cout<<"bal";
}else{
cout<<"not bal";
}
}

