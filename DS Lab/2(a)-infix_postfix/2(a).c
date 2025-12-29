#include <stdio.h>
#include <string.h>
#include <ctype.h>
#define max 30
int top=-1;
int stack[max];

void push(char c){
    if (top==max-1){
        printf("overflow");
    }
    else{
        stack[++top]=c;
    }
}
char pop(){
    if (top==-1){
        printf("underflow");
        return -1;
    }
    else{
        return stack[top--];
    }
}
int peek(){
    if (top==-1){
        printf("underflow");
        return 0;
    }
    else{
        return stack[top];
    }
}

int precedence(char op){
    switch (op){
        case '+':
        case '-':
        return 1;
        case '*':
        case '/':
        return 2;
        case '^':
        return 3;
        case '(':
        return 0;

    }
    return -1;
}

int associativity(char op){
    if (op=='^'){
        return 1;
    }
    else{
        return 0;
    }
}

void infixtopostfix(char infix[],char postfix[]){
    int k=0;

    for (int i=0;infix[i]!='\0';i++){
    char c= infix[i];

    if (isalnum(c)){
        postfix[k++]=c;
    }
    else if(c=='('){
        push(c);
    }
    else if (c==')'){
        while (top!=-1 && peek()!='('){
            postfix[k++]=pop();

        }
        pop();
    }
    else{
        while(top!=-1 && ((precedence(peek())>precedence(c)) || (precedence(peek())==precedence(c) && associativity(c)==0))){
            postfix[k++]=pop();
        }
        push(c);
    }
    }
    while(top!=-1){
        postfix[k++]=pop();
    }
    postfix[k]='\0';
}

int main(){
    char inf[50],post[50];
    printf("enter exp:");
    gets(inf);
    infixtopostfix(inf,post);
    printf("postfic exp is: %s",post);
    return 0;
}
