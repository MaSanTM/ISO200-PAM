/*
    * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
   * AUTHOR: SANTOS, Mateus Henrique                        *
   * SEE ME IN: linkedin.com/in/mateus-h-santos             *
   * COPYRIGHT (C) Mateus Henrique dos Santos, 2021         *
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
{
        return PAM_SUCCESS;
}
PAM_EXTERN int pam_sm_authenticate( pam_handle_t *pamh, int flags,int argc, const char **argv )
{
      FILE *g= fopen("/etc/pam.d/pam.acesso/acesso.serial", "r");

    if (!g)
      {
        perror("\nAccess denied! See /etc/pam.d/pam.access/serial.access.");
                sleep(2);
                return PAM_AUTH_ERR;
      }
   else
           return PAM_SUCCESS;

       fclose(g);
}
