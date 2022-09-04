#include<iostream>
#include<string>
using namespace std;

int encry(string key, string pt)
{
	int row;
	int col = key.length();
	if(pt.length() % key.length() == 0)
	{
		row=pt.length() / key.length();
	}
	else
	{
		row=(pt.length() / key.length()) + 1;
	}
	
	char mat[row][col];
	for(int i=0; i<row; i++)
	{
		for(int j=0; j<col; j++)
		{
			//blank space in the matrix is replaced by '_'
			mat[i][j] = '_';
		}
	}
	
	int k=0;
	for(int i=0; i<row; i++)
	{
		for(int j=0; j<col; j++)
		{
			if(k<pt.length())
			{
				mat[i][j] = pt[k++];
			}
		}
	}
	
	int arr[col];
	int temp = 1;
	string alpha = "abcdefghijklmnopqrstuvwxyz";
	for(int i=0; i<alpha.length(), temp <= col; i++)
	{
		for(int j=0; j<col; j++)
		{
			if(alpha[i] == key[j])
			{
				arr[j] = temp;
				temp++;
			}
		}
	}
	
	int tra=1;
	for(int i=0; i<col; i++)
	{
		for(int j=0; j<col; j++)
		{
			if(arr[j] == tra)
			{
				for(int i=0; i<row; i++)
				{
					cout<<mat[i][j];
				}
				tra++;
			}
		}
	}
	
	return 0;
}

int decry(string key, string pt)
{
	int row;
	int col = key.length();
	if(pt.length() % key.length() == 0)
	{
		row=pt.length() / key.length();
	}
	else
	{
		row=(pt.length() / key.length()) + 1;
	}
	
	char mat[row][col];
	
	int arr[col];
	int temp = 1;
	string alpha = "abcdefghijklmnopqrstuvwxyz";
	for(int i=0; i<alpha.length(), temp <= col; i++)
	{
		for(int j=0; j<col; j++)
		{
			if(alpha[i] == key[j])
			{
				arr[j] = temp;
				temp++;
			}
		}
	}
	
	int tra=1,z=0;
	for(int i=0; i<col; i++)
	{
		for(int j=0; j<col; j++)
		{
			if(arr[j] == tra)
			{
				for(int i=0; i<row; i++)
				{
					mat[i][j] = pt[z++];
				}
				tra++;
			}
		}
	}
	
	int k=0;
	for(int i=0; i<row; i++) 
	{
		for(int j=0; j<col; j++)
		{	
			if(mat[i][j] != '_')
			{
				cout<<mat[i][j];
			}
		}
	}
	
	return 0;
}

int main()
{
	string key,pt;
	cout<<"Enter a key using small alphabets only(transposition cipher)"<<endl;
	getline(cin>>ws, key);
	cout<<"Enter plaintext"<<endl;
	getline(cin>>ws, pt);

	int choice;
    cout<<"Press 1 to encipher the text"<<endl;
    cout<<"Press 2 to decipher the text"<<endl;
    cin>>choice;
	
	switch(choice)
    {
    case 1:
    	cout<<"Encrypted output:"<<endl;
        encry(key, pt);
		break;

    case 2:
    	cout<<"Decrypted output:"<<endl;
        decry(key, pt);
        break;

    default:
        cout<<"Try again next time"<<endl;
    }		
	
	return 0;
}
