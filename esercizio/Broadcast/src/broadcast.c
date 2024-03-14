#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct Node
{
    int data;
    int sequence_number;
    int is_leader;
}Node;

int generate_random_number(){
    return rand() & 100;
}

void broadcast_data(Node *node){
    if (node == NULL || message == NULL) {
        printf("Node or message is null.\n");
        return;
    }

    int broadcast = 1;
    if (setsockopt(node->socket, SOL_SOCKET, SO_BROADCAST, &broadcast, sizeof broadcast) == -1) {
        perror("setsockopt (SO_BROADCAST)");
        exit(EXIT_FAILURE);
    }

    struct sockaddr_in broadcastAddr;
    memset(&broadcastAddr, 0, sizeof broadcastAddr);
    broadcastAddr.sin_family = AF_INET;
    broadcastAddr.sin_addr.s_addr = inet_addr("255.255.255.255");
    broadcastAddr.sin_port = node->address.sin_port;

    if (sendto(node->socket, message, strlen(message), 0, (struct sockaddr*)&broadcastAddr, sizeof broadcastAddr) == -1) {
        perror("sendto");
        exit(EXIT_FAILURE);
    }
}

void handle_recive_data (Node *node, int data, int sequence_number){
    if (node->sequence_number >= sequence_number){
        return;
    }

    node->data= data;
    node->sequence_number = sequence_number;

    printf("%d\n", data);

}

void start_node (Node *node){
    if (node->is_leader){
        sleep(1);

        int data = generate_random_number();
        node->data = data;
        node->sequence_number++;

        printf("%d\n", data);

        broadcast_data(node);
    }
}