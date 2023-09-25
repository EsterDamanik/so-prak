#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>

int main(){
	puts("jalan");
	system("shutdown now");
	//execlp("ps", "ps", "-A", NULL);
	//char *args[] = ("cal","cal 6 2023", NULL);
	//execvp(args[0], args);
	puts("done");
	return 0;
}
