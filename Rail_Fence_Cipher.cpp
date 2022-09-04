#include<iostream>
#include<sstream>
#include<string>
using namespace std;


string encry(int key, string t)
{
    string enc_s = "";
    int col = t.length();
    char rf[key][col];

    for(int i=0; i<key; i++)
    {
        for(int j=0; j<col; j++)
        {
            rf[i][j] = 0;
        }
    }

    for(int j=0,i=0,dir=1; j<col; i+=dir, j++)
    {
        rf[i][j] = t[j];
        if(i==0){dir=1;}
        else if(i==key-1){dir=-1;}
    }

    for(int i=0; i<key; i++)
    {
        for(int j=0; j<col; j++)
        {
            if(rf[i][j]!=0) 
            {
                enc_s += rf[i][j];
            }
            
        }
    }
    return enc_s;
}

string decry(int key, string t)
{
    string dec_s = "";
    int col = t.length();
    char rf[key][col];

    for(int i=0; i<key; i++)
    {
        for(int j=0; j<col; j++)
        {
            rf[i][j] = 0;
        }
    }

    for(int j=0,i=0,dir=1; j<col; i+=dir, j++)
    {
        rf[i][j] = '$';
        if(i==0){dir=1;}
        else if(i==key-1){dir=-1;}
    }

    int z=0;
    for(int i=0; i<key; i++)
    {
        for(int j=0; j<col; j++)
        {
            if(rf[i][j] == '$')
            {
                rf[i][j] = t[z++];
            }
        }
    }

    for(int j=0,i=0,dir=1; j<col; i+=dir,j++)
    {
        dec_s += rf[i][j];
        if(i==0){dir=1;}
        else if(i==key-1){dir=-1;}
    }

    return dec_s;
}

int main()
{
    int key;
    string t;
    cout<<"enter key"<<endl;
    cin>>key;
    
    cout<<"enter text"<<endl;
    getline(cin>>ws, t);

    int choice;
    cout<<"Press 1 to encipher the text"<<endl;
    cout<<"Press 2 to decipher the text"<<endl;
    cin>>choice;
    
    switch(choice)
    {
    case 1:
        cout<<"Encrypted output:"<<encry(key, t)<<endl;
        break;

    case 2:
        cout<<"Decrypted output:"<<decry(key, t)<<endl;
        break;

    default:
        cout<<"Try again next time"<<endl;
    }

    return 0;
}

