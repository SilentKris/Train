#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <assert.h>

int main()
{
	int ret;

	ret = mkfifo("./fifo.txt", 0640);
	assert(!ret);
	return 0;
}
