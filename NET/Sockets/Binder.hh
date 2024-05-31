#pragma once
#include <iostream>
#include <string>
#include <sys/socket.h>

namespace NET {
  namespace Sockets {
    class Binder {
    private:  
      int          family;
      uint16_t     listen_port;
    
      std::string  address;

      sockaddr_in  saddr;
      sockaddr_in6 saddr6;
    
      void __configure_addrv6  (void);
      void __configure_addr    (void);
    public:
      Binder (int af_type, uint16_t port, std::string listen_target);
      int bind_socket (int socket_descriptor);
    };
  }
}
