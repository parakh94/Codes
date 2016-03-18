#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define sf scanf
#define pf printf

char arr[1000000];

int main()
{
	ll i,l,count=-1;
	vector <string>rep;
	string s;
	getline(cin, s);
//	cout<<s;
	int j = 0;
	for(i = 0; i< s.length();i++){
		if(s[i] == ' '){
			rep.push_back(s.substr(j,i-j));
//			cout<<s.substr(j,i-j);
			j = i+1;
		}
	}
	rep.push_back(s.substr(j,i-j));
		
//	for (vector<string>::iterator it = rep.begin() ; it != rep.end(); ++it)
//    cout << *it;
//  	cout << '\n';
  	
	
	sf("%[^\n]s",arr);
//	printf("%s\n",arr);
	l=strlen(arr);
	
	for(i=0;i<l;i++)
	{
		int flag = 0;
		if(arr[i]=='{'&&arr[i+1]=='}')
		{
			count++;
//			cout<<count << " " << rep.size();
			if(count<rep.size())
			cout<<rep[count];
			else
			{
				flag=1;
			}
			if(flag==1)
			cout<<arr[i];
			else i++;
		}
		else if(arr[i]=='{'&&arr[i+1]!='}')
		{
			int k=i+1,z=0,flag1=0,m=0;
			while(arr[k]!='}')
			{
				
				if(arr[k]-'0' >= 0 && arr[k]-'0'<= 9)
				{
					z=z*10+arr[k]-'0';
					if(arr[k-1]=='{'&&arr[k+1]!='}'&&z==0)flag = 1;
				}
				else if(arr[k]-'a' >= 0 && arr[k]-'a'<= 26) {
					if(arr[k-1]=='{')cout<<arr[k-1];
					cout<<arr[k];
					if(arr[k+1] == '}')cout<<arr[k+1];
					flag1=1;
				}
				else flag = 1;
				k++;
			}
//			cout<<z<<" "<<flag;
			if(flag1==0)
			{
				if(z<rep.size()&&flag == 0)
				cout<<rep[z];
				else {
					m = 1;
					flag = 1;
				}
			}
			if(m == 1) cout<<arr[i];
			else  i = k;
		}
		else
		printf("%c",arr[i]);
	}
	return 0;
}

