/*
Author Ming Hann Hsieh 

Starts off as a server or client on a given port
Created for CSE489 Spring 2017 Programming Assignment 1
Created 18 Feb 2017
*/

#include <stdio.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netdb.h>
#include <arpa/inet.h>
#include <netinet/in.h>


/*  Parse cmd and args from the input */
argc = 0;
arg = strtok(cmd," ");
while(arg){
	strcpy(argv[argc],arg);
	argc += 1;

	arg = strtok(NULL, " ");
}

/* Process commands */
if((strcmp(argv[0], "HELP"))){
	fprintf("[%s:SUCCESS]\n", command_str);
	else{
		fprintf("[%s:ERROR]\n", command_str);
	}
}

if((strcmp(argv[0], "IP"))){
	fprintf("[%s:SUCCESS]\n", command_str);
	else{
		fprintf("[%s:ERROR]\n", command_str);
}

if((strcmp(argv[0], "PORT"))){
	fprintf("[%s:SUCCESS]\n", command_str);
	else{
		fprintf("[%s:ERROR]\n", command_str);
}

if((strcmp(argv[0], "LOGIN"))){
	fprintf("[%s:SUCCESS]\n", command_str);
	else{
		fprintf("[%s:ERROR]\n", command_str);
}

if((strcmp(argv[0], "LIST"))){
	fprintf("[%s:SUCCESS]\n", command_str);
	else{
		fprintf("[%s:ERROR]\n", command_str);
}

if((strcmp(argv[0], "SEND"))){
	fprintf("[%s:SUCCESS]\n", command_str);
	else{
		fprintf("[%s:ERROR]\n", command_str);
}

if((strcmp(argv[0], "LOGOUT"))){
	fprintf("[%s:SUCCESS]\n", command_str);
	else{
		fprintf("[%s:ERROR]\n", command_str);
}

if((strcmp(argv[0], "EXIT"))){
	fprintf("[%s:SUCCESS]\n", command_str);
	else{
		fprintf("[%s:ERROR]\n", command_str);
}


int status;
struct addrinfo hints;
struct addrinfo *serverinfo;	 //will point to the results

memset(&hints, 0, sizeof hints); // Make sure the struct is empty
hints.ai_family = AF_UNSPEC; 	 // Don't care IPv4 or IPv6
hints.ai_socktype = SOCK_STREAM; // TCP stream sockets
hints.ai_flags = AI_PASSIVE;	 // Fill in my IP for me

if((status = getaddrinfo(NULL, "3490", &hints, &servinfo)) !=0){
	fprintf(stderr, "getaddrinfo error: %s\n", gai_strerror(status));
	exit(1);
}
// servinfo now points to a linked list of 1 or more struct addrinfos
// ... do everything until you don't need servinfo anymore ...

freeaddrinfo(servinfo); // free the linked-list

/*Server Socket Setup*/
server_socket = socket(AF_INET, SOCK_STREAM, 0);
if(server_socket < 0){
	return err_msg_ERR("Cannot create socket");
}

bzero(&server_addr, sizeof(server_addr));

server_addr.sin_family = AF_INET;
server_addr.sin_addr.s_addr = hton1(INADDR_ANY);
server_addr.sin_port = htons(port);

printf("Port: %d:", ntohs(server_addr.sin_port));

if(bind(server_socket, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0){
	return err_msg_ERR("Bind failed");
}

if(listen(server_socket, BACKLOG) < 0){
	fprintf(stderr, "Unable to listen on port %d", port);
	return -1;
}

caddr_len = sizeof(client_addr);
fdaccept = accept(server_socket, (struct sockaddr *)&client_addr, &caddr_len);
if(fdaccept < 0){
	return err_msg_ERR("Accept failed.");
}

/* connect() */

fdsocket = socket(AF_INET, SOCK_STREAM, 0);
if(fdsocket < 0){
	return err_msg_ERR("Failed to create socket");
}

bzero(&server_addr, sizeof(server_addr));
server_addr.sin_family = AF_INET;
inet_pton(AF_INET, server_ip, &server_addr.sin_addr);
server_addr.sin_port = htons(server_port);

if(connect(fdsocket, (struct sockaddr*)&server_addr, sizeof(server_addr)) < 0){
	return err_msg_ERR("Connect failed.");
}

/* Select() */
FD_ZERO(&master_list);
FD_ZERO(&watch_list);
head_socket = server_socket;
/* Register the listening socket */
FD_SET(server_socket, &master_list);
/* Register STDIN */
FD_SET(STDIN, &master_list);


/* Select) Control flow */
while(TRUE){
	,,,,,
	,,,,,
	selret = select(head_socket + 1, &watch_list, NULL, NULL, NULL);
	if(selret<0){
		return printf("select failed.");
	}
	/* Check if we have sockets/STDIN to process */
	if(selret > 0){
		/* Loop through socket descriptors to check which ones are ready */
		for(sock_index=0; sock_index<=head_socket; sock_index+=1){
			if(FD_ISSET(sock_index, &watch_list)){
				/* Check if new command on STDIN */
				if(sock_index == STDIN){
					,,,,,
				}
				/* Check if new client is requesting connection */
				else if(sock_index == server_socket){
					,,,,,
					/* Add to watched socket list */

				}
				/* Read from existing clients */
				else{
					,,,,,
				}
			}
		}
	}
}
