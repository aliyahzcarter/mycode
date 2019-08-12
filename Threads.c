/* Aliyah Carter
 09/30/18
CSC 564
Threads Program

*/

#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>


int f[];
int n;



void *printFibonacci(void *param)
{
    printf("Calculating Fibonacci Program in Second Thread\n");



 /* Declare an array to store Fibonacci numbers. */
  f[n]= f[n+2];   // 1 extra to handle case, n = 0
  int i;

  f[0] = 0;
  f[1] = 1;

  for (i = 2; i<=n+2; i++)
      {


        f[i] = f[i-1] + f[i-2];
}



printf("THe thread is complete");

}
int main()
{
    pthread_t thread_id;
    printf("Before Thread\n");
	int j; 

    printf("Please Enter a Value");
    scanf("%d",&n);
    pthread_create(&thread_id, NULL, printFibonacci  ,NULL);








 
    pthread_join(thread_id, NULL);
    
    
    
    printf("Fibonacci Series: \n");
    for(j=0; j<=n+2; j++)


{

printf("%3d   %6 \n",j,f[j]);


}
    printf("After Thread\n");
}


	
	
	
	
	
	
	
