#include <stdio.h>
#include <fcntl.h>           /* For O_* constants */
#include <sys/stat.h>        /* For mode constants */
#include <semaphore.h>
#include <unistd.h>

int main(void)
{
    int res = sem_unlink("/test.sem");
    if (res == -1) {
        perror("sem_unlink");
        //return 1;
    }

    sem_t *sem = sem_open("/test.sem", O_RDONLY | O_CREAT, 0666, 66);
    if (sem == SEM_FAILED) {
        perror("sem_open");
        return 1;
    }

    pause();

    res = sem_close(sem);
    if (res == -1) {
        perror("sem_close");
        return 1;
    }

    return 0;
}
