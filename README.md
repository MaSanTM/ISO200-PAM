<h1>PAM 2FA</h1> 
<h2>A PAM module using USB device to authenticate.</h2>
<p>This module was developed for Operational Systems II class in my technologycal degree. Below will be the entire installation and execution process.</p>
<h2>Arch Linux</h2>
<img src="https://archlinux.org/static/logos/archlinux-logo-dark-90dpi.ebdee92a15b3.png" alt="alt text"
 width="" height="">
 <p>For this, was used Arch Linux distribution. The version, is not so important and can be downloaded here: https://archlinux.org/download/ You are free to use any Linux distribution you like.</p>

<h1>1 PRE-INSTALLATION</h1>
<h2>1.1 Makepkg</h2>
<h3>1.1.1 Installing Make</h3>

You'll need Make to run the commands for the installation. So:
```bash
# pacman -S make
```
<h3>1.1.2 Checking Make</h3>

```bash
# make -help
```
<h2>1.2 GNU Compiler Collection - GCC</h2>
<h3>1.2.1 Installing GCC</h3>
Then install the GCC to Makepkg work correctly:

```bash
# pacman -S gcc
```
<h3>1.2.2 Checking</h3>

```bash
# gcc -h
```

## conio.h library

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
