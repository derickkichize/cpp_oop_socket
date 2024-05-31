#pragma once
#include <netinet/in.h>
#include <sys/socket.h>
#include "SocketContract.hh"
#include "SocketBind.hh"
#include "SocketListen.hh"

namespace NET {
  class Socket:
    public SocketContract,
    public SocketBind,
    public SocketListen
  {
  private:
    int socket_descriptor;
    int socket_domain;
    int socket_type;
    int socket_protocol;
    
    int  create (void);
  public:
    void startListen (void);
    Socket  (int domain, int type, int protocol);
    ~Socket (void) override;
  };
}
