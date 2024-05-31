#pragma once
#include <sys/socket.h>

namespace NET {
  class SocketBind {
  private:
    sockaddr_in  saddr;
    sockaddr_in6 saddr6;
    
    int          family;
    uint16_t     listen_port;
    std::string  address;
    
    void __configure_addrv6  (void);
    void __configure_addr    (void);
  public:
    SocketBind (int af_type, uint16_t port, const char* addr);
    void bind_socket (int socket_descriptor);
}
