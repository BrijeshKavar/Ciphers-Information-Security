#include<iostream>
using namespace std;

int encry(string key, string text)
{
	char pf[6][6];
	string temp = "abcdefghijklmnopqrstuvwxyz0123456789";
	key += temp;
	int size = key.length();
	
	for(int i=0; i<size; i++)
	{
		for(int j=i+1; j<size; j++)
		{
			if(key[i] == key[j])
			{
				for(int k=j; k<size; k++)
				{
					key[k] = key[k+1];
				}
				size--;
			}
		}
	}
	
	for(int i=0,k=0; i<6; i++)
	{
		for(int j=0; j<6; j++)
		{
			pf[i][j] = key[k++];
		}
	}
	
	for(int i=0; i<text.length()-1; i++)
	{
		if(text[i] == ' ')
		{
			text.erase(text.begin()+i);
		}
	}
		
	for(int i=0; i<text.length()-1; i+=2)
	{
		if(text[i] == text[i+1])
		{
			string s1 = "";
			if(text[i] == 'x')
			{
				s1 += "q";
			}
			else
			{
				s1 += "x";
			}
			
			text.insert(i+1, s1);	
		}
	}
	
	if(text.length() % 2 != 0)
	{
		if(text[text.length()-1] == 'x')
		{
			text += "q";
		}
		else
		{
			text += "x";
		}
	}
	
	cout<<"Encrypted text is: "<<endl;
	
	for(int i=0; i<text.length(); i+=2)
	{
		int j1,j2,k1,k2;
		for(int j=0; j<6; j++)
		{
			for(int k=0; k<6; k++)
			{
				if(text[i] == pf[j][k])
				{
					j1=j;
					k1=k;
				}
				if(text[i+1] == pf[j][k])
				{
					j2=j;
					k2=k;
				}
			}
		}
		if(j1==j2)
		{
			cout<<pf[j1][(k1+5) % 6]<<pf[j2][(k2+5) % 6];
		}
		else if(k1==k2)
		{
			cout<<pf[(j1+7) % 6][k2]<<pf[(j2+7) % 6][k1];
		}
		else
		{
			cout<<pf[j1][k2]<<pf[j2][k1];
		}
	}
	
	return 0;
}

int decry(string key, string text)
{
	char pf[6][6];
	string temp = "abcdefghijklmnopqrstuvwxyz0123456789";
	key += temp;
	int size = key.length();
	
	for(int i=0; i<size; i++)
	{
		for(int j=i+1; j<size; j++)
		{
			if(key[i] == key[j])
			{
				for(int k=j; k<size; k++)
				{
					key[k] = key[k+1];
				}
				size--;
			}
		}
	}
	
	for(int i=0,k=0; i<6; i++)
	{
		for(int j=0; j<6; j++)
		{
			pf[i][j] = key[k++];
		}
	}
		
	cout<<"Decrypted text is: "<<endl;
	
	for(int i=0; i<text.length(); i+=2)
	{
		int j1,j2,k1,k2;
		for(int j=0; j<6; j++)
		{
			for(int k=0; k<6; k++)
			{
				if(text[i] == pf[j][k])
				{
					j1=j;
					k1=k;
				}
				if(text[i+1] == pf[j][k])
				{
					j2=j;
					k2=k;
				}
			}
		}
		if(j1==j2)
		{
			cout<<pf[j1][(k1+7) % 6]<<pf[j2][(k2+7) % 6];
		}
		else if(k1==k2)
		{
			cout<<pf[(j1+5) % 6][k2]<<pf[(j2+5) % 6][k1];
		}
		else
		{
			cout<<pf[j1][k2]<<pf[j2][k1];
		}
	}
	
	return 0;
}

int main()
{
	string key,text;
	cout<<"Enter key without space and in small alphabets only: "<<endl;
	getline(cin>>ws,key);
	cout<<"Enter text in small alphabets only: "<<endl;
	getline(cin>>ws,text);
	
	int choice;
    cout<<"Press 1 to encipher the text"<<endl;
    cout<<"Press 2 to decipher the text"<<endl;
    cin>>choice;
    
    switch(choice)
    {
    case 1:
        encry(key, text);
        break;

    case 2:
        decry(key, text);
        break;

    default:
        cout<<"Try again next time"<<endl;
    }
	
	return 0;
}
