#include "malloc.h"
#include <stdio.h>

int main(int argc, char** argv)
{
	printf("Malloc tests\n");
	printf("-- Initializing\n");

	char buf[1024];
	sp_malloc_init(buf, 1024);

	printf("-- Checking space: %ld, ", sp_malloc_space());
	if (sp_malloc_space() == 1024 - 2 * sizeof(char*))
	{
		printf("ok\n");
	}
	else
	{
		printf("fail\n");
		return -1;
	}

	printf("-- Allocating memory: ");
	char* mem = sp_malloc(10);
	if (mem != NULL)
	{
		printf("ok\n");
	}
	else
	{
		printf("fail\n");
		return -1;
	}

	printf("-- Checking space: %ld, ", sp_malloc_space());
	if (sp_malloc_space() == 1024 - 4 * sizeof(char*) - 10)
	{
		printf("ok\n");
	}
	else
	{
		printf("fail\n");
		return -1;
	}

	printf("-- Free memory\n");
	sp_free(mem);

	printf("-- Checking space: %ld, ", sp_malloc_space());
	if (sp_malloc_space() == 1024 - 2 * sizeof(char*))
	{
		printf("ok\n");
	}
	else
	{
		printf("fail\n");
		return -1;
	}

	return 0;
}
