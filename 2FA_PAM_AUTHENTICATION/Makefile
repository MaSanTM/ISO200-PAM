
pam_access.o: pam_access.c      # sudo make
        gcc -fPIC  -fno-stack-protector -c pam_access.c

install: pam_access.o                   # sudo make install
        ld  -x --shared -o /lib64/security/pam_access.so pam_access.o
        sed -i "4s/^/   auth      required  pam_access.so\n/" /etc/pam.d/system-auth
        clear
        @echo - > Modules installed sucessfull!

uninstall:                                              # sudo make uninstall
        rm -f /lib64/security/pam_access.so
        rm -rf /etc/pam.d/pam.access
        sed -i '/pam_access/d' /etc/pam.d/system-auth
        clear
        @echo  -> Modules uninstalled sucessfull.   
