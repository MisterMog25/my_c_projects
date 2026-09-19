#include <stdio.h>
#include <time.h>
#include <stdbool.h>
#include <unistd.h>



int main(void){
    time_t rawtime = 0;
    struct tm *pTime = NULL;
    bool isRunning = true;

    printf("DIGITAL CLOCK\n");
    while (isRunning){

        time(&rawtime);

        pTime = localtime(&rawtime);

        printf("\r%02d:%02d:%02d", pTime -> tm_hour, pTime->tm_min, pTime->tm_sec);
        fflush(stdout);
        sleep(1);

    }

    return 0;
}