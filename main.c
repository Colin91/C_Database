#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "LL_priority_queue.h"
#include "CB_priority_queue.h"


struct LL_Queueu

{
    int Key[1000];
    int Rear_Node;
    Object_Node Queue_Node[1000]; //contains pointer to the 1st object of each queue
};
typedef struct LL_Queueu ListOfQ;


struct CB_Queueu
{
    int Key[1000];
    int Rear_Node;
    CB_Object_Node Queue_Node[1000]; //contains pointer to the 1st object of each queue
};
typedef struct CB_Queueu CB_ListOfQ;

void Existing_Q(ListOfQ,int);
void CB_Existing_Q(CB_ListOfQ,int);


int main()
{
    int size=0;
    int Price;
    char Stock_Name[20];
    int Count=0;
    int choice=0;
    int Queue_Counter=0;
    int Queue_key=0;
    int Queue_key1=0;
    int Queue_key2=0;

    int CB_Queue_Counter=0;
    int CB_Queue_key=0;
    int CB_Queue_key1=0;
    int CB_Queue_key2=0;
    CB_Object CB_OBL2;
    CB_Object_Node CB_OBL;

    int List=0;
    int LL_FLAG=0;
    int CB_FLAG=0;

    int Priority=0;
    int Element=0;
    int ret_empty=0;
    int ret_size=0;
    int i=0;
    int Check_Input=0;
    int input;
    Object OBL;
    Object TestPeek;
    Object OBL_2;
    Object_Node OBN;
    Object* Loop_OBL;
    Object_Node OBN_2;
    Object_Node OBN_3;
    FILE* FP;

    ListOfQ LOQ;
    CB_ListOfQ CB_LOQ;

    printf("WELCOME TO THE STOCK TRADING SYSTEM\n");

    printf("=================MENU===============\n");
    printf("[1] Create Queue\n");
    printf("[2] Enqueue To Queue\n");
    printf("[3] Dequeue From Queue\n");
    printf("[4] Merge Two Queues\n");
    printf("[5] Peek Maximum of Queue\n");
    printf("[6] Check if Queue is Empty\n");
    printf("[7] Size of Queue\n");
    printf("[8] Save Queue\n");
    printf("[9] Load Queue\n");
    printf("[10] Clear Queue\n");
    printf("[11] List Queue\n");
    printf("[0] Quit\n");
    do
    {
        start:
        Queue_key=0;
        Queue_key1=0;
        Queue_key2=0;
        CB_Queue_key=0;
        CB_Queue_key1=0;
        CB_Queue_key2=0;
        Priority=0;
        Element=0;

        printf(" ---------------------------------------------------------------\n");
        printf("| [1]Create [2]Enqueue [3]Dequeue [4]Merge  [5]Peek  [6]Is Empty|\n");
        printf("| [7]Size   [8]Save    [9]Load    [10]Clear [11]List [0]Quit    |\n");
        printf(" ---------------------------------------------------------------\n");

        printf("Enter Selection : \n");
        printf("===============================\n");
        fflush(stdin);
        Check_Input=scanf(" %d",&input);

        if(Check_Input!=1)
        {
            printf("Invalid Number\n");
            goto start;
        }
        Check_Input=0;

        if(input>11||input<0)
        {
            printf("Selection range 1-11 . Please re-enter Selection\n");
            goto start;
        }

        if(Queue_Counter==0&&CB_Queue_Counter==0&&(input>1||input<1))
        {
            printf("Currently there exists NO Queues in ANY Format. Create a Queue by Pressing [1] in the Menu\n");
            goto start;
        }
        if(Queue_Counter==0)
        {
            LL_FLAG=0;
        }
        else{ LL_FLAG = 1;}
        if(CB_Queue_Counter==0)
        {
            CB_FLAG=0;
        }
        else{ CB_FLAG = 1;}


        switch(input)
        {
 // =================================================================================================================
            case 1:

                printf("Enter Size of Queue:\n");
                Check_Input=scanf("%d",&size);
                if(Check_Input!=1)
                {
                    printf("--Invalid Input--\n");
                    goto start;
                }

                printf("Choose Type of Queue: Press[1] For Linked List , Press[2] For Circular Buffer\n");
                Check_Input=scanf("%d",&List); //  1 or 2
                if(Check_Input!=1||(List>2||List<1))
                {
                    printf("--Invalid Input--\n");
                    goto start;
                }

                if(List==1) //Linked List
                {
                    LOQ.Queue_Node[Queue_Counter]=create_q(size);
                    LOQ.Key[Queue_Counter]=Queue_Counter;
                    Queue_Counter++;
                }
                if(List==2) //Circular Buffer
                {
                    CB_LOQ.Queue_Node[CB_Queue_Counter]=CB_create_q(size);
                    CB_LOQ.Key[CB_Queue_Counter]=CB_Queue_Counter;
                    CB_Queue_Counter++;
                }

                break;
 // =================================================================================================================
            case 2:

                printf("Choose Type of Queue: Press[1] For Linked List , Press[2] For Circular Buffer\n");
                Check_Input=scanf("%d",&List); //  1 or 2
                if(Check_Input!=1||(List>2||List<1))
                {
                    printf("--Invalid Input--\n");
                    goto start;
                }

                if(List==1&&LL_FLAG==1)
                {
                    printf("Enter Queue Key to Enqueue to:\n");
                    Existing_Q(LOQ,Queue_Counter);
                    Check_Input=scanf("%d",&Queue_key);
                    if(Check_Input!=1||Queue_key<0||Queue_key>Queue_Counter)
                    {
                        printf("--Invalid Input--\n");
                        goto start;
                    }

                    if(Queue_key>=0&&Queue_key<Queue_Counter)
                    {
                        do
                        {
                            printf("------------------------\n");
                            printf("Enter Stock Name :\n");
                            scanf("%s",OBL.Stock_Name);
                            printf("Enter Price of Stock :\n");
                            scanf("%d",&OBL.Price);
                            printf("Enter Priority value :\n");
                            scanf("%d",&Priority);
                            printf("------------------------\n");
                            LOQ.Queue_Node[Queue_key]=enqueue(LOQ.Queue_Node[Queue_key],OBL,Priority);
                            printf(" ------------------------------------------------------\n");
                            printf("Enter another Value[Any Number] or go to Main Menu[9] ?:\n");
                            printf(" ------------------------------------------------------\n");
                            Check_Input=scanf("%d",&choice);
                            if(Check_Input!=1)
                            {
                                printf("--Invalid Input--\n");
                                goto start;
                            }

                        }while(choice!=9);
                    }
                    else
                    {
                        printf("Queue Does not Exist\n");
                        printf("-------------------------\n");
                        goto start;
                    }

                }
                if(List==2&&CB_FLAG==1)
                {
                    printf("Enter Queue Key to Enqueue to:\n");
                    CB_Existing_Q(CB_LOQ,CB_Queue_Counter);
                    Check_Input=scanf("%d",&CB_Queue_key);
                    if(Check_Input!=1||CB_Queue_key<0||CB_Queue_key>CB_Queue_Counter)
                    {
                        printf("--Invalid Input--\n");
                        goto start;
                    }

                    if(CB_Queue_key>=0&&CB_Queue_key<CB_Queue_Counter)
                    {
                        do
                        {
                            printf("------------------------\n");
                            printf("Enter Stock Name :\n");
                            scanf("%s",CB_OBL2.Stock_Name);
                            printf("Enter Price of Stock :\n");
                            scanf("%d",&CB_OBL2.Price);
                            printf("Enter Priority value :\n");
                            scanf("%d",&Priority);
                            printf("------------------------\n");
                            CB_LOQ.Queue_Node[CB_Queue_key]=CB_enqueue(CB_LOQ.Queue_Node[CB_Queue_key],CB_OBL2,Priority);
                            printf(" ------------------------------------------------------\n");
                            printf("Enter another Value[Any Number] or go to Main Menu[9] ?:\n");
                            printf(" ------------------------------------------------------\n");
                            Check_Input=scanf("%d",&choice);
                            if(Check_Input!=1)
                            {
                                printf("--Invalid Input--\n");
                                goto start;
                            }

                        }while(choice!=9);
                    }
                    else
                    {
                        printf("Queue Does not Exist\n");
                        printf("-------------------------\n");
                        goto start;
                    }

                }

                break;
// =================================================================================================================\\DEQUEUE
            case 3:

                 printf("Choose Type of Queue: Press[1] For Linked List , Press[2] For Circular Buffer\n");
                 Check_Input=scanf("%d",&List); //  1 or 2
                 if(Check_Input!=1||(List>2||List<1))
                 {
                     printf("--Invalid Input--\n");
                     goto start;
                 }

                 if(List==1&&LL_FLAG==1)
                 {
                     printf("Enter Queue Key to Dequeue From:\n");
                     Existing_Q(LOQ,Queue_Counter);
                     Check_Input=scanf("%d",&Queue_key);
                     if(Check_Input!=1||Queue_key<0||Queue_key>Queue_Counter)
                     {
                         printf("--Invalid Input--\n");
                         goto start;
                     }

                     if(Queue_key>=0||Queue_key<Queue_Counter)
                     {
                         LOQ.Queue_Node[Queue_key]=dequeue(LOQ.Queue_Node[Queue_key]);
                     }
                     else
                     {
                         printf("Queue Does not Exist\n");
                         printf("-------------------------\n");
                         goto start;
                     }
                 }

                 if(List==2&&CB_FLAG==1)
                 {
                     printf("Enter Queue Key to Dequeue From:\n");
                     CB_Existing_Q(CB_LOQ,CB_Queue_Counter);
                     Check_Input=scanf("%d",&CB_Queue_key);
                     if(Check_Input!=1||CB_Queue_key<0||CB_Queue_key>CB_Queue_Counter)
                     {
                         printf("--Invalid Input--\n");
                         goto start;
                     }

                     if(CB_Queue_key>=0||CB_Queue_key<CB_Queue_Counter)
                     {
                         CB_LOQ.Queue_Node[CB_Queue_key]=CB_dequeue(CB_LOQ.Queue_Node[CB_Queue_key]);
                     }
                     else
                     {
                         printf("Queue Does not Exist\n");
                         printf("-------------------------\n");
                         goto start;
                     }
                 }

                 break;
 // =================================================================================================================//MERGE
            case 4:

                printf("Choose Type of Queue: Press[1] For Linked List , Press[2] For Circular Buffer\n");
                Check_Input=scanf("%d",&List); //  1 or 2
                if(Check_Input!=1||(List>2||List<1))
                {
                    printf("--Invalid Input--\n");
                    goto start;
                }

                if(List==1&&LL_FLAG==1)
                {
                     printf("Enter First Queue Key:\n");
                     Existing_Q(LOQ,Queue_Counter);
                     Check_Input=scanf("%d",&Queue_key1);
                     if(Check_Input!=1||Queue_key<0||Queue_key>Queue_Counter)
                     {
                         printf("--Invalid Input--\n");
                         goto start;
                     }

                     printf("Enter Second Queue Key:\n");
                     Existing_Q(LOQ,Queue_Counter);
                     Check_Input=scanf("%d",&Queue_key2);
                     if(Check_Input!=1||Queue_key2<0||Queue_key2>Queue_Counter)
                     {
                         printf("--Invalid Input--\n");
                         goto start;
                     }

                     if(Queue_key>=0||Queue_key<Queue_Counter)
                     {
                         LOQ.Key[Queue_Counter]=Queue_Counter;
                         LOQ.Queue_Node[Queue_Counter]=merge(LOQ.Queue_Node[Queue_key1],LOQ.Queue_Node[Queue_key2]);
                         Queue_Counter++;
                     }
                     else
                     {
                         printf("Queue Does not Exist\n");
                         printf("-------------------------\n");
                         goto start;
                     }
                }

                if(List==2&&CB_FLAG==1)
                {
                     printf("Enter First Queue Key:\n");
                     CB_Existing_Q(CB_LOQ,CB_Queue_Counter);
                     Check_Input=scanf("%d",&CB_Queue_key1);
                     if(Check_Input!=1||CB_Queue_key1<0||CB_Queue_key1>CB_Queue_Counter)
                     {
                         printf("--Invalid Input--\n");
                         goto start;
                     }

                     printf("Enter Second Queue Key:\n");
                     CB_Existing_Q(CB_LOQ,CB_Queue_Counter);
                     Check_Input=scanf("%d",&CB_Queue_key2);
                     if(Check_Input!=1||CB_Queue_key2<0||CB_Queue_key2>CB_Queue_Counter)
                     {
                         printf("--Invalid Input--\n");
                         goto start;
                     }

                     if(CB_Queue_key>=0||CB_Queue_key<CB_Queue_Counter)
                     {
                         CB_LOQ.Key[CB_Queue_Counter]=CB_Queue_Counter;
                         CB_LOQ.Queue_Node[CB_Queue_Counter]=CB_merge(CB_LOQ.Queue_Node[CB_Queue_key1],CB_LOQ.Queue_Node[CB_Queue_key2]);
                         CB_Queue_Counter++;
                     }
                     else
                     {
                         printf("Queue Does not Exist\n");
                         printf("-------------------------\n");
                         goto start;
                     }
                }

                break;
 // =================================================================================================================//PEEK
            case 5:

                printf("Choose Type of Queue: Press[1] For Linked List , Press[2] For Circular Buffer\n");
                Check_Input=scanf("%d",&List); //  1 or 2
                if(Check_Input!=1||(List>2||List<1))
                {
                    printf("--Invalid Input--\n");
                    goto start;
                }

                if(List==1&&LL_FLAG==1)
                {
                    printf("Enter Queue Key to get Max:\n");
                    Existing_Q(LOQ,Queue_Counter);
                    Check_Input=scanf("%d",&Queue_key);
                    if(Check_Input!=1||Queue_key<0||Queue_key>Queue_Counter)
                    {
                        printf("--Invalid Input--\n");
                        goto start;
                    }

                    if(Queue_key>=0||Queue_key<Queue_Counter)
                    {
                        OBL=peek(LOQ.Queue_Node[Queue_key]);
                        printf("| Stock Name : %s      \n",OBL.Stock_Name);
                        printf("| Price      : %d      \n",OBL.Price);
                        printf("| Priority   : %d      \n",OBL.Priority);

                    }
                    else
                    {
                        printf("Queue Does not Exist\n");
                        printf("-------------------------\n");
                        goto start;
                    }
                }

                if(List==2&&CB_FLAG==1)
                {
                    printf("Enter Queue Key to get Max:\n");
                    CB_Existing_Q(CB_LOQ,CB_Queue_Counter);
                    Check_Input=scanf("%d",&CB_Queue_key);
                    if(Check_Input!=1||CB_Queue_key<0||CB_Queue_key>CB_Queue_Counter)
                    {
                        printf("--Invalid Input--\n");
                        goto start;
                    }


                    if(CB_Queue_key>=0||CB_Queue_key<CB_Queue_Counter)
                    {
                        CB_OBL2=CB_peek(CB_LOQ.Queue_Node[CB_Queue_key]);
                        printf("| Stock Name : %s      \n",CB_OBL2.Stock_Name);
                        printf("| Price      : %d      \n",CB_OBL2.Price);
                        printf("| Priority   : %d      \n",CB_OBL2.Priority);
                    }
                    else
                    {
                        printf("Queue Does not Exist\n");
                        printf("-------------------------\n");
                        goto start;
                    }
                }

                break;
 // =================================================================================================================//is empty
            case 6:

                printf("Choose Type of Queue: Press[1] For Linked List , Press[2] For Circular Buffer\n");
                Check_Input=scanf("%d",&List); //  1 or 2
                if(Check_Input!=1||(List>2||List<1))
                {
                    printf("--Invalid Input--\n");
                    goto start;
                }

                if(List==1&&LL_FLAG==1)
                {
                    printf("Enter Queue Key to check if Queue is Empty:\n");
                    Existing_Q(LOQ,Queue_Counter);
                    Check_Input=scanf("%d",&Queue_key);
                    if(Check_Input!=1||Queue_key<0||Queue_key>Queue_Counter)
                    {
                        printf("--Invalid Input--\n");
                        goto start;
                    }

                    if(Queue_key>=0||Queue_key<Queue_Counter)
                    {
                        ret_empty=is_empty(LOQ.Queue_Node[Queue_key]);
                        if(ret_empty==1)
                        {
                            printf("Queue [%d] is empty\n",Queue_key);
                        }
                        else
                        {
                            printf("Queue [%d] is not empty\n",Queue_key);
                        }

                    }
                    else
                    {
                        printf("Queue Does not Exist\n");
                        printf("-------------------------\n");
                        goto start;
                    }
                }

                if(List==2&&CB_FLAG==1)
                {
                    printf("Enter Queue Key to check if Queue is Empty:\n");
                    CB_Existing_Q(CB_LOQ,CB_Queue_Counter);
                    Check_Input=scanf("%d",&CB_Queue_key);
                    if(Check_Input!=1||CB_Queue_key<0||CB_Queue_key>CB_Queue_Counter)
                    {
                        printf("--Invalid Input--\n");
                        goto start;
                    }

                    if(CB_Queue_key>=0||CB_Queue_key<CB_Queue_Counter)
                    {
                        ret_empty=CB_is_empty(CB_LOQ.Queue_Node[CB_Queue_key]);
                        if(ret_empty==1)
                        {
                            printf("Queue [%d] is empty\n",CB_Queue_key);
                        }
                        else
                        {
                            printf("Queue [%d] is not empty\n",CB_Queue_key);
                        }

                    }
                    else
                    {
                        printf("Queue Does not Exist\n");
                        printf("-------------------------\n");
                        goto start;
                    }
                }

                break;
// =================================================================================================================//Size
            case 7:

                printf("Choose Type of Queue: Press[1] For Linked List , Press[2] For Circular Buffer\n");
                Check_Input=scanf("%d",&List); //  1 or 2
                if(Check_Input!=1||(List>2||List<1))
                {
                    printf("--Invalid Input--\n");
                    goto start;
                }

                if(List==1&&LL_FLAG==1)
                {
                    printf("Enter Queue Key to check the Size of Queue:\n");
                    Existing_Q(LOQ,Queue_Counter);
                    Check_Input=scanf("%d",&Queue_key);
                    if(Check_Input!=1||Queue_key<0||Queue_key>Queue_Counter)
                    {
                        printf("--Invalid Input--\n");
                        goto start;
                    }

                    if(Queue_key>=0||Queue_key<Queue_Counter)
                    {
                        ret_size=Size(LOQ.Queue_Node[Queue_key]);
                        printf("Queue [%d] Size is %d\n",Queue_key,ret_size);
                    }
                    else
                    {
                        printf("Queue Does not Exist\n");
                        printf("-------------------------\n");
                        goto start;
                    }
                }
                if(List==2&&CB_FLAG==1)
                {
                    printf("Enter Queue Key to check the Size of Queue:\n");
                    CB_Existing_Q(CB_LOQ,CB_Queue_Counter);
                    Check_Input=scanf("%d",&CB_Queue_key);
                    if(Check_Input!=1||CB_Queue_key<0||CB_Queue_key>CB_Queue_Counter)
                    {
                        printf("--Invalid Input--\n");
                        goto start;
                    }

                    if(CB_Queue_key>=0||CB_Queue_key<CB_Queue_Counter)
                    {
                        ret_size=CB_size(CB_LOQ.Queue_Node[CB_Queue_key]);
                        printf("Queue [%d] Size is %d\n",CB_Queue_key,ret_size);
                    }
                    else
                    {
                        printf("Queue Does not Exist\n");
                        printf("-------------------------\n");
                        goto start;
                    }
                }

                break;
 // =================================================================================================================
            case 8:

                printf("Choose Type of Queue: Press[1] For Linked List , Press[2] For Circular Buffer\n");
                Check_Input=scanf("%d",&List); //  1 or 2
                if(Check_Input!=1||(List>2||List<1))
                {
                    printf("--Invalid Input--\n");
                    goto start;
                }

                if(List==1&&LL_FLAG==1)
                {
                    printf("Enter Queue Key to Save Queue:\n");
                    Existing_Q(LOQ,Queue_Counter);
                    Check_Input=scanf("%d",&Queue_key);
                    if(Check_Input!=1||Queue_key<0||Queue_key>Queue_Counter)
                    {
                        printf("--Invalid Input--\n");
                        goto start;
                    }

                    if(Queue_key>=0||Queue_key<Queue_Counter)
                    {
                        LOQ.Queue_Node[Queue_key]=store(LOQ.Queue_Node[Queue_key],FP);
                    }
                    else
                    {
                        printf("Queue Does not Exist\n");
                        printf("-------------------------\n");
                        goto start;
                    }
                }

                if(List==2&&CB_FLAG==1)
                {
                    printf("Enter Queue Key to Save Queue:\n");
                    CB_Existing_Q(CB_LOQ,CB_Queue_Counter);
                    Check_Input=scanf("%d",&CB_Queue_key);
                    if(Check_Input!=1||CB_Queue_key<0||CB_Queue_key>CB_Queue_Counter)
                    {
                        printf("--Invalid Input--\n");
                        goto start;
                    }

                    if(CB_Queue_key>=0||CB_Queue_key<CB_Queue_Counter)
                    {
                        CB_LOQ.Queue_Node[CB_Queue_key]=CB_store(CB_LOQ.Queue_Node[CB_Queue_key],FP);
                    }
                    else
                    {
                        printf("Queue Does not Exist\n");
                        printf("-------------------------\n");
                        goto start;
                    }

                }

                break;
 // =================================================================================================================
            case 9:

                printf("Choose Type of Queue: Press[1] For Linked List , Press[2] For Circular Buffer\n");
                Check_Input=scanf("%d",&List); //  1 or 2
                if(Check_Input!=1||(List>2||List<1))
                {
                    printf("--Invalid Input--\n");
                    goto start;
                }

                if(List==1&&LL_FLAG==1)
                {
                    printf("Enter Queue Key to Load Queue:\n");
                    Existing_Q(LOQ,Queue_Counter);
                    Check_Input=scanf("%d",&Queue_key);
                    if(Check_Input!=1||Queue_key<0||Queue_key>Queue_Counter)
                    {
                        printf("--Invalid Input--\n");
                        goto start;
                    }

                    if(Queue_key>=0||Queue_key<Queue_Counter)
                    {
                        LOQ.Queue_Node[Queue_key]=load(LOQ.Queue_Node[Queue_key],FP);
                    }
                    else
                    {
                        printf("Queue Does not Exist\n");
                        printf("-------------------------\n");
                        goto start;
                    }
                }

                if(List==2&&CB_FLAG==1)
                {
                    printf("Enter Queue Key to Load Queue:\n");
                    CB_Existing_Q(CB_LOQ,CB_Queue_Counter);
                    Check_Input=scanf("%d",&CB_Queue_key);
                    if(Check_Input!=1||CB_Queue_key<0||CB_Queue_key>CB_Queue_Counter)
                    {
                        printf("--Invalid Input--\n");
                        goto start;
                    }

                    if(CB_Queue_key>=0||CB_Queue_key<CB_Queue_Counter)
                    {
                        CB_LOQ.Queue_Node[CB_Queue_key]=CB_load(CB_LOQ.Queue_Node[CB_Queue_key],FP);
                    }
                    else
                    {
                        printf("Queue Does not Exist\n");
                        printf("-------------------------\n");
                        goto start;
                    }
                }


                break;
 // =================================================================================================================//CLEAR
            case 10:

                printf("Choose Type of Queue: Press[1] For Linked List , Press[2] For Circular Buffer\n");
                Check_Input=scanf("%d",&List); //  1 or 2
                if(Check_Input!=1||(List>2||List<1))
                {
                    printf("--Invalid Input--\n");
                    goto start;
                }

                if(List==1&&LL_FLAG==1)
                {
                    printf("Enter Queue Key to Load Queue:\n");
                    Existing_Q(LOQ,Queue_Counter);
                    Check_Input=scanf("%d",&Queue_key);
                    if(Check_Input!=1||Queue_key<0||Queue_key>Queue_Counter)
                    {
                        printf("--Invalid Input--\n");
                        goto start;
                    }

                    if(Queue_key>=0||Queue_key<Queue_Counter)
                    {
                         LOQ.Queue_Node[Queue_key]=clear(LOQ.Queue_Node[Queue_key]);
                    }
                    else
                    {
                        printf("Queue Does not Exist\n");
                        printf("-------------------------\n");
                        goto start;
                    }

                }

                if(List==2&&CB_FLAG==1)
                {
                    printf("Enter Queue Key to Load Queue:\n");
                    CB_Existing_Q(CB_LOQ,CB_Queue_Counter);
                    Check_Input=scanf("%d",&CB_Queue_key);
                    if(Check_Input!=1||CB_Queue_key<0||CB_Queue_key>CB_Queue_Counter)
                    {
                        printf("--Invalid Input--\n");
                        goto start;
                    }

                    if(CB_Queue_key>=0||CB_Queue_key<CB_Queue_Counter)
                    {
                         CB_LOQ.Queue_Node[CB_Queue_key]=CB_clear(CB_LOQ.Queue_Node[CB_Queue_key]);
                    }
                    else
                    {
                        printf("Queue Does not Exist\n");
                        printf("-------------------------\n");
                        goto start;
                    }

                }

                break;
// =================================================================================================================

            case 11:

                printf("Choose Type of Queue: Press[1] For Linked List , Press[2] For Circular Buffer\n");
                Check_Input=scanf("%d",&List); //  1 or 2
                if(Check_Input!=1||(List>2||List<1))
                {
                    printf("--Invalid Input--\n");
                    goto start;
                }

                if(List==1&&LL_FLAG==1)
                {
                    printf("Enter Queue Key:\n");
                    Existing_Q(LOQ,Queue_Counter);
                    Check_Input=scanf("%d",&Queue_key);
                    if(Check_Input!=1||Queue_key<0||Queue_key>Queue_Counter)
                    {
                        printf("--Invalid Input--\n");
                        goto start;
                    }

                    if(Queue_key>=0||Queue_key<Queue_Counter)
                    {
                        ret_empty=is_empty(LOQ.Queue_Node[Queue_key]);
                        if(ret_empty==0)
                        {
                            for(Loop_OBL=LOQ.Queue_Node[Queue_key].Max;Loop_OBL!=LOQ.Queue_Node[Queue_key].Min->Next;Loop_OBL=Loop_OBL->Next) //FOR LINKED LISTS
                            {
                                printf("----------------------\n");
                                printf("| Stock Name : %s      \n",Loop_OBL->Stock_Name);
                                printf("| Price      : %d      \n",Loop_OBL->Price);
                                printf("| Priority   : %d      \n",Loop_OBL->Priority);
                                printf("----------------------\n");

                            }

                        }
                        else
                        {
                                printf("List is Empty\n");
                                goto start;
                        }

                    }
                    else
                    {
                        printf("Queue Does not Exist\n");
                        printf("-------------------------\n");
                        goto start;

                    }

                }

                if(List==2&&CB_FLAG==1)
                {
                    printf("Enter Queue Key:\n");
                    CB_Existing_Q(CB_LOQ,CB_Queue_Counter);
                    Check_Input=scanf("%d",&CB_Queue_key);
                    if(Check_Input!=1||CB_Queue_key<0||CB_Queue_key>CB_Queue_Counter)
                    {
                        printf("--Invalid Input--\n");
                        goto start;
                    }

                    CB_LOQ.Queue_Node[CB_Queue_key].Count;

                    if(CB_Queue_key>=0||CB_Queue_key<CB_Queue_Counter)
                    {
                        ret_empty=CB_is_empty(CB_LOQ.Queue_Node[CB_Queue_key]);
                        if(ret_empty==0)
                        {
                            for(i=0;i<=CB_LOQ.Queue_Node[CB_Queue_key].Count;i++) //FOR Circular Buffer
                            {
                                printf("----------------------\n");
                                printf("| Stock Name : %s      \n",CB_LOQ.Queue_Node[CB_Queue_key].Front[i].Stock_Name);
                                printf("| Price      : %d      \n",CB_LOQ.Queue_Node[CB_Queue_key].Front[i].Price);
                                printf("| Priority   : %d      \n",CB_LOQ.Queue_Node[CB_Queue_key].Front[i].Priority);
                                printf("----------------------\n");
                            }

                        }
                        else
                        {
                            printf("List is Empty\n");
                            goto start;
                        }


                    }
                    else
                    {
                        printf("Queue Does not Exist\n");
                        printf("-------------------------\n");
                        goto start;

                    }

                }

                break;

        }
    }while(input!=0);


    return 0;
}

void Existing_Q(ListOfQ LOQ_In,int Count)
{
    int i;
    printf("Current Number of Queues and Keys:\n");
    printf("Linked Lists [");
    for(i=0;i<Count;i++)
    {
        printf("%d ,",LOQ_In.Key[i]);
    }
    printf("] : ");

}
void CB_Existing_Q(CB_ListOfQ LOQ_In,int Count)
{
    int i;
    printf("Current Number of Queues and Keys:\n");
    printf("Circular Buffers [");
    for(i=0;i<Count;i++)
    {
        printf("%d ,",LOQ_In.Key[i]);
    }
    printf("] : ");

}

