#include <stdio.h>
#include <strings.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <netdb.h>

int main() {
    int clientsocket, port;
    struct sockaddr_in serveraddr;
    socklen_t len;
    int a, b, sum = 0;

    clientsocket = socket(AF_INET, SOCK_STREAM, 0);
    bzero((char*)&serveraddr, sizeof(serveraddr));
    len = sizeof(serveraddr);

    serveraddr.sin_family = AF_INET;

    printf("Enter the port number: ");
    scanf("%d", &port);
    serveraddr.sin_port = htons(port);

    printf("\nTrying to connect to the server\n");
    connect(clientsocket, (struct sockaddr*)&serveraddr, sizeof(serveraddr));
    printf("\nConnected to the server\n");

    printf("Enter two numbers for addition\n");
    scanf("%d%d", &a, &b);

    send(clientsocket, &a, sizeof(a), 0);
    send(clientsocket, &b, sizeof(b), 0);

    printf("\nReceiving sum from server\n");
    recv(clientsocket, &sum, sizeof(sum), 0);
    printf("\nSum received: %d\n", sum);

    close(clientsocket);

    return 0;
}
