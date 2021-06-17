

pam_pdrive.o: pam_pdrive.c
	gcc -fPIC -lcurl -fno-stack-protector -c pam_pdrive.c

install: pam_pdrive.o
	ld -lcurl -x --shared -o /lib64/security/pam_pdrive.so pam_pdrive.o
	sed -i "4s/^/	auth	  required  pam_pdrive.so\n/" /etc/pam.d/system-auth
	gcc create_file.c -o create_file
	gcc add_usb.c -o add_usb
	./criar_arquivos

uninstall:
	rm -f /lib64/security/pam_pdrive.so
	rm -rf /etc/pam.d/pam.pdrive
	sed -i '/pam_pdrive/d' /etc/pam.d/system-auth
	clear
	@echo "\n\n -> Authentication module removed successfully!.\n\n"

addpendrive:
	./add_usb