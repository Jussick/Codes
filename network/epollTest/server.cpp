#include "utility.h"
 
int main(int argc, char *argv[])
{
    //服务器IP + port
    struct sockaddr_in serverAddr;
    serverAddr.sin_family = PF_INET;
    serverAddr.sin_port = htons(SERVER_PORT);
    serverAddr.sin_addr.s_addr = inet_addr(SERVER_IP);
    //创建监听socket
    int listener = Socket(PF_INET, SOCK_STREAM, 0);
    printf("listen socket created \n");

    int opt = 1;
    setsockopt(listener, SOL_SOCKET, SO_REUSEADDR, &opt, sizeof(opt));

    //绑定地址
    Bind(listener, (struct sockaddr *)&serverAddr, sizeof(serverAddr));
    //设置监听模式
    Listen(listener, 5);

    printf("Start to listen: %s:%d\n", SERVER_IP, SERVER_PORT);

    //在内核中创建事件表
    int epfd = Epoll_create(EPOLL_SIZE);
    printf("epoll created, epollfd = %d\n", epfd);

    static struct epoll_event events[EPOLL_SIZE];

    //往内核事件表里添加事件
    addfd(epfd, listener, true);

    //主循环
    while(1)
    {
        //epoll_events_count表示就绪事件的数目
        int epoll_events_count = Epoll_wait(epfd, events, EPOLL_SIZE, -1);
 
         printf("epoll_events_count = %d\n", epoll_events_count);
        //处理这epoll_events_count个就绪事件 
        for(int i = 0; i < epoll_events_count; ++i) {
            int sockfd = events[i].data.fd;
            //新用户连接
            if(sockfd == listener)
            {
                struct sockaddr_in client_address;
                socklen_t client_addrLength = sizeof(struct sockaddr_in);
                int clientfd = Accept( listener, ( struct sockaddr* )&client_address, &client_addrLength );
 
                printf("client connection from: %s : % d(IP : port), clientfd = %d \n",
                    inet_ntoa(client_address.sin_addr), ntohs(client_address.sin_port), clientfd);
 
                addfd(epfd, clientfd, true);
                // 服务端用list保存用户连接
                clients_list.push_back(clientfd);
                printf("Add new clientfd = %d to epoll\n", clientfd);
                printf("Now there are %d clients int the chat room\n", (int)clients_list.size());
 
                // 服务端发送欢迎信息  
                printf("welcome message\n");                
                char message[BUF_SIZE];
                bzero(message, BUF_SIZE);
                sprintf(message, SERVER_WELCOME, clientfd);
                Send(clientfd, message, BUF_SIZE, 0);
            }
            //处理用户发来的消息，并广播，使其他用户收到信息
            else 
            {   
                sendBroadcastmessage(sockfd);
            }
        }//for
    }//while
    close(listener); //关闭socket
    close(epfd);    //关闭内核
    return 0;
}
