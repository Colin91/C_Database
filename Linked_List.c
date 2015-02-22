#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "LL_priority_queue.h"



Object_Node clear(Object_Node OBN_In)
{
    Object* Temp;
    Object* Loop_OBL;
    int EMPTY;
    int c=0;
    int i=0;
    EMPTY=is_empty(OBN_In);
    c =Size(OBN_In);

    if(EMPTY==0)
    {
        for(i=0;i<=c;i++)
        {
            OBN_In = dequeue(OBN_In);
        }
    }
    else
    {
        printf("Err 004 : Queue is Empty, Nothing to Clear\n");
    }
    OBN_In.Rear=OBN_In.Front;
    OBN_In.Max=OBN_In.Front;
    OBN_In.Min=OBN_In.Front;
    OBN_In.Lead=OBN_In.Front;
    OBN_In.Lag=OBN_In.Front;
    OBN_In.Counter=0;
    return OBN_In;


}

Object_Node store(Object_Node OBN_In, FILE* FP)
{
    int i;
    char name[30];
    Object* Loop_OBL;
    Object OBL;
    printf("Enter file name: " );
    scanf("%s", name); // Read in filename
    FP = fopen(name,"wb");

    if(FP!=NULL)
    {
        i=OBN_In.Counter;
        fwrite(&i,sizeof(i),1,FP);
        for(Loop_OBL=OBN_In.Max;Loop_OBL!=OBN_In.Min->Next;Loop_OBL=Loop_OBL->Next)
        {
            fwrite(&(*Loop_OBL),sizeof(Object),1,FP);
        }
    }
    else
    {
        printf("Err 005 : Problem with File %s\n",name);
    }

    fclose(FP);
    return OBN_In;

}
Object_Node load(Object_Node OBN_In_01, FILE* FP)
{
    int i;
    int j;
    char name[30];
    char* buffer;
    long Size;
    Object OBL;
    Object* P_OBL;
    int convert;
    printf("Enter file name to Load: " );
    scanf("%s", name); // Read in filename

    FP=fopen(name,"rb");

    if(FP!=NULL)
    {
        fseek(FP,SEEK_SET,0);
        fread(&i,sizeof(i),1,FP);
        P_OBL=malloc(sizeof(*P_OBL)*i);

        for(j=0;j<i;j++)
        {
            fread(&P_OBL[j],sizeof(Object),1,FP);
            P_OBL[j].Stock_Name;
            P_OBL[j].Price;
            OBN_In_01=enqueue(OBN_In_01,P_OBL[j],P_OBL[j].Priority);
        }
    }
    else
    {
        printf("Err 005 : Problem with File %s,\n",name);
    }
    fclose(FP);
    //free(P_OBL);
    return OBN_In_01;

}


Object_Node merge(Object_Node OBN_In_01,Object_Node OBN_In_02)
{
    Object* Loop_OBL;
    Object_Node OBN_In_03;

    OBN_In_03 = create_q(OBN_In_01.Max_Size+OBN_In_02.Max_Size);
    OBN_In_03.Max_Size=OBN_In_01.Max_Size+OBN_In_02.Max_Size;

    OBN_In_03.Counter=0;

    for(Loop_OBL=OBN_In_01.Max;Loop_OBL!=NULL;Loop_OBL=Loop_OBL->Next)
    {
        OBN_In_03=enqueue(OBN_In_03,*Loop_OBL,Loop_OBL->Priority);
        *OBN_In_03.Rear=*Loop_OBL;
    }

    OBN_In_03.Min->Next=&(*OBN_In_02.Max);

    for(Loop_OBL=OBN_In_02.Max;Loop_OBL!=NULL;Loop_OBL=Loop_OBL->Next)
    {
        OBN_In_03=enqueue(OBN_In_03,*Loop_OBL,Loop_OBL->Priority);
    }

    return OBN_In_03;

}


int Size(Object_Node OBN_In)
{
    int sizer;
    sizer = OBN_In.Counter;
    if(sizer==0)
    {
        printf("ERR 001 : Size not set\n");
    }
    return sizer;
}

int is_empty(Object_Node OBN_In) // 1 = true 0 = false
{
    int ret=0;
    if(OBN_In.Counter==0)
    {
        ret=1;
    }
    return ret;
}


Object peek(Object_Node OBN_In)
{
    int Check;
    Check=is_empty(OBN_In);
    Object Max;

    if(Check==1)
    {
        printf("ERR 002 : Queue is Empty\n");
    }
    else
    {
        Max=*OBN_In.Max;

    }
    return Max;
}

Object_Node dequeue(Object_Node OBN_In)
{
    int Check=0;
    Check=is_empty(OBN_In);
    Object* Temp;
    if(Check==1)
    {
        printf("ERR 002 : Queue is Empty\n");
    }
    else
    {
        Temp=OBN_In.Max->Next;
        free(OBN_In.Max);
        OBN_In.Max=Temp;
        OBN_In.Count--;
        OBN_In.Counter--; //added
    }
    return OBN_In;
}

