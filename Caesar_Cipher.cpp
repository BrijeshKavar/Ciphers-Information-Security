#include<iostream>
#include<bits/stdc++.h>
using namespace std;
#define mm 250

string encry(string s)
{
    string op="";
    for(int i=0; i<s.size(); i++)
    {
        if(s[i]==' ')
            {op+= s[i];}

        else if((s[i]>='a' && s[i]<'v')||(s[i]>='A' && s[i]<'V'))
        {
            op+= (s[i]+5);
        }
        else if(s[i]>='v'|| s[i]>='V' )
        {
            //op+= ((s[i]+5)%91 + 65);
            op+= (s[i]-26+5);
        }
        //else if()
    }
    return op;
}

string decry(string s)
{
    string op="";
    for(int i=0; i<s.size(); i++)
    {
        if(s[i]==' ')
            {op+= s[i];}

        else if((s[i]>'e' && s[i]<='z')||(s[i]>'E' && s[i]<='Z'))
        {
            op+= s[i]-5;
        }
        else if(s[i]<='e' || s[i]<='E')
        {
            op+= (s[i]+26-5);
        }
    }
    return op;
}

void doWork()
{
    cout<<"=========================================================="<<endl;
    cout<<"Welcome to the world of characters."<<endl<<endl;
    string s;
    int x;
    cout<<"Please enter the string"<<endl;
    getline(cin,s);

    cout<<endl<<"Could you please tell me what you want to do with the string?"<<endl;
    cout<<"Press 1 for ENCRYPTION"<<endl;
    cout<<"Press 2 for DECRYPTION"<<endl;
    // cout<<"Press 3 for EXIT"<<endl;
    cin>>x;
    switch(x)
    {
        case 1:
        {cout<<endl<<encry(s)<<endl;
        break;}

        case 2:
        {cout<<endl<<decry(s)<<endl;
        break;}

        default:
        cout<<"Please enter valid input next time."<<endl;
        break;
    }
    return;
}

int main()
{
    doWork();
    cout<<endl<<"have a great day :)"<<endl;
    cout<<"=========================================================="<<endl;
    return 0;
}
