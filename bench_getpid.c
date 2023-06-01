#include <stdio.h>
#include <sys/syscall.h>
#include <unistd.h>
#include <time.h>
#include <sys/types.h>
#include <stdlib.h>

void timespec_diff(struct timespec *start, struct timespec *stop, struct timespec *result)
{
	if ((stop->tv_nsec - start->tv_nsec) < 0)
	{
		result->tv_sec = stop->tv_sec - start->tv_sec - 1;
		result->tv_nsec = stop->tv_nsec - start->tv_nsec + 1000000000;
	}
	else
	{
		result->tv_sec = stop->tv_sec - start->tv_sec;
		result->tv_nsec = stop->tv_nsec - start->tv_nsec;
	}
}

int main(int argc, char* argv[])
{
	unsigned int i, iter;
	struct timespec t1;
	struct timespec t2;
	struct timespec t3;

	if (argc != 2)
	{
		fprintf(stderr, "Usage: bench_getpid <iter>\n");
		return 1;
	}

	iter = atoi(argv[1]);

	if (!iter)
	{
		fprintf(stderr, "Invalid input\n");
		return 1;
	}

	fprintf(stdout, "Press any key to start! PID: %d\n",
			syscall(SYS_getpid));
	getchar();

	clock_gettime(CLOCK_MONOTONIC_RAW, &t1);
	for (i = 0; i < iter; i++) syscall(SYS_getpid);
	clock_gettime(CLOCK_MONOTONIC_RAW, &t2);

	timespec_diff(&t1, &t2, &t3);
	printf("Duration: %lu\n", t3.tv_sec * 1000000 + t3.tv_nsec / 1000);

	return 0;
}
