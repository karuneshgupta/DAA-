#include<stdio.h>
#include<stdlib.h>

int main()
{
    int inputArrSize;
    printf("enter size ");
    scanf("%d",&inputArrSize);
// 10
    int chararray[inputArrSize];
    printf("enter %d charachters " , inputArrSize);
    char ch;
    int max = -1;
    for (int i = 0; i < inputArrSize; i++)
    {
        scanf(" %c",&ch);//   a,e,d,w,a,d,q,a,f,p
        int val = ch - 'a';// 0,4,3,22,0,4,16,0,5,15
        chararray[i] =val;// [0,4,3,22,0,4,16,0,5,15]
        if(chararray[i] > max )
        max =chararray[i]; // 16->q
    }

    int temparr[26] ;
    for (int i = 0; i < 26; i++)
    {
        temparr[i] =0;
    }

    for (int i = 0; i <inputArrSize; i++)
    {
        /* code */
        temparr[chararray[i]]++;//[3,0,0,1,1,1,0,0,0,0,0,0,0,0,0,1,1,0,0,0,0,0,1,0,0,0]
    }
    int max1 = -1 ,position = 0;
    for(int i = 0 ;i< max ;i++)
    {
        if(temparr[i] > max1)
        {
            max1 = temparr[i]; // 3
            position = i; // 0
        }
    }

    if(max1>=2)
    {
    int charachter = 'a' + position;
    printf("%c occurs %d times",charachter , max1);
    }
    else
    printf("no duplicates present");
    
    
        
}