Object_Node enqueue(Object_Node OBN_In,Object OBL_In,int Priority_In)
{
    Object* Loop_OBL;
    Object* LagOfLag;
    int max=0;
    int i=0,j=0,z=0;
    int min=0;
    int Flag=0;
    Object Max;
    Object Min;


    if(OBN_In.Counter!=OBN_In.Max_Size)
    {
        OBN_In.Rear=(Object*)malloc(sizeof(Object));
        OBL_In.Priority=Priority_In;
        OBL_In.Next=NULL;
        *OBN_In.Rear=OBL_In;

        for(Loop_OBL=OBN_In.Max;Loop_OBL!=OBN_In.Min->Next;Loop_OBL=Loop_OBL->Next)
        {
            if(OBN_In.Counter==0)
            {
                OBN_In.Max=OBN_In.Rear;
            }
            else
            {
                if(Loop_OBL==NULL&&OBN_In.Counter!=0)
                {
                    Loop_OBL->Next=OBN_In.Rear;
                }

            }


        }
        OBN_In.Counter=(OBN_In.Counter)+1;

        if(OBN_In.Rear==OBN_In.Front)
        {
            for(Loop_OBL=OBN_In.Front;Loop_OBL!=NULL;Loop_OBL=Loop_OBL->Next)
            {
                if(Loop_OBL->Priority>max)
                {
                    max=Loop_OBL->Priority;
                    Max=(*Loop_OBL);
                    OBN_In.Max=&(*Loop_OBL);
                }
                if(Loop_OBL->Priority<min)
                {
                    min=Loop_OBL->Priority;
                    Min=(*Loop_OBL);
                    OBN_In.Min=&(*Loop_OBL);
                }
            }
        }

        //Case 1
        if(OBN_In.Rear->Priority>OBN_In.Max->Priority)
        {
            OBN_In.Rear->Next=&(*OBN_In.Max);
            OBN_In.Max=&(*OBN_In.Rear);
            OBN_In.Min->Next=NULL;
            Flag=1;
        }

        //Case 2
        if(OBN_In.Rear->Priority==OBN_In.Max->Priority)
        {
            OBN_In.Lag=OBN_In.Max->Next;
            if(OBN_In.Lag!=NULL)
            {
                if(OBN_In.Lag->Priority==OBN_In.Max->Priority) //In case there are more than 2 same values of max
                {
                    LagOfLag=OBN_In.Lag->Next;
                    OBN_In.Lag->Next=&(*OBN_In.Rear);
                    OBN_In.Rear->Next=&(*LagOfLag);
                }
                else
                {
                    OBN_In.Max->Next=&(*OBN_In.Rear);
                    OBN_In.Rear->Next=&(*OBN_In.Lag);
                }

            }

            OBN_In.Min->Next=NULL;
            Flag=1;
        }

        //Case 3
        if(OBN_In.Rear->Priority<=OBN_In.Min->Priority)
        {
            OBN_In.Min->Next=&(*OBN_In.Rear);
            OBN_In.Min=&(*OBN_In.Rear);
            OBN_In.Rear->Next=NULL;
            Flag=1;
        }

        //Case 4
        if(OBN_In.Rear->Priority<OBN_In.Max->Priority&&OBN_In.Rear->Priority>OBN_In.Min->Priority)
        {
            for(OBN_In.Lead=OBN_In.Max;OBN_In.Lead!=NULL;OBN_In.Lead=OBN_In.Lead->Next)
            {
                OBN_In.Lag=OBN_In.Lead->Next;
                if((OBN_In.Rear->Priority<=OBN_In.Lead->Priority)&&(OBN_In.Rear->Priority>OBN_In.Lag->Priority))
                {
                    OBN_In.Lead->Next=&(*OBN_In.Rear);
                    OBN_In.Rear->Next=&(*OBN_In.Lag);
                    OBN_In.Min->Next=NULL;
                    Flag=1;
                }
            }
        }


    }
    else
    {
        printf("ERR 004 : List is Full\n");
        //OBN_In.Min->Next=NULL;
    }
	
    
    return OBN_In;

}

Object_Node create_q(int max_size)
{

    Object *PTL;
    Object_Node OBN;
    OBN.Max_Size=max_size;

    OBN.Front = (Object*)malloc(sizeof(Object));

    if(OBN.Front==NULL)
    {
        printf("ERR 003 : Memory Allocation Failed\n");
    }
    else
    {
        OBN.Rear=OBN.Front;
        OBN.Max=OBN.Front;
        OBN.Min=OBN.Front;
        OBN.Lead=OBN.Front;
        OBN.Lag=OBN.Front;
        OBN.Counter=0;
        return OBN;
    }

}
