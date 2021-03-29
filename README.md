# ISO200-PAM 
**A PAM 2FA project to the ISO200 class at FATEC Americana.**


For use, you'll need an **Arch Linux** distribution: https://archlinux.org/download/ the version, is very irrelevant.

# /bin/bash

The file userLogin.c was created to insert him inside the _/bin/bash_ directory on distribution. As we know, this directory contains all binaries of the system, ie we can run the command direct from the Shell. For example:
```
~$ userLogin
~$ A Token was sent to your device, insert in to proceed:
~$ 
```
And will activate the determinate command for the Two Factor Authentication. You can the _.c_ file into the directory simple following the script:
```bash
echo userLogin.c >>> /bin/bash
```
Then you can test running the "new command".

# conio.h

Running the _.c_ script, you'll get the following error:
```bash
userLogin.c:5:10: fatal error: conio.h: No such file or directory
  5 | #include <conio.h>
    |
compilation terminated.
```
So i made some changes in the script, exchanging the _conio.h_ libray by the _ncurses.h_ . Follow the Step-by-Step section to install in your system.

# ncurse.h installation

### Installing in Debian and derivates:
