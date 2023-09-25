#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>


int main()
{
	pid_t child = fork();
	if (child == 0) {
		while (1) {
			puts("EXO");
			sleep(1);
		}
	} else {
		sleep(4);
		kill(child, SIGSTOP); // stop
		sleep(3);
		kill(child, SIGCONT); // continue
		sleep(2);
		kill(child, SIGTERM); //terminate
	}
	return 0;
}

