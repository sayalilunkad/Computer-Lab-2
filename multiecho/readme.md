This program builds a multi-threaded echo server.

##Step 1
Write the .x file which is the default file for RPCGENinput files.

##Step 2
For multi-threading applications run the .X with -M
		rpcgen -M -a echo.x
This will generate the header files, client stub, server stub and XDR routines and template for the server and client .c files.

##Step 3
Edit the .c files to add required functionalities.

##Step 4
Compile the server.c and client.c 

		gcc -o echo_server server.c echo_svc.c echo_xdr.c
		gcc -o echo_client client.c echo_clnt.c echo_xdr.c

#Step 5
Run the server and client
				
				./server
				./client
