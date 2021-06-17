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


void makeDirPdrive(){

      //variable that save the state
     // if = 0 directory doesn't exist
    // if = -1 directory exist
    struct stat st = {0};
	
      //if = -1 
     //then return the message;
    // else creates the directory
	if (stat("/etc/pam.d/pam.pdrive", &st) == -1) {
		if(mkdir("/etc/pam.d/pam.pdrive", 0700) == 0){
            printf("    Directory created: /pam.pdrive\n");
		}else{
            printf("    ERROR creating directory: /pam.pdrive\n");
        }
	}else{
            printf("    Existing directory: /pam.pdrive\n");
    }
}

void makeDirLog(){

        //variable that save the state
       // if = 0 directory doesn't exist
      // if = -1 directory exist
        struct stat st = {0};
        
        //if = -1 
       //then return the message;
      // else creates the directory
        if (stat("/etc/pam.d/pam.pdrive/log", &st) == -1) {
                if(mkdir("/etc/pam.d/pam.pdrive/log", 0700) == 0){
                    printf("    Directory created: /log\n");
                }else{
                    printf("    ERROR creating directory: /log\n");
                }
            }else{
                    printf("    Existing directory: /log\n");
        }
}

void makeFileSerial(){
    FILE *pdrive_serial;
    
    pdrive_serial = fopen("/etc/pam.d/pam.pdrive/pdrive.serial", "a");

    if (pdrive_serial == NULL){
        printf("    ERROR creating the serials...\n");
    }
    else{
        printf("    Serial files created successfully!\n");
    }
}

void makeFileLog(){
    FILE *log;
    
    log = fopen("/etc/pam.d/pam.pdrive/log/login", "a");

    if (log == NULL){
        printf("    ERROR creating the logins history...\n");
    }
    else{
        printf("    Logins history files created successfully!\n");
    }
}


int verPendrive(){
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
        printf("Erro");
    }
 
    buf[len - 1] = 0;

    int qtd = strlen(buf);

    return qtd;
    
}

char verSerial(){
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
 
    buf[len - 1] = 0;
    

    return buf;

}


void addUser( char nome[256] ){
    ssize_t len;
     
    char buf[256], *p;
    char buf2[256];
    int i;
   
    len = readlink("/sys/block/sdb", buf, 256);
   
    buf[len] = 0;
   
    sprintf(buf2, "%s/%s", "/sys/block/", buf);
    for (i=0; i<6; i++) {
        p = strrchr(buf2, '/');
        *p = 0;
    }
   
    strcat(buf2, "/serial");

    int f = open(buf2, 0);
    len = read(f, buf, 256);
    if (len <= 0) {
        
    }
 
    buf[len - 1] = 0;

    FILE *pont_arq; //creates the variable pointer to the file
        //opening "w" type files
        pont_arq = fopen("/etc/pam.d/pam.pdrive/pdrive.serial", "w");
        
        //testing files
        if(pont_arq == NULL)
        {
        printf("    ERROR: opening the file...");
        }
        
        //fprintf to store the string into the file
        fprintf(pont_arq, "%s", buf);

        //fclose to close the file
        fclose(pont_arq);

        puts("    USB device registered successfully!\n");

}

int main(int argc, char *argv[]){
    system("clear");

    puts("\n\n-> WELCOME TO THE PAM 2FA MODULE!")
    puts("\n-> 1 - Make sure that the flash drive is connected and installed;");
    puts("\n-> 2 - Make sure thath only one flash drive is connected in your machine;");
    puts("\n-> 3 - If any USB device be detected, the program will be close;");
    system("read -p \"\nPress Enter to continue...\" foo");

    system("clear"); 

     puts("\n-> Installing:");
    puts("---------------------------------------------------");
    sleep(2);

    puts("\n-> Creating the configuration modules:");
    puts("   '/etc/pam.d/pam.pdrive'");
    puts("   '/etc/pam.d/pam.pdrive/log'");
    makeDirPdrive();
    makeDirLog();
    sleep(2);

    puts("\n-> Creating the file that will store the serials:");
    puts("   '/etc/pam.d/pam.pdrive'");
    puts("   '/etc/pam.d/pam.pdrive/log'");
    makeFileSerial();
    makeFileLog(); 

    char nome[100]; 

    puts("\n-> Flash drive registered!"");

    addUser(nome);

    system("read -p \"Press Enter to continue...\" foo");

}
