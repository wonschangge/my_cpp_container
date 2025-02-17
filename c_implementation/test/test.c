#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <netdb.h>

#define SERVER_NAME "yros.fun"
#define SERVER_PORT 80

int main() {
    int ret, len, server_fd;
    unsigned char buf[1024];
    struct sockaddr_in server_addr;
    struct hostent *server_host;

    // 启动连接
    printf("\n . Connecting to tcp/%s/%4d...", SERVER_NAME, SERVER_PORT);
    fflush(stdout);

    // 获取服务器的IP地址
    if ((server_host = gethostbyname(SERVER_NAME)) == NULL) {
        printf(" failed\n ! gethostbyname failed\n\n");
        return EXIT_FAILURE;
    }

    // 创建一个TCP套接字
    if ((server_fd = socket(AF_INET, SOCK_STREAM, IPPROTO_IP)) < 0) {
        printf(" failed\n ! socket returned %d\n\n", server_fd);
        return EXIT_FAILURE;
    }

    // 设置服务器地址结构体
    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(SERVER_PORT);
    memcpy(&server_addr.sin_addr, server_host->h_addr, server_host->h_length);

    // 连接到服务器
    if (connect(server_fd, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        printf(" failed\n ! connect failed\n\n");
        close(server_fd);
        return EXIT_FAILURE;
    }

    printf(" connected\n");

    // 发送HTTP GET请求
    const char *request = "GET / HTTP/1.1\r\nHost: yros.fun\r\nConnection: close\r\n\r\n";
    if (send(server_fd, request, strlen(request), 0) < 0) {
        printf(" failed\n ! send failed\n\n");
        close(server_fd);
        return EXIT_FAILURE;
    }

    printf(" request sent\n");

    // 读取服务器响应
    while ((len = recv(server_fd, buf, sizeof(buf) - 1, 0)) > 0) {
        buf[len] = '\0';
        printf("%s", buf);
    }

    if (len < 0) {
        printf(" failed\n ! recv failed\n\n");
    } else {
        printf(" response received\n");
    }

    // 关闭套接字
    close(server_fd);
    return EXIT_SUCCESS;
}