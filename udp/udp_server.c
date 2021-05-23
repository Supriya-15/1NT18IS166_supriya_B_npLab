#include<stdio.h>
#include<string.h>
#include<sys/socket.h>
#include<arpa/inet.h>

int main(void)
{
	int socket_desc;
	struct sockaddr_in server_addr,client_addr;
	char server_message[100],client_message[100];
	int client_struct_length=sizeof(client_addr);
	
	//clean buffers:
	memset(server_message,'\0',sizeof(server_message));
	memset(client_message,'\0',sizeof(client_message));
	
	//create udp socket:
	socket_desc=socket(AF_INET,SOCK_DGRAM,IPPROTO_UDP);
	
	if(socket_desc<0){
	printf("Error while creating a socket \n");
	return -1;
	}
	
	printf("Socket created successfullly \n");
	
	server_addr.sin_family=AF_INET;
	server_addr.sin_port=htons(2000);
	server_addr.sin_addr.s_addr=inet_addr("127.0.0.1");
	
	//blind to the set port and ip
	if(bind(socket_desc,(struct sockaddr*)&server_addr,sizeof(server_addr))<0){
	printf("couldn't bind to the prt \n");
	return -1;
	}
	printf("done with blinding \n");
	printf("listening for incoming message ....\n\n");
	
	
	
	
	
	
	 if (recvfrom(socket_desc, client_message, sizeof(client_message), 0,
         (struct sockaddr*)&client_addr, &client_struct_length) < 0){
        printf("Couldn't receive\n");
        return -1;
    }
    printf("Received message from IP: %s and port: %i\n",
           inet_ntoa(client_addr.sin_addr), ntohs(client_addr.sin_port));
    
    printf("Msg from client: %s\n", client_message);
    
    // Change to uppercase:
    for(int i = 0; client_message[i]; ++i)
        client_message[i] = toupper(client_message[i]);
    
    // Respond to client:
    strcpy(server_message, client_message);
    
    if (sendto(socket_desc, server_message, strlen(server_message), 0,
         (struct sockaddr*)&client_addr, client_struct_length) < 0){
        printf("Can't send\n");
        return -1;
    }
    
    // Close the socket:
    close(socket_desc);

}
	
	
	
	
	
	
