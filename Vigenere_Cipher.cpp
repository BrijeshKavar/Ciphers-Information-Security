#include<iostream>
using namespace std;

int encry(string key, string text)
{
	string output = "";
	for(int i=0,j=0; i<text.length(); i++,j++)
	{	
		if(int(text[i]) < 91 && text[i] != ' ')
		{
			
			
			if((int(text[i]) + int(key[j]) - 97) > 90)
			{
				output += (int(text[i]) + int(key[j]) - 97 - 26);
			}
			else
			{
				output += (int(text[i]) + int(key[j]) - 97);
			}
		}
		
		else if(int(text[i]) > 96)
		{
			if((int(text[i]) + int(key[j]) - 97) < 123)
			{
				output += (int(text[i]) + int(key[j]) - 97);
			}
			else
			{
				output += (int(text[i]) + int(key[j]) - 97 - 26);
			}
		}
		
		else if(text[i] = ' ')
		{
			output += " ";
			j--;
		}
		
		if(j == key.length()-1) {j=-1;}
	}
	
	cout<<output;

	return 0;
}

int decry(string key, string text)
{
	string output = "";
	for(int i=0,j=0; i<text.length(); i++,j++)
	{
		if(int(text[i]) < 91 && text[i] != ' ')
		{
			if((int(text[i]) - int(key[j]) + 97) < 65)
			{
				output += (int(text[i]) - int(key[j]) + 97 + 26);
			}
			else
			{
				output += (int(text[i]) - int(key[j]) + 97);
			}
		}
		
		else if(int(text[i]) > 96)
		{
			if((int(text[i]) - int(key[j]) + 97) > 96)
			{
				output += (int(text[i]) - int(key[j]) + 97);
			}
			else
			{
				output += (int(text[i]) - int(key[j]) + 97 + 26);
			}
		}
		
		else if(text[i] = ' ')
		{
			output += " ";
			j--;
		}
		
		if(j == key.length()-1) {j=-1;}
	}
	
	cout<<output;
	
	return 0;
}

int main()
{
	string key,text;
	cout<<"Enter text: "<<endl;
	getline(cin>>ws, text);
	cout<<"Enter key in small letters, excluding space: "<<endl;
	getline(cin>>ws, key);

	int choice;
    cout<<"Press 1 to encipher the text"<<endl;
    cout<<"Press 2 to decipher the text"<<endl;
    cin>>choice;
	
	switch(choice)
    {
    case 1:
    	cout<<"Encrypted output:"<<endl;
        encry(key, text);
		break;

    case 2:
    	cout<<"Decrypted output:"<<endl;
        decry(key, text);
        break;

    default:
        cout<<"Try again next time"<<endl;
    }
	
	return 0;
}
