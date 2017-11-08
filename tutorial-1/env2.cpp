#include<bits/stdc++.h>
using namespace std;

extern char **environ;

int main(int argc, char* argv[]){

	for(int i=0; environ[i]!='\0'; i++)
		cout<<environ[i]<<endl;	

	return 0;
}
