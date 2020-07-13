//Client.cpp代码（通信模块）：
//客户要连接的服务端地址（ ip地址 + 端口号）
struct sockaddr_in serverAddr;
serverAddr.sin_family = PF_INET;
serverAddr.sin_port = htons(SERVER_PORT);
serverAddr.sin_addr.s_addr = inet_addr(SERVER_IP);

// 创建套接字（socket）
int sock = socket(PF_INET, SOCK_STREAM, 0);
if(sock < 0) { perror("sock error"); exit(-1); }
//向服务器发出连接请求（connect）
if(connect(sock, (struct sockaddr *)&serverAddr, sizeof(serverAddr)) < 0) {
    perror("connect error");
    exit(-1);
}