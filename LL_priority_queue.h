#ifndef LL_PRIORITY_QUEUE_H_INCLUDED
#define LL_PRIORITY_QUEUE_H_INCLUDED

struct Data
{
    char Stock_Name[20];
    int Price;
    int Priority; //1-5
    struct Data* Next;
};
typedef struct Data Object;
struct Linked_Nodes
{
    int Max_Size;
    int Size;
    int Count;
    int Counter;
    Object* Front;
    Object* Rear;
    Object* Max;
    Object* Min;
    Object* Lead;
    Object* Lag;

};
typedef struct Linked_Nodes Object_Node;
Object_Node create_q(int);
Object_Node enqueue(Object_Node,Object,int);
Object_Node dequeue(Object_Node);
Object_Node merge(Object_Node,Object_Node);
Object peek(Object_Node);
Object_Node clear(Object_Node);
int is_empty(Object_Node);
int Size(Object_Node);
Object_Node store(Object_Node,FILE*);
Object_Node load(Object_Node,FILE*);




#endif // LL_PRIORITY_QUEUE_H_INCLUDED

