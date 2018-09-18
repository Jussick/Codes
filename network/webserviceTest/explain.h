#include <sys/types.h>
#include <sys/socket.h>

/**
获取一个socket descriptor
@params:
    domain: 此处固定使用AF_INET
    type: 此处固定使用SOCK_STREAM
    protocol: 此处固定使用0
@returns:
    nonnegative descriptor if OK, -1 on error.
*/
int socket(int domain, int type, int protocol);

/**
客户端socket向服务器发起连接
@params:
    sockfd: 发起连接的socket descriptor
    serv_addr: 连接的目标地址和端口
    addrlen: sizeof(*serv_addr)
@returns:
    0 if OK, -1 on error
*/
int connect(int sockfd, struct sockaddr *serv_addr, int addrlen);

/**
服务器socket绑定地址和端口
@params:
    sockfd: 当前socket descriptor
    my_addr: 指定绑定的本机地址和端口
    addrlen: sizeof(*my_addr)
@returns:
    0 if OK, -1 on error
*/
int bind(int sockfd, struct sockaddr *my_addr, int addrlen);

/**
将当前socket转变为可以监听外部连接请求的socket
@params:
    sockfd: 当前socket descriptor
    backlog: 请求队列的最大长度
@returns:
    0 if OK, -1 on error
*/
int listen(int sockfd, int backlog);

/**
等待客户端请求到达，注意，成功返回得到的是一个新的socket descriptor，
而不是输入参数listenfd。
@params:
    listenfd: 当前正在用于监听的socket descriptor
    addr: 客户端请求地址（输出参数, 不关心可以传NULL）
    addrlen: 客户端请求地址的长度（输出参数, 不关心可以传NULL）
@returns:
    成功则返回一个非负的connected descriptor，出错则返回-1
*/
int accept(int listenfd, struct sockaddr *addr, int *addrlen);

