#include <dirent.h>
#include <stdio.h>
#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <time.h>
#include <errno.h>
#include <pwd.h>
int main()
{
    system("clear");

    struct tm *data_hora_atual;
    time_t segundos;    
    time(&segundos);   
    data_hora_atual = localtime(&segundos);  

    ssize_t len;
     
    char buf[256], *p;
    char buf2[256];
    int i;
   
    len = readlink("/sys/block/sdb", buf, 256);
   
    buf[len] = 0;
   
    // printf("%s\n", buf);
    sprintf(buf2, "%s/%s", "/sys/block/", buf);
    for (i=0; i<6; i++) {
        p = strrchr(buf2, '/');
        *p = 0;
    }
   
    // printf("%s\n", buf2);
    strcat(buf2, "/serial");
    // printf("opening %s\n", buf2);

    int f = open(buf2, 0);
    len = read(f, buf, 256);
    if (len <= 0) {
        
    }
 
    buf[len] = 0;

    FILE *pont_arq; // creates the variable pointer to the file
        
        //open a "w" type file
        pont_arq = fopen("/etc/pam.d/pam.pdrive/pdrive.serial", "a");
        
        //testing file
        if(pont_arq == NULL)
        {
        printf("    \n\n  ->ERROR: opening the file!");
        }
        
        //fprintf to store the string into the file
        fprintf(pont_arq, "\n%s", buf);

        //fclose to close the file
        fclose(pont_arq);

        puts("    \n\n-> Flash drive registered successfully!\n\n");
  
  
}
