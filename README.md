# ISO200-PAM 
**A PAM 2FA project to the ISO200 class at FATEC Americana.**


For this, was used **Arch Linux** distribution the version, is not so important. You can download it here: https://archlinux.org/download/

## $PATH

The file userLogin.c was created to insert him inside the ```/bin/bash``` directory on distribution. As we know, this directory contains all binaries of the system, ie we can run the command direct from the Shell. For example:
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

## conio.h

Running the _.c_ script, you'll get the following error:
```bash
userLogin.c:5:10: fatal error: conio.h: No such file or directory
  5 | #include <conio.h>
    |
compilation terminated.
```
So i made some changes in the script, exchanging the _conio.h_ libray by the _ncurses.h_ . Follow the Step-by-Step section to install in your system.

## ncurse.h installation

### Installing in Debian and derivates:

1. Some packages will need to be installed before the library. Run the command:
```bash
~# apt-get install libncurses5-dev libncursesw5-dev
```
### Installing in RHEL and derivates:

1. A package is need to install the library in *.rpm* distros. Run the command:
```bash
~# dnf install ncurses-devel
```
