#include <stdio.h>
#include <signal.h>
#include <unistd.h>

void sig(int signum) {
	printf("Undefined\n");
}

int main()
{
	int n;
	double x, ans;
	signal(SIGFPE, sig);
	while(1) {
		scanf("%lf", &x);
		double up = (x - 3.0) * (x + 0.5);
		double down = (x - 0.5) * (x + 0.4);
		if (down == 0.0) {
			raise(SIGFPE);
			continue;
		}
		ans = up / down;
		printf("%lf\n", ans);
	}
	return 0;
}