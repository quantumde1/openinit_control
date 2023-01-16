#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>

/* Licensed under BSD */
/* OhiOS Project, 2022, all rights reserved */

void create_service(char* name)
{
    //create a service from a command you give, which need to include runlevel for service, depends of him and his name
    FILE *fp;
    fp = fopen(strcat("/etc/openinit.d/", name), "w");
    if(fp == NULL) {
        printf("file can't be opened\n");
        exit(1);
    }
    printf("Writing file configuration");
    fprintf(fp, strcat("#!/bin/sh\n exec ", name));
    fclose(fp);
    chmod(strcat("/etc/openinit.d/", name), 777);
    printf("Writing finished");
}

void run_service(char* name)
{
    system(strcat("/etc/openinit.d/", name));
}

void stop_service(char* name)
{
    char line[50];
    FILE *cmd = popen(strcat("pidof ", name), "r");
    fgets(line, 50, cmd);
    pid_t pid = strtoul(line, NULL, 10);
    pclose(cmd);
}

void disable_service(char* name)
{
    //TODO implement disable service
}

void enable_service(char* name)
{
    //TODO implement enable service
}