<h1>ISO200-PAM</h1> 
<h2>A PAM 2FA using USB device to authenticate.</h2>

<img src="https://archlinux.org/static/logos/archlinux-logo-dark-90dpi.ebdee92a15b3.png" alt="alt text"
 width="" height="">
 <p>For this, was used Arch Linux distribution. The version, is not so important and can be downloaded here: https://archlinux.org/download/ You are free to use any Linux distribution you like.</p>

<h3>HOW-TO</h3>
<h4>Installing Make</h4>

First of all, you'll need Make to run the commands for the installation. So:
```bash
# pacman -S make
# man make
```
or
```
# make -help
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
