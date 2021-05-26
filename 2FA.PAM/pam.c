/* 
   * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
  * AUTHOR: Mateus Henrique dos Santos                     *
  * See this repository in: github.com/MaSanTM/ISO200-PAM  *
  * See my profile in: linkedin.com/in/mateus-h-santos     *
  * Copyright (c) Mateus Henrique dos Santos, 2021         *
   * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 */
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
#include <security/pam_modules.h>
#include <security/pam_ext.h>

#define _GNU_SOURCE 
    
PAM_EXTERN int pam_sm_setcred( pam_handle_t *pamh, int flags, int argc, const char **argv ) 

{ return PAM_SUCCESS;}

PAM_EXTERN int pam_sm_authenticate( pam_handle_t *pamh, int flags,int argc, const char **argv ) 
{
      FILE *g= fopen("/etc/pam.d/pam.acesso/acesso.serial", "r");
      
    if (!g)
      {
        perror("Acces denied! See /etc/pam.d/pam.access/serial.access.\n
        The file can be created or edited by $ vi /etc/pam.d/pam.access/serial.access");
		sleep(2);
		return PAM_AUTH_ERR;	
      }
   else
	   return PAM_SUCCESS;
       fclose(g);
}