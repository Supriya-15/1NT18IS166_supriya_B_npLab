#include<stdio.h>
#include<string.h>


void bit(int frame[],int n)
{
int i=0;
     int framerec[n];
     
     for(i=n-1;i>=0;i--)     {
      framerec[i]=frame[i];
     }
     
     printf("\n the frame transfer is ");
     for(i=0;i<n;i++)
     {
     printf("  %d  \n  ",framerec[i]);
     }
     
}
//void sender(int frame[],int i)
//{
 //int count=0;
   //int v=frame[i];
    //while(v!=0)
   //{
   // v=v/10;
    //   count++;
        
  //  }
 
// printf("the %d frame has this %d bits",i+1,count);  
 
//}

void main(){
    int n,i,count=0;
  
     printf("enter the number of frames\n");
     scanf("%d",&n);
    // int p=n;
       int frame[n];
    printf("enter the frame pattern\n");
    for(i=0;i<n;i++)
    {
    scanf("%d",&frame[i]);
    }
    for(i=0;i<n;i++)
    {
     int v=frame[i];
    while(v!=0)
    {
    v=v/10;
       count++;
   
    }
    
    printf("\nthe %dst frame has this %d bits",i+1 ,count);  
 count=0;
}
bit(frame,n);
    /*for(i=0;i<n;i++)
    {
    
}*/
}
