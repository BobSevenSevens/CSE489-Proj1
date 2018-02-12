#include <cstddef>
#include <cstdlib>
#include <iostream>

//not sure about these 2 but its in the guide so ???
#include <sys/types.h>
#include <sys/socket.h>



void connection(){
	getaddrinfo(); //Pretty sure we have to fill these 3 in with port etc.
	socket();
	bind();
	listen();  //Wait for a connection request from a client
	int newreq(int s, struct sockaddr *addr, socklen_t *addrlen); //Accepts request, data is in the variables(?)
	//Then do stuff here based off what the client is requesting
	
}

int main(int argc, char**argv){ //This takes command line arguments

string userinput;
cout << "Input command";
cin >> userinput;

if(userinput == "AUTHOR"){
	cout << (“I, %s, have read and understood the course academic integrity policy.\n”, rhrosent)
	cout << (“I, %s, have read and understood the course academic integrity policy.\n”, your_ubit_name) //Fill in yours here?
	}
if(userinput == "IP"){
	//Get and print server IP
	cout << (“IP:%s\n”, ip_addr)
}	

if(userinput == "PORT"){
	//Get and print server port
	cout << (“PORT:%d\n”, port)


	
}