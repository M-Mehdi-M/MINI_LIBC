#include <time.h>
#include <unistd.h>

unsigned int sleep(unsigned int seconds) {
    /* TODO: Implement sleep(). */
    struct timespec req, rem;
    req.tv_sec = (long)seconds;
    req.tv_nsec = 0;

    int result;

    do {
        result = nanosleep(&req, &rem);
        if (result == 0)
            break;
        if (result == -1 && rem.tv_sec > 0) {
            req = rem;
        } else {
            return (unsigned int)-1;
        }
    } while (1);

    return 0;
}
