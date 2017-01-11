# Socket Notes 
## 1. 引子
- 我们深谙信息交流的价值，那网络中进程之间如何通信，如我们每天打开浏览器浏览网页时，浏览器的进程怎么与web服务器通信的？当你用QQ聊天时，QQ进程  怎么与服务器或你好友所在的QQ进程通信？这些都得靠socket？那什么是socket？socket的类型有哪些？还有socket的基本函数，这些都是本文想介绍的。
- `“一切皆Socket！”` 话虽些许夸张，但是事实也是，现在的网络编程几乎都是用的socket。
## 2. 网络中进程之间如何通信？
- 本地的进程间通信（IPC）有很多种方式，但可以总结为下面4类：
  - 消息传递（管道、FIFO、消息队列）
  - 同步（互斥量、条件变量、读写锁、文件和写记录锁、信号量）
  - 共享内存（匿名的和具名的）
  - 远程过程调用（Solaris门和Sun RPC）
- 但这些都不是本文的主题！我们要讨论的是网络中进程之间如何通信？首要解决的问题是如何唯一标识一个进程，否则通信无从谈起！在本地可以通过进程PID来唯一标识一个进程，但是在网络中这是行不通的。
- 其实TCP/IP协议族已经帮我们解决了这个问题，网络层的`ip地址`可以唯一标识网络中的主机，而传输层的`协议+端口`可以唯一标识主机中的应用程序（进程）。这样利用三元组（`ip地址，协议，端口`）就可以标识网络的进程了，网络中的进程通信就可以利用这个标志与其它进程进行交互。
- 使用TCP/IP协议的应用程序通常采用应用编程接口：UNIX  BSD的套接字（socket）和UNIX System V的TLI（已经被淘汰），来实现网络进程之间的通信。就目前而言，几乎所有的应用程序都是采用socket，而现在又是网络时代，网络中进程通信是无处不在，这就是我为什么说`“一切皆socket”`
## 3. 什么是Socket？[socket man page](http://man7.org/linux/man-pages/man7/socket.7.html)
- 上面我们已经知道网络中的进程是通过socket来通信的，那什么是socket呢？socket起源于Unix，而Unix/Linux基本哲学之一就是`“一切皆文件”`，都可以用“打开open –> 读写write/read –> 关闭close”模式来操作。我的理解就是Socket就是该模式的一个实现，socket即是一种特殊的文件，一些socket函数就是对其进行的操作（读/写IO、打开、关闭），这些函数我们在后面进行介绍。
## 4. socket的基本操作 
- socket()函数   
`sockfd = socket(int domain, int socket_type, int protocol);`
- domain
```
creates an endpoint for communication and returns a file descriptor that refers to that endpoint.
The domain argument specifies a communication domain; this selects the protocol family which will be used for communication.
These families are defined in <sys/socket.h>.  The currently understood formats include:

创建一个用于通信的端点  返回一个指向该端点的文件描述符
domain参数指定一个通信用的协议域（domain 协议域，又称为协议族（family）） 
这些参数定义在<sys/socket.h> 目前有一下这些常用格式：

AF_UNIX, AF_LOCAL   Local communication        用于本地通信
AF_INET             IPv4 Internet protocols    用于IPv4网络通信
AF_INET6            IPv6 Internet protocols    用于IPv6网络通信
```
- socket_type
```
The socket has the indicated type, which specifies the communication semantics.  Currently defined types are:

socket需要指定用于通信的类型  目前有这些常用定义：

SOCK_STREAM
Provides sequenced, reliable, two-way, connection-based byte streams.  An out-of-band data transmission mechanism may be supported.
提供序列、可靠、双向、连接—基于字节流。带外数据传输机制。

SOCK_DGRAM
Supports datagrams (connectionless, unreliable messages of a fixed maximum length).
支持数据报文（无连接的、不可靠、一个固定的最大长度的消息）

SOCK_SEQPACKET
Provides a sequenced, reliable, two-way connection-based data transmission path for datagrams of fixed maximum length; a consumer is required to read an entire packet with each input system call.
提供顺序、可靠、双向连接—基于数据报的固定数据传输路径最大长度；消费者需要读取每个输入系统调用的整个数据包。
```
- protocol
```
The protocol specifies a particular protocol to be used with the
socket.  Normally only a single protocol exists to support a
particular socket type within a given protocol family, in which case
protocol can be specified as 0.  However, it is possible that many
protocols may exist, in which case a particular protocol must be
specified in this manner.  The protocol number to use is specific to
the “communication domain” in which communication is to take place;
如果socket 只有一个对应的 protocol 则该参数可为0 
不然必须指定一个 socket对应的protocol
```
- sockfd
```
 On success, a file descriptor for the new socket is returned.  On error, -1 is returned, and errno is set appropriately.
 成功返回描述符  失败返回-1
```

- bind()函数  
`int bind(int sockfd, const struct sockaddr *addr, socklen_t addrlen);`





官方文档http://man7.org/linux/man-pages/man7/socket.7.html 