#include <iostream>
#include <string>
#include <fstream>

using namespace std; 

int D;
int n;
const int S=n;

const int B;

int Determinate(int n, int Matrix[S][B])
{
	S=n;
	int ans=0, s=1, i ,j , b,e;
	
	int repMatrix[S][S];
	
	if (n==1){
		
		return Matrix[0][0];	
	}
	
	else {
				for (int c=0;c<n;c++){
					
					e=0;
					b=0;
					for ( i=0; i < n; i++)
					{

						for (j=0; j<n;j++)
						{
							repMatrix[i][j] = 0;
			                    if(i!=0 && j!=c)
			                    {
					                repMatrix[b][e] = Matrix[i][j];
					                        
				                        if(e<(n-2))
				                        {
				                            e++;
				                        }
				                        else
				                        {
				                            e=0;
				                            b++;
										}
								}
							}
						}
	
				ans = ans + s*(Matrix[0][c]*Determinate(n-1,repMatrix));
	
					s= -1*s;
					}// end of c loop 
						
				}// end of else statment
				
			return ans;
		
}

int main()
{
	
	int n,i, j
	ifstream ptr;
	string filename;
	
	//initialize matrix
	int Matrix[S][S];
	cout <<"Welcome to the Determinate Program, you may enter in an N, and your matrix file provided must be N x N "<<endl;
 
	cout<<"For example if N = 3 , then file format should be :" <<endl<<endl<<"1 2 3" <<endl<<"4 5 6 "<<endl<<"7 1 2"<<endl<<endl;
	cout<<"Enter N"<<endl;
	cin >>n;
	
	cout<<" The Current N = "<<n<<endl;
	
	cout<<"Please enter in file name not including txt "<<endl;
	cin>>filename;
	
	filename= filename + ".txt";
		
	
		
		
	ptr.open(filename.c_str());
		
		 for ( i=0; i<n;i++){
		 
	 		for( j=0;j <n;j++)
	 		ptr>>Matrix[i][j];
	 			
	 	}
	
	
	 ptr.close();
	 
	 //print out the data in the matrix 
	 
	 cout<< "Filename:"<<filename<<endl<<" The Data in the file is listed as"<<endl;
	 
	 	for ( i=0; i<n;i++){
		 
	 		for( j=0;j <n;j++)
			cout<<Matrix[i][j]<<"  "; 
	 		cout<<endl;		
	 	}
	 		
	 		//Call to determinate function 
	D= Determinate(n,Matrix);
		
	
	cout<<" The determinate is:"<<D;
	
   
 	cout<<endl;
	system ("pause");
	
	return 0; 


}





