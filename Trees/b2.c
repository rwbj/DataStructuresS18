#include <stdio.h>

main(argc, argv, envp)
int argc;
char **argv, **envp;
{
	unsigned int  cnt=0;
	float f, df;
	f = 0.000001;
	df = 0.000001;

	while (1) {
		f+= df;
		if ((++cnt % 1000000) == 0) {
			printf("f=%f   df=%f    ", f, df);
			printf("cnt = %d\n", cnt);
			df = df+0.000001;
			//sleep(1);
		}
	}
}
