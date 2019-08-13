#include<iostream>

#include<string>

using namespace std;

void Hamming();
void TwoDParity();
void dTwoDParity();
void dHamming();


int arr2[7];
int arr[6][6];
int main()
{

	int num;
	bool quit=false;
	while (quit == false)
	{
		cout<<"ENCODER"<<endl;
		cout << "Select the Encoder you would like to use" << endl;
		cout << "1.Hamming" <<endl<< "2.TwoDParity"<< endl << "3.Quit"<<endl;
		cin>>num;

		if (num == 1)
		{
			Hamming();
		}
		else if (num == 2)
		{
			TwoDParity();
		}

		else if (num == 3)
		{
			quit = true;
		}
		else 
			 cout<<"The number you have entered is invalid"<<endl;

		
	}
	system("pause");
		return 0;
}
void TwoDParity()
{
	int counter=0;
	for(int i = 0; i < 6; i++)
	{
		for(int j = 0; j < 6; j++)
		{
			arr[i][j] = rand() % 2;
		}
	}
	for(int i = 0; i < 5; i++)
	{
		counter = 0;
		for(int j = 0; j < 5; j++)
		{
			cout << arr[i][j];
			if( arr[i][j] == 1)
			{
				 counter ++;
			}
		}
		if(counter%2==0)
		{
			arr[i][5]=0;
		}
		else
			arr[i][5]=1;
		cout << endl;
	}
	for(int j= 0; j < 5; j++)
	{
		counter = 0;
		for(int i = 0; i < 5; i++)
		{
			//cout << arr[i][j];

			if( arr[i][j] == 1)
			{
				 counter ++;
			}
		}
		if(counter%2==0)
		{
			arr[5][j]=0;
		}
		else
			arr[5][j]=1;
		cout << endl;
	}
	for(int i = 0; i < 6; i++)
	{
		for(int j = 0; j < 6; j++)
		{
			cout << arr[i][j];
		}
		cout << endl;
	}
	cout << "Would you like to decode this 'y' or 'n'";
	string s;
	cin >> s;
	if(arr[5][5] == 0)
		arr[5][5] = 1;
	else
		arr[5][5] = 0;
	if(s == "y")
	{
		dTwoDParity();
	}
}

void Hamming()
{
	for(int i = 0; i < 4; i++)
	{
		arr2[i] = rand() % 2;
		cout << arr2[i] << " ";
	}
	cout << endl;
	int check1, check2, check3;
	check1 = check2 = check3 = 0;
	if(arr2[0] == 0)
	{
		check1++;
		check2++;
	}
	if(arr2[1] == 0)
	{
		check1++;
		check3++;
	}
	if(arr2[2] == 0)
	{
		check2++;
		check3++;
	}
	if(arr2[3] == 0)
	{
		check1++;
		check2++;
		check3++;
	}
	if(check1 % 2 == 0)
		arr2[4] = 0;
	else
		arr2[4] = 1;
	if(check2 % 2 == 0)
		arr2[5] = 0;
	else
		arr2[5] = 1;
	if(check3 % 2 == 0)
		arr2[6] = 0;
	else
		arr2[6] = 1;

	for(int i = 0; i < 4; i++)
	{
		cout << arr2[i] << " ";
	}
	cout << " : ";
	for(int i = 4; i < 7; i++)
	{
		cout << arr2[i] << " "; 
	}
	cout << "Would you like to decode this 'y' or 'n'";
	string s;
	cin >> s;
	if(s == "y")
	{
		dHamming();
	}
}
void dTwoDParity()
{
	cout << "Original" << endl;
	for(int i = 0; i < 6; i++)
	{
		for(int j = 0; j < 6; j++)
		{
			cout << arr[i][j];
		}
		cout << endl;
	}
	int counter = 0;
	for(int i = 0; i < 5; i++)
	{
		
		counter = 0;
		for(int j = 0; j < 5; j++)
		{
			cout << arr[i][j];
			if( arr[i][j] == 1)
			{
				 counter ++;
			}
		}
		if(counter%2==0)
		{
			if(arr[i][5] != 0)
			{
				cout << endl << "There is an error at [" << i << "][5]" <<  endl;
			}
		}
		else
		{
			if(arr[i][5] != 1)
			{
				cout << endl << "There is an error at [" << i << "][5]" <<  endl;
			}
		}
		cout << endl;
	}
	for(int j= 0; j < 5; j++)
	{
		counter = 0;
		for(int i = 0; i < 5; i++)
		{
			//cout << arr[i][j];
			if( arr[i][j] == 1)
			{
				 counter++;
			}
		}
		if(counter%2==0)
		{
			if(arr[5][j] != 0)
			{
				cout << endl << "There is an error at [" << "[5][" << j  << "]" <<  endl;
			}
			arr[5][j]=0;
		}
		else
		{
			if(arr[5][j] != 0)
			{
				cout << endl << "There is an error at " << "[5][" << j  << "]" <<  endl;
			}

		}
		cout << endl;
	}
	
}
void dHamming()
{
	for(int i = 0; i < 4; i++)
	{
		arr2[i] = rand() % 2;
		cout << arr2[i] << " ";
	}
	cout << endl;
	int check1, check2, check3;
	check1 = check2 = check3 = 0;
	if(arr2[0] == 0)
	{
		check1++;
		check2++;
	}
	if(arr2[1] == 0)
	{
		check1++;
		check3++;
	}
	if(arr2[2] == 0)
	{
		check2++;
		check3++;
	}
	if(arr2[3] == 0)
	{
		check1++;
		check2++;
		check3++;
	}
	if(check1 % 2 == 0)
	{
		if(arr2[4] != 0)
			cout << "There is an error at parity bit 1" << endl;
	}
	else
	{
		if(arr2[4] == 1)
			cout << "There is an error at parity bit 1" << endl;
	}
	if(check1 % 2 == 0)
	{
		if(arr2[5] != 0)
			cout << "There is an error at parity bit 2" << endl;
	}
	else
	{
		if(arr2[5] == 1)
			cout << "There is an error at parity bit 2" << endl;
	}
	if(check1 % 2 == 0)
	{
		if(arr2[6] != 0)
			cout << "There is an error at parity bit 3" << endl;
	}
	else
	{
		if(arr2[6] == 1)
			cout << "There is an error at parity bit 3" << endl;
	}
	for(int i = 0; i < 4; i++)
	{
		cout << arr2[i] << " ";
	}
	cout << " : ";
	for(int i = 4; i < 7; i++)
	{
		cout << arr2[i] << " "; 
	}
}