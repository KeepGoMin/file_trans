#ifndef __SOCKET_H__
#define __SOCKET_H__
#include <string>
#include <mutex>
class Socket {
public:
    explicit Socket(int protocol);
    virtual ~Socket();
    int getLocalPort();
    int getRemotePort();
    bool bind(std::string &ip, int port);
    bool listen(int maxConnection=MAX_CONN_NUM);
    Socket& accept();
    bool connect(std::string &ip, int port);
    bool connect(Socket &s);
    bool write(std::string &buf);
    bool write(char *buf, int len);
    bool read(std::string &buf);
    bool read(char *buf, int *len);
    bool close();
private:
    static int MAX_CONN_NUM;
    int socket_fd;
    int domain;
    int protocol;
};
int Socket::MAX_CONN_NUM = 5;
#endif