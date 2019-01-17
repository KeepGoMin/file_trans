#include "socket.hpp"

#include <sys/types.h>
#include <unistd.h>
#include <linux/types.h>
#include <netinet/in.h>
#include <sys/socket.h>
#include <arpa/inet.h>

#include <iostream>
#include <string.h>

Socket::Socket(int _protocol) : protocol(_protocol)
{
    socket_fd = -1;
}
Socket::~Socket()
{
}

int Socket::getLocalPort()
{
    if (socket_fd > 0)
    {
        struct sockaddr_in addr;
        socklen_t len = 0;
        int ret = getpeername(socket_fd, (struct sockaddr *)&addr, &len);
        if (ret != 0)
        {
            std::cout << __func__ << "error:" << strerror(errno) << std::endl;
            return -1;
        }
        return addr.sin_port;
    }
    return -1;
}

int Socket::getRemotePort()
{
    if (socket_fd > 0)
    {
        struct sockaddr_in addr;
        socklen_t len = 0;
        int ret = getsockname(socket_fd, (struct sockaddr *)&addr, &len);
        if (ret != 0)
        {
            std::cout << __func__ << "error:" << strerror(errno) << std::endl;
            return -1;
        }
        return addr.sin_port;
    }
    return -1;
}

bool Socket::bind(std::string &ip, int port)
{
    if (socket_fd > 0)
    {
        struct sockaddr_in addr;
        socklen_t len = 0;
        int ret;
        addr.sin_family = domain;
        addr.sin_port = (int16_t)port;
        ret = inet_aton(ip.c_str(), &(addr.sin_addr));
        if (ret == 0)
        {
            std::cout << __func__ << "get ip address error:" << strerror(errno) << std::endl;
            return false;
        }
        int ret = bind(socket_fd, (struct sockaddr *)&addr, len);
        if (ret != 0)
        {
            std::cout << __func__ << "bind error:" << strerror(errno) << std::endl;
            return false;
        }
        return true;
    }
    return false;
}

bool Socket::listen(int maxConnection)
{
    if (socket_fd > 0)
    {
        int ret = listen(socket_fd, maxConnection);
        if (ret != 0)
        {
            std::cout << __func__ << "error:" << strerror(errno) << std::endl;
            return false;
        }
        return true;
    }
    return false;
}
Socket &Socket::accept()
{
    Socket *s = nullptr;
    int sfd = accept
}
bool Socket::connect(std::string &ip, int port)
{
    return false;
}
bool Socket::connect(Socket &s)
{
    return false;
}
bool Socket::write(std::string &buf)
{
    return false;
}
bool Socket::write(char *buf, int len)
{
    return false;
}
bool Socket::read(std::string &buf)
{
    return false;
}
bool Socket::read(char *buf, int *len)
{
    return false;
}
bool Socket::close()
{
    return false;
}