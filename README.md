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

<h2>1.3 Git - Version Control</h2>
<h4>1.3.1 Installing Git</h4>
Next install the Git to clone the repository:

```bash
# pacman -S git
```

<h3>1.3.2 Checking</h3>

```bash
# git -h
```

<h1>2 INSTALLATION</h1>
<h2>2.1 Cloning the repository:</h2>

```bash
# git clone https://www.github.com/MaSanTM/PAM_2FA
```

You can see the repository in the directory that you have dowloaded it.
<h2>2.2 The source files</h2>
Entering in the source folder you'll see some files in .c and a Makefile. If you want, see the contents.

```bash
# cat addpendrive.c
```

or

```bash
# cat Makefile
```

<h3>2.2.1 The Makefile</h3>
The Makefile will automate your installation process. So run it:

```bash
# make 
# make install 
```

Read the instructions and follow to the next step.

<h2>2.3 /etc/pam.d </h2>
Now, you can go to the PAM directories of your distribution:

```c
# cd /etc/pam.d
```