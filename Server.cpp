//Server.cpp代码（通信模块）：
//服务端地址 ip地址 + 端口号
struct sockaddr_in serverAddr;
serverAddr.sin_family = PF_INET;
serverAddr.sin_port = htons(SERVER_PORT);
serverAddr.sin_addr.s_addr = inet_addr(SERVER_HOST);

//服务端创建监听socket
int listener = socket(PF_INET, SOCK_STREAM, 0);
if(listener < 0) { perror("listener"); exit(-1);}
printf("listen socket created \n");

//将服务端地址与监听socket绑定
if( bind(listener, (struct sockaddr *)&serverAddr, sizeof(serverAddr)) < 0) {
    perror("bind error");
    exit(-1);
}
//开始监听
int ret = listen(listener, 5);
if(ret < 0) { perror("listen error"); exit(-1);}
printf("Start to listen: %s\n", SERVER_HOST);