
pam_acesso2.o: pam_acesso2.c	# sudo make
	gcc -fPIC  -fno-stack-protector -c pam_acesso2.c

install: pam_acesso2.o 			# sudo make install
	ld  -x --shared -o /lib64/security/pam_acesso2.so pam_acesso2.o
	sed -i "4s/^/	auth	  required  pam_acesso2.so\n/" /etc/pam.d/system-auth
	clear
	@echo "\nModules installed sucessfull!\n"

uninstall: 						# sudo make uninstall
	rm -f /lib64/security/pam_acesso2.so 
	rm -rf /etc/pam.d/pam.acesso
	sed -i '/pam_acesso2/d' /etc/pam.d/system-auth
	clear
	@echo "\n -> Modules uninstalled sucessfull.\n"