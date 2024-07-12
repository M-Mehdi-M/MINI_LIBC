#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <errno.h>
#include <internal/types.h>
#include <internal/syscall.h>

int puts(const char *str) {
    /* TODO: Implement puts(). */
    size_t len = strlen(str);

    int result = syscall(__NR_write, 1, str, len);
    result = syscall(__NR_write, 1, "\n", 1);

    if (result < 0) {
		errno = -result;
		return -1;
	}

    return 0;
}
