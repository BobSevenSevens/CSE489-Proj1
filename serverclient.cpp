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
#include <iostream>

#include "../include/logger.h"

using namespace std;

int main(int argc, char* argv[]){
/*  Parse cmd and args from the input */
	char *minghann = "Henry Heis";
	char *rhrosent = "Rhrosent";
	/*
	argc = 0;
	char * cmd = "chat_app";
	char *arg = strtok(cmd," ");
	while(arg){
		strcpy(argv[argc],arg);
		argc += 1;

		arg = strtok(NULL, " ");
	}*/
	char mode = 's'; // default mode is server
	char *port = "5000"; // default Port
	for(int i = 0; i < argc; i++){
		switch(i){
			// interpret cmd ./chat_app s 4322
			case 1:
			    mode = argv[i][0];
			break;
			case 2:
				port = argv[i];
			break;
			default:
			break;
		}
	}
	if(mode == 's'){
		cout << "Hi, I'm server" << endl;
		cout << "Port #: " << port << endl;
		// int status;
		// struct addrinfo hints;
		// struct addrinfo *serverinfo;	 //will point to the results

		// memset(&hints, 0, sizeof hints); // Make sure the struct is empty
		// hints.ai_family = AF_UNSPEC; 	 // Don't care IPv4 or IPv6
		// hints.ai_socktype = SOCK_STREAM; // TCP stream sockets
		// // hints.ai_flags = AI_PASSIVE;	 // Fill in my IP for me

		// if((status = getaddrinfo(NULL, port, &hints, &servinfo)) !=0){
		//  	fprintf(stderr, "getaddrinfo error: %s\n", gai_strerror(status));
		//  	exit(1);
		// }
		
		// // servinfo now points to a linked list of 1 or more struct addrinfos
		// // ... do everything until you don't need servinfo anymore ...

		// freeaddrinfo(servinfo); // free the linked-list
	}
	if(mode == 'c'){
		cout << "Hi, I'm Client" << endl;
		cout << "Port #: " << port << endl;
	}
}
