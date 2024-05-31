#include "TCPSocket.hh"
#include "Domain.hh"
#include "Type.hh"
#include "Protocol.hh"

namespace NET {
  TCPSocket::TCPSocket()
    : Socket (NET::Domain::INET, NET::Type::STREAM, NET::Proto::TCP) {}
  
  void
  TCPSocket::listen_on (int backlog, int listen_port)
  {
    Socket::listen_on(backlog, listen_port);
  }
}
