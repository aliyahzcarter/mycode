#include <iostream> 
#include <vector>
#include <fstream>
#include <deque>

using namespace std;

// Functions 
void getData();
void PrintData();
void RR();
void Calc();
void Calc2();
void WaitTime();



//global variables 
ifstream inFile; 
vector<float> Proc;
vector<float> Arrv;


vector<float>TurnTime;
vector<float>Arr2;


bool Array[22];
float Wait[22];

deque<float>turn;
deque<float>rqueue;


int Queue[10000];

int qMax = 0;
int  N;
int choice;

float Arrival; 
float Add;
float TQ=0;
float CS=0;
float count=30;
float counter2;
float Data;
float TotalTime;
float counter;
float k;
float x=30;
float qMaxTotal = 0;


bool check =1;


int main (){
	
	char exit = 'y';
	getData();
	
	
	
	cout<<" Please Select From Options (1-4)"<<endl;
	cout<<"1. Time Slices"<<endl<<"2. Time Slices + Context Switch "<<endl; 
	cin>>choice;
	
	
	switch (choice)
	
	{
		
		case 1:
			
					cout<<"Time Quantum ?"<<endl;
					
					cin>>TQ;
					
					cout<< " Time Quantum :" << TQ<< " msec"<<endl;
					
					TQ=TQ/1000;
					
					cout<<" Time Quantum: "<< TQ <<" sec"<<endl;
					
					RR();
		
						
					break;
			
		
					
					
		case 2:     	cout<<"Time Quantum ?"<<endl;
					
					cin>>TQ;
					
					cout << "Context Switch ?"<<endl;
					cin>>CS;
					
					cout<< " Time Quantum :" << TQ<< " msec"<<endl;
					cout <<" Context Switch :"<<CS<<" msec "<<endl; 
					CS=CS/1000;					
					TQ=TQ/1000;
					
					cout<<" Time Quantum: "<< TQ <<" sec"<<endl;
					cout <<"Context Switch :"<<CS << " sec"<<endl;
					
					RR();
					//Reset(exit);
					
					break;

		
	}
	
	
	
	

	

	
	
	
	cout<<"Simulation Complete"<<endl;
	system ("pause");
	
	return 0;
}


void getData ()
{
	
	
	inFile.open ( "RoundRobin.txt");
	  
	  	
	  	for ( int i=1; i<=44;i++){
	  		
	  			if ( i%2!=0)
	  			{
	  			inFile>>Data;
	  			
	  			Arrv.push_back(Data);
	  			}
	  		
			  
			  else 
			  	
	  				{	
	  				inFile>>Data;
	  				
	  				Proc.push_back(Data);
	  				
				  	}
    }
	  
	
	cout<< " There are "<<Proc.size()<< " Processes For the System"<<endl<<endl<<endl<<endl;
	
	PrintData();
	
}


void PrintData()
{
	
	cout<<"Arrival Time  "<<"   Processing Time"<<endl;
	
	// For Loop to print thr contents of the Processing Vector
	
	for (int i= 0; i < Proc.size(); i++)
	
	{
		
		cout<<Arrv[i]<<"                     "<< Proc[i]<<endl;
		
		
	}
	
	cout<< "----------------------------------------------------------------                  "<<endl<<endl<<endl;
	//Function call to Round Robin 	
  //  RR();
					
	}
	
void RR()

{
	
	cout <<" HERE"<<endl;
	int counter = 0;
		
	while (true) 	
	{
		
		//	cout<<" INSIDE OF LOOP"<<endl;
		N = 0;
		for (int i= 0; i < Proc.size(); i++)
		{
				
			//Only performs calculations if 1. The Proceess still has process time, and 2. It's arrival time is less than or equal to the current time
			if ((Proc[i] != 0) && (Arrv[i] <= count))
			{
				
			
				
				if(Proc[i]!=0&&Arrv[i]<=count)
				{
					counter2++;
					//Add one to counter for amount of ready processes
					N++;
				}
				
				//if N is greater than the current  qMax than replace the current qMax with N
				if (N>qMax)
				{
					
					qMax = N;
					
					
				}
				// Add the total amount of ready processes  
				qMaxTotal = qMaxTotal +N;
				
				
				// Check the correspondong postion in the array, to check to se if process has already ran 
				if(Array[i]!=1)
				{
					Array[i]=1;
					// the time the first executes is at time =count so it is stored in the wait vector 
					Wait[i]=count;
						
					// The Arrival time of the current process that is executing is stored in Arrv				
					Add=Arrv[i];
							
					Arr2.push_back(Add);
										
					// Account for switching between processes, process will only enter into this if statement if the  boolean corresponding array is  not 1
					count = count + CS;	
											
						}
					
		       // Conditions for  Process - Time Quantum , if Process-Time quantum is greater than 0 then do this
				if ((Proc[i]-TQ) > 0)
				{
					
					
					// Change the value in the cureent index  to processing time - time quantum
					Proc[i] = Proc[i] - TQ;
	
					//Add  time quantum to the current time
						count = count + TQ;
					  //	counter2++;
				}
				
				//if the process -TQ is less than 0 
				 if ((Proc[i]-TQ) <= 0)
				{
					
					//Adds remaining processing time to the current time
					if (Proc[i]-TQ==0){
						
						count  = count + TQ;
					}
					
					else {
					
					count = count + Proc[i];
					
					}	
					//Sets the current proccess' processing time equal to 0, marking it as complete
					Proc[i] = 0;
					// Increment counter everytime a process completes ( When the process ==0)
					counter++;
					
					//Print Completed information  and the Completion Time
				/*	cout<<"Process :"<< i << endl; */
					
				
				
					turn.push_back(count);
							
				// Check to see if the proceess time is less than the next number in the queue , if it is it will increment the current CPU time to the next arrivl time 
						if (count<Arrv[i+1])
						{
						count = Arrv [i+1];
						count= count+CS;
						
						}
					
					 cout << endl;		
	
			} 
			
		
	}
	
	
}
 // Check to see if counter is the same size as the Process vector Size and if it is,  then break from the infinite loop

	if (counter==Proc.size())
	{
		
			cout <<"Total Simluation Time:"<<turn[21]<<endl;
			
			
		//	cout<<"Completion :"<<count<<endl;
			break;
						
	}
	
	//end of while loop
	}
// Out of While Loop

 	Calc2();
 	
}


void Calc2(){
	

	float sum,sum2;
	int x;
	int sum3;
	
	cout <<endl<<endl;
	
	cout<<" DATA RESULTS "<<endl;
	cout<<"----------------------"<<endl;
	// Calculate the turn around time by taking the completeion - the arrival
	for ( int x=0;x<22;x++)
	{
		turn[x]=turn[x]-Arr2[x];
		
		sum = sum + turn[x];
		
	}
	//Calculate the Wait time by first execution time - arrv 
	for ( int j = 0 ; j<22; j++){
		
		Wait[j]=Wait[j]-Arr2[j];
		
		sum2=  sum2 + Wait[j];
	}
	
	// Find the average turn around time
	sum =(sum/turn.size());
	//Find the average Wait Time 
	sum2 =(sum2/turn.size());
	qMax=qMax-1;
	
		cout<< "Turn Around Time Average: " <<sum<<endl; 
		cout <<"Wait Time Average: "<<sum2<<endl;
		cout<<"Average Queue  Length: "<<  qMax << endl ;
		cout <<"Queue  Average :  " << (qMaxTotal/counter2)<< endl<<endl<<endl;
}








	
	
	

	
