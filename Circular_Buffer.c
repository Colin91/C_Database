#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "CB_priority_queue.h"



CB_Object_Node CB_clear(CB_Object_Node OBN_In)
{

    int i;
    int c;
    CB_Object OBL_01;
    c =CB_size(OBN_In);
    for(i=0;i<=c;i++)
    {
        OBN_In=CB_dequeue(OBN_In);
    }
    OBN_In.Count=0;
    OBN_In.Counter=0;
    OBN_In.Size=0;
    OBN_In.Rear=OBN_In.Front;
    OBN_In.First=OBN_In.Front;
    return OBN_In;
}

CB_Object_Node CB_store(CB_Object_Node OBN_In, FILE* FP)
{
    int i;
    int j;
    char name[30];
    CB_Object Loop_OBL;
    CB_Object OBL;
    printf("Enter file name: " );
    scanf("%s", name); // Read in filename
    FP = fopen(name,"wb");

    if(FP!=NULL)
    {
        i=OBN_In.Counter;
        fwrite(&i,sizeof(i),1,FP);
        for(j=0;j<i;j++)
        {
            Loop_OBL=OBN_In.Front[j];
            fwrite(&(Loop_OBL),sizeof(CB_Object),1,FP);
        }
    }
    else
    {
        printf("Err 005 : Problem with File %s\n",name);
    }
    fclose(FP);
    return OBN_In;


}
CB_Object_Node CB_load(CB_Object_Node OBN_In, FILE* FP)
{
    int i;
    int j;
    int create=0;
    char name[30];
    char* buffer;
    long Size;
    CB_Object OBL;
    CB_Object* P_OBL;
    int convert;
    printf("Enter file name to Load: " );
    scanf("%s", name);

    FP=fopen(name,"rb");

    if(FP!=NULL)
    {
        fseek(FP,SEEK_SET,0);
        fread(&i,sizeof(i),1,FP);

        P_OBL=malloc(sizeof(*P_OBL)*i);

        for(j=0;j<i;j++)
        {
            fread(&P_OBL[j],sizeof(CB_Object),1,FP);
            P_OBL[j].Stock_Name;
            P_OBL[j].Price;
            OBN_In=CB_enqueue(OBN_In,P_OBL[j],P_OBL[j].Priority);
        }
    }
    else
    {
        printf("File %s, error in loading\n",name);
    }
    fclose(FP);
    return OBN_In;

}


CB_Object_Node CB_merge(CB_Object_Node OBN_In_01,CB_Object_Node OBN_In_02)
{
    int i;
    int length=0;
    char temp[20];
    CB_Object_Node OBN_In_03;
    CB_Object_Node OBN_TEMP_In_03;
    OBN_TEMP_In_03=OBN_In_01;
    CB_Object OBL_01,OBL_02,OBL_03;

    OBN_In_03=CB_create_q(OBN_In_01.Size+OBN_In_02.Size);
    OBN_In_03.Size=OBN_In_01.Size+OBN_In_02.Size;
    OBN_In_03.Rear=OBN_In_03.Front;

    OBN_In_03.Count=0;

   length=strlen(OBN_In_01.Front->Stock_Name);

    for(i=0;i<OBN_In_01.Counter;i++)
    {
        OBL_01.Price=OBN_In_01.Front[i].Price;
        OBN_In_03=CB_enqueue(OBN_In_03,OBN_In_01.Front[i],OBN_In_01.Front[i].Priority);
    }
    for(i=0;i<OBN_In_02.Counter;i++)
    {
        OBL_02.Price=OBN_In_02.Front[i].Price;
        OBN_In_03=CB_enqueue(OBN_In_03,OBN_In_02.Front[i],OBN_In_02.Front[i].Priority);
    }

    return OBN_In_03;

}

int CB_size(CB_Object_Node OBN_In)
{
    int sizer=0;
    sizer = OBN_In.Counter;
    if(sizer==0)
    {
        printf("ERR 001 : Size not set\n");
    }
    else
    {
        sizer=sizer;
    }
    return sizer;
}

int CB_is_empty(CB_Object_Node OBN_In) // 1 = true 0 = false
{
    int ret=0;
    if(OBN_In.Counter==0)//-1
    {
        ret=1;
    }
    return ret;
}


CB_Object CB_peek(CB_Object_Node OBN_In)
{
    CB_Object OBJ;
    int Check;
    Check=CB_is_empty(OBN_In);
    if(Check==1)
    {
        printf("ERR 002 : List is Empty\n");
    }
    else
    {
        OBJ = OBN_In.Front[0];
    }

    return OBJ;
}

CB_Object_Node CB_dequeue(CB_Object_Node OBN_In)
{
    int i=0;
    int Check=0;
    Check=CB_is_empty(OBN_In);
    if(Check==1)
    {
        printf("ERR 002 : List is Empty\n");
    }
    else
    {
        for(i=0;i<OBN_In.Count+1;i++)
        {
            OBN_In.Front[i]=OBN_In.Front[i+1];

        }
        OBN_In.Count--;
        OBN_In.Rear--;
        OBN_In.Counter--;
    }

    return OBN_In;
}

CB_Object_Node CB_enqueue(CB_Object_Node OBN_In,CB_Object OBL_In,int Priority_In)
{
    int i=0,j=0;
    int max=0;
    CB_Object Max;
    CB_Object Temp_1;

    OBL_In.Priority=Priority_In;
    OBN_In.Count=OBN_In.Rear-OBN_In.Front;
    OBN_In.Counter=OBN_In.Counter+1;

    OBL_In.Key=OBN_In.Count;

    if(OBN_In.Count>OBN_In.Size-1)
    {
         OBN_In=CB_dequeue(OBN_In);
         *OBN_In.Rear=OBL_In;
         OBN_In.Rear++;
    }
    else
    {
        *OBN_In.Rear=OBL_In;
        OBN_In.Rear++;

    }


    if(OBN_In.Rear!=OBN_In.Front)
    {
        for(j=0;j<=OBN_In.Count;)
        {
            max=OBN_In.Front[j].Priority;
            Max=OBN_In.Front[j];
            for(i=OBN_In.Count;i<=OBN_In.Count;)
            {
                if(OBN_In.Front[i].Priority>max)
                {
                    Temp_1=OBN_In.Front[j];
                    OBN_In.Front[j]=OBN_In.Front[i];
                    OBN_In.Front[i]=Temp_1;
                }
                i++;
            }
            j++;
        }
    }


    return OBN_In;

}

CB_Object_Node CB_create_q(int max_size)
{

    CB_Object *PTL;
    CB_Object_Node OBN;
    OBN.Size=max_size;
    OBN.Front = (CB_Object*)malloc(max_size*sizeof(CB_Object)+(1*sizeof(CB_Object))); // For the OBN.Rear Overflow

    if(OBN.Front==NULL)
    {
        printf("ERR 003 : Memory Allocation Failed\n");
    }
    else
    {
        OBN.Rear=OBN.Front;
        OBN.First=OBN.Front;
        OBN.Count=0;
        OBN.Counter=0;
        return OBN;
    }

}

CB_Object_Node CB_get_First_Node(CB_Object_Node OBN_01)
{
    int i=0;
    OBN_01.First=OBN_01.Front;

    for(i=0;i<OBN_01.Size-1;i++)
    {
        OBN_01.First++;
    }
    OBN_01.First=&OBN_01.Front[0];
    return OBN_01;
}



