This program scans all the ports on a system and displays the port number of the open ports.

##Step 1
Write the .x file 
##Step 2
		rpcgen -a port.x
This will generate the header files, client stub, server stub and XDR routines and template for the server and client .c files.
##Step 3
Check if portmap is installed. If not
		sudo apt-get install portmap
##Step 4
		sudo -i service portmap stop
		sudo -i rpcbind -i -w
		sudo -i service portmap start
##Step 5
Compile the server.c and client.c
		gcc -o server port_server.c port_svc.c port_xdr.c 
		gcc -o port_client client.c echo_clnt.c echo_xdr.c
##Step 6
Run the executables

		./server
		./client IP
		

IP can be the IP adress of any machine.
 
 
  
