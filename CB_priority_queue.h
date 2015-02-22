#ifndef PRIORITY_QUEUE_H_INCLUDED
#define PRIORITY_QUEUE_H_INCLUDED

struct CB_Data
{
    char Stock_Name[20];
    int Price;
    int Key;
    int Priority;
};
typedef struct CB_Data CB_Object;

struct CB_Nodes
{
    CB_Object* Front;
    CB_Object* Rear;
    CB_Object* First;
    int Size;
    int Count;
    int Counter;

};
typedef struct CB_Nodes CB_Object_Node;

CB_Object_Node CB_create_q(int);
CB_Object_Node CB_enqueue(CB_Object_Node,CB_Object,int);
CB_Object_Node CB_dequeue(CB_Object_Node);
CB_Object_Node CB_merge(CB_Object_Node,CB_Object_Node);
CB_Object CB_peek(CB_Object_Node);
CB_Object_Node CB_clear(CB_Object_Node);
int CB_is_empty(CB_Object_Node);
int CB_size(CB_Object_Node);
CB_Object_Node CB_get_First_Node(CB_Object_Node);
CB_Object_Node CB_store(CB_Object_Node,FILE*);
CB_Object_Node CB_load(CB_Object_Node,FILE*);

#endif // PRIORITY_QUEUE_H_INCLUDED
