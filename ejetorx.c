#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

void *abrir()
{

    system("eject -T");
    sleep(5);
    return NULL;
}

void *tocar()
{

    system("aplay x.wav");
    return NULL;
}

void main(int argc, char argv[])
{
    pthread_t thread_idMus;
    printf("Tocando\n");
    pthread_create(&thread_idMus, NULL, tocar, NULL);
    pthread_join(thread_idMus, NULL);

    while (1)
    {
        pthread_t thread_id;
        printf("Criando a caralha da Thread\n");
        pthread_create(&thread_id, NULL, abrir, NULL);
        pthread_join(thread_id, NULL);
        printf("Executou essa merda!\n");
    }
}
