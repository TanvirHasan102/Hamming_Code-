#include<iostream>
#include<stdlib.h>
#include<math.h>
#include<stdio.h>
using namespace std;

int main()
{
    int i,parity_type,message_size,msg[100],parity_bit=0;

    printf("Enter message size: ");
    scanf("%d",&message_size);

    printf("\nEnter message's bit one by one:");
    for(i=1;i<=message_size;i++)
        scanf("%d",&msg[i]);

    printf("\nEnter Parity type(0=Even & 1=Odd): ");
    scanf("%d",&parity_type);


    while (message_size + parity_bit + 1 > pow (2, parity_bit))
      {parity_bit++;}


    int message[message_size+parity_bit],p=0,d=1;

    for (i = 1; i <= message_size+parity_bit; i++)
    {
        if (i==pow(2, p))

        {
           message[i] = 0;
           p++;
        }

        else
        {
          message[i] = msg[d];
          d++;
        }
    }

    printf(" \nData Bits are Encoded with Parity bits(0): ");
    for (i = 1; i <=message_size+parity_bit ; i++)
    {
        printf("%d ",message[i]);
    }
    printf("\n\n");

    int j=1,k,count1,count;

    while(j<=parity_bit)
    {
        count1=0;
        count=pow(2,j-1);
        i=count-1;
        while(i<=message_size+parity_bit)
        {
            k=1;
            while(k<=count)
            {
                if(message[i+k]==1)
                    count1++;
                k++;
            }
            i=i+count+k-1;
        }

        if(parity_type==1)
        {
            if(count1%2==0)
                message[count]=1;

            else
                 message[count]=0;

        }
        else
        {
            if(count1%2==0)
                message[count]=0;

            else
                 message[count]=1;

        }
        j++;


      }

      printf("\nCodeword:");
      for(i=1;i<=message_size+parity_bit;i++)
        printf("%d ",message[i]);

     printf("\n\n");
}

