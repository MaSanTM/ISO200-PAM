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

    //if = 0 directory doesn't exist | if -1 = existent
    struct stat st = {0};
	
    //if -1, return the message, else don't create the directory
	if (stat("/etc/pam.d/pam.pdrive", &st) == -1) {
		if(mkdir("/etc/pam.d/pam.pdrive", 0700) == 0){
            printf("    Directory created successfully: /pam.pdrive\n");
		}else{
            printf("    Error creating the directory: /pam.pdrive\n");
        }
	}else{
            printf("    Directory already exists: /pam.pdrive\n");
    }
}

void makeDirLog(){

        //save the state, if = 0 then  directory doesn't exist | if = -1 existent
        struct stat st = {0};
        
        //if = 1, return the message, else don't create the directory
        if (stat("/etc/pam.d/pam.pdrive/log", &st) == -1) {
                if(mkdir("/etc/pam.d/pam.pdrive/log", 0700) == 0){
                    printf("    Directory create successfully: /log\n");
                }else{
                    printf("    Error creating the directory: /log\n");
                }
            }else{
                    printf("    Directory already exists: /log\n");
        }
}

void makeFileSerial(){
    FILE *pdrive_serial;
    
    pdrive_serial = fopen("/etc/pam.d/pam.pdrive/pdrive.serial", "a");

    if (pdrive_serial == NULL){
        printf("    Error creating the serial file...\n");
    }
    else{
        printf("    Serial files created sucessfully!\n");
    }
}

void makeFileLog(){
    FILE *log;
    
    log = fopen("/etc/pam.d/pam.pdrive/log/login", "a");

    if (log == NULL){
        printf("    Error creating login history files...\n");
    }
    else{
        printf("    Login history files created successfully!\n");
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

    FILE *pont_arq; // pointer to the variable file
        
        //opening the file with "w" type
        pont_arq = fopen("/etc/pam.d/pam.pdrive/pdrive.serial", "w");
        
        //testing the file
        if(pont_arq == NULL)
        {
        printf("    Erro na abertura do arquivo!");
        }
        
        //using fprintf to store the string into a file
        fprintf(pont_arq, "%s", buf);

        //using fclose to close the file
        fclose(pont_arq);

        puts("    Device registered successfully!\n");

}

int main(int argc, char *argv[]){
    system("clear");

    puts("\n\n-> WELCOME TO THE PAM 2FA MODULE!");
    puts("\n\n-> 1 - Make sure that the flash drive is connected and installed.");
    puts("\n-> 2 - Make sure thath only a single flash drive is connected and installed.");
    puts("\n-> 3 - If not detected, the program will terminate.");
    system("read -p \"\nPress Enter to continue...\" foo");

    system("clear"); 

     puts("\n-> Starting installation:");
    puts("---------------------------------------------------");
    sleep(2);

    puts("\n-> Creating module configuration directories:");
    puts("   '/etc/pam.d/pam.pdrive'");
    puts("   '/etc/pam.d/pam.pdrive/log'");
    makeDirPdrive();
    makeDirLog();
    sleep(2);

    puts("\n-> Creating the files that store the serials:");
    puts("   '/etc/pam.d/pam.pdrive'");
    puts("   '/etc/pam.d/pam.pdrive/log'");
    makeFileSerial();
    makeFileLog(); 

    char nome[100]; 

    puts("\n-> Registering the USB device:");

    addUser(nome);

    system("read -p \"Press Enter to continue...\" foo");

}
