#include <bits/stdc++.h>
#include <unistd.h>
using namespace std;

int x,i;

void handler(int sig) {
	cout<<"File"<<i-1<<" reading stopped"<<endl;
	x++;
	sleep(10);
}

int main(int argc, char* argv[]) {
	int n = atoi(argv[1]);
	for(i = 2; i < 5; i++) {
		ifstream readf;
		readf.open(argv[i]);
		string s;
		x = i;
		signal(SIGINT, handler);
		cout<<"File Name: "<<argv[i]<<"...."<<endl;
		while(getline(readf, s) && x==i) {
			cout<<s<<endl;
			sleep(n);
		}
	}

}
