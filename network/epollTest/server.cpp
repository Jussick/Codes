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
 
        