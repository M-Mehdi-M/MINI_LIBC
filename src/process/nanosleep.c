#include <time.h>
#include <unistd.h>
#include <internal/syscall.h>

int nanosleep(const struct timespec *req, struct timespec *rem) {
    /* TODO: Implement nanosleep(). */

    int result = syscall(__NR_nanosleep, req, rem);

    if (result == -1) {
        if (rem != NULL) {
            rem->tv_sec = 0;
            rem->tv_nsec = 0;
        }
        return -1;
    }
    return result;
}
