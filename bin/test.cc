#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h> /* for fork */
#include <sys/types.h> /* for pid_t */
#include <sys/wait.h> /* for wait */

int main(int argc, char** argv)
{
    int ncore;
    if (argc == 2) {
        ncore = atoi(argv[1]);
    } else {
        printf("Usage: test [ncore]\n");
        exit(0);
    }
    
     
    printf("cores: %d\n", ncore);
 
    printf("Mapbench %s local\n", argv[1]);
    pid_t pid=fork();
    if (pid == 0) {
        char name[] = "mapbench";
        char local[] = "local";
        char *__argv[] = {name, argv[1], local};
        execv("mapbench", __argv);
        exit(127); /* only if execv fails */
    }
    else {
        waitpid(pid,0,0);
    }
    
    printf("\n\n");
    sleep(2);

    printf("Countbench %s\n", argv[1]);
    pid=fork();
    if (pid == 0) {
        char name[] = "countbench";
        char *__argv[] = {name, argv[1], NULL};
        execv("countbench", __argv);
        exit(127);
    }
    else {
        waitpid(pid,0,0);
    }
 
    printf("\n\n");
    sleep(2);
    
    printf("Schedbench 10 %s\n", argv[1]);
    pid=fork();
    if (pid == 0) {
        char name[] = "schedbench";
        char iters[] = "10";
        char *__argv[] = {name, iters, argv[1], NULL};
        execv("schedbench", __argv);
        exit(127); 
    }
    else {
        waitpid(pid,0,0);
    }
 
    printf("\n\n");
    sleep(2);
    
    printf("Filebench %s 10\n", argv[1]);
    pid=fork();
    if (pid == 0) {
        char name[] = "filebench";
        char nloops[] = "10";
        char *__argv[] = {name, argv[1], nloops, NULL};
        execv("filebench", __argv);
        exit(127); 
    }
    else {
        waitpid(pid,0,0);
    }

    
    printf("\n\n");
    sleep(2);
    
    printf("Linkbench 0 %s\n", argv[1]);
    pid=fork();
    if (pid == 0) {
        char name[] = "linkbench";
        char nstat[] = "0";
        char *__argv[] = {name, nstat, argv[1], NULL};
        execv("linkbench", __argv);
        exit(127); 
    }
    else {
        waitpid(pid,0,0);
    }

    
    printf("\n\n");
    sleep(2);
    
    printf("Fdbench %s\n", argv[1]);
    pid=fork();
    if (pid == 0) {
        char name[] = "fdbench";
        char *__argv[] = {name, argv[1], NULL};
        execv("fdbench", __argv);
        exit(127); 
    }
    else {
        waitpid(pid,0,0);
    }
    
    return 0;
}
