#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int encry(long int n, long int e, long int msg)
{
	long int earr[e+1];
		
	earr[e] = 1;
	
	for(long int i=0; i<e; i++)
		earr[i] = msg;
	
	long int m=1;
	while(m<e)
	{
		long int k=0;
		if(fmod((e/m), 2) == 0)
		{
			long int i=0;
			for(i=0; i<=(e+1)/m - 2; i+=2)
				earr[k++] = (earr[i] * earr[i+1]) % n;
				
			earr[k] = earr[i];
		}
		else
		{
			for(long int i=0; i<=(e+1)/m - 1; i+=2)
				earr[k++] = (earr[i] * earr[i+1]) % n;
		}
			
		m = m*2;
	}
	
	return earr[0];
}

int decry(long int n, long int d, long int msg)
{	
	long int darr[d+1];
	
	darr[d] = 1;
	
	for(long int i=0; i<d; i++)
		darr[i] = msg;
		
	long int m=1;
	while(m<d)
	{
		long int k=0;
		if(fmod((d/m), 2) == 0)
		{
			long int i=0;
			for(i=0; i<=(d+1)/m - 2; i+=2)
				darr[k++] = (darr[i] * darr[i+1]) % n;
				
			darr[k] = darr[i];
		}
		else
		{
			for(long int i=0; i<=(d+1)/m - 1; i+=2)
				darr[k++] = (darr[i] * darr[i+1]) % n;
		}
			
		m = m*2;
	}
	
	return darr[0];
}

int main()
{
	long int p,q,n,euler,e,d;
	
	cout<<"enter prime value for p:"<<endl;
	cin>>p;
	cout<<"enter prime value for q:"<<endl;
	cin>>q;
	
	for(int i=2; i<p/2+1; i++)
	{
		if(p % i == 0)
		{
			cout<<"either p or q is not prime"<<endl;
			return 0;
		}
	}
	
	for(int i=2; i<q/2+1; i++)
	{
		if(q % i == 0)
		{
			cout<<"either p or q is not prime"<<endl;
			return 0;
		}
	}
	
	n = p*q;
	euler = (p-1)*(q-1);
	
	cout<<"n = "<<n<<"\teuler = "<<euler<<endl;
	
	cout<<"enter the value of e: it must be less than "<<euler<<" and co-prime with "<<euler<<endl;
	cin>>e;
	
	for(int i=1; i>0; i++)
	{
		if(((euler*i)+1) % e == 0)
		{
			d = ((euler*i)+1)/e;
			i=-1;
		}
	}
	
	cout<<"the value of d satisfying d*"<<e<<"=1(mod "<<euler<<") is: "<<d<<endl;
	
	string in,eout="",dout="";
	cout<<"Enter the string to be encrypted: "<<endl;
	getline(cin>>ws, in);
	
	for(int i=0; i<in.length(); i++)
		cout<<"("<<(int)in[i]<<")";
		
	cout<<endl;
	
	long int msg[5];

	cout<<"encrypted msg by block of 5 is: "<<endl;
	
	int j=0,x=1,y;
	
	if(in.length() % 5 == 0)
		y = in.length()/5;
	else
		y = in.length()/5 + 1;
	
	for(int a=0; a<y; a++)
	{
		int z = 5;
		if(a == y-1 && in.length() % 5 != 0)
		{
			z = in.length() % 5;
		}
		
		cout<<endl<<"("<<x<<")"<<"th block encryption:"<<endl;
		for(int i=0; i<z; i++)
		{
			msg[i] = (int)in[j++];
			msg[i] = encry(n, e, msg[i]);
			cout<<(char)msg[i];
			eout += (char)msg[i];
		}
	
		cout<<endl;
	
		for(int i=0; i<z; i++)
			cout<<"("<<msg[i]<<")";
		
		cout<<endl;
		
		cout<<"("<<(x++)<<")"<<"th block decryption:"<<endl;
		
		for(int i=0; i<z; i++)
		{
			msg[i] = decry(n, d, msg[i]);
			cout<<(char)msg[i];
			dout += (char)msg[i];
		}
	
		cout<<endl;
	
		for(int i=0; i<z; i++)
			cout<<"("<<msg[i]<<")";
		
		cout<<endl;
	}
	
	cout<<"========Final output========"<<endl<<"encrypted: "<<eout<<endl<<"decrypted: "<<dout;
	
	return 0;
}
