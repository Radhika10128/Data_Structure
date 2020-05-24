#include<stdio.h>
#include<stdlib.h>
#define bool int

struct sNode{
int data;
struct sNode* next;
};
bool isMatching(char chara1,char chara2)
{
    if(chara1=='{' && chara2=='}')
        return 1;
    else if(chara1=='(' && chara2==')')
        return 1;
    else if(chara1=='[' && chara2==']')
        return 1;
    else
        return 0;
}
void push(struct sNode** stack,int data)
{
    struct sNode* newnode=(struct sNode*)malloc(sizeof(struct sNode));
    newnode->data=data;
    newnode->next=*stack;
    *stack=newnode;
}
int pop(struct sNode** stack)
{
    char res;
    struct sNode* top;
    top=*stack;
    res=top->data;
    *stack=top->next;
    free(top);
    return res;
}
bool areParenthesisBalanced(char exp[])
{
    int i=0;
    struct sNode *stack=NULL;
    while(exp[i])
    {
        if(exp[i]=='{' || exp[i]=='(' || exp[i]=='[')
            push(&stack,exp[i]);
        else if(exp[i]=='}' || exp[i]==')' || exp[i]==']')
        {
            if(stack==NULL)
                return 0;
            else if(!isMatching(pop(&stack),exp[i]))
                return 0;
        }
            i++;
    }
    if(stack==NULL)
        return 1;
    else
        return 0;
}
int main()
{
char exp[100] = "{()}[]";
  if (areParenthesisBalanced(exp))
    printf("Balanced \n");
  else
    printf("Not Balanced \n");
  return 0;
}
