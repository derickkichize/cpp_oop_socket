#include <iostream>
#include <cstdlib>
#include <cerrno>
#include <arpa/inet.h>
#include <SocketBind.hh>

namespace NET {
  SocketBind::SocketBind (int af_type, uint16_t port, const char* addr)
    :family      (af_type),
     listen_port (port),
     address     (addr),
     saddr ({}), saddr6 ({}) {}

  void
  SocketBind::configure_addr (void)
  {
    saddr.sin_family      = family;
    saddr.sin_port        = htons(listen_port);
    saddr.sin_addr.s_addr = inet_addr(address);
  }

  void
  SocketBind::configure_addrv6 (void)
  { 
    saddr6.sin6_family = family;
    saddr6.sin6_port   = htons(listen_port);

    if (inet_pton(family, address, &(saddr6.sin6_addr)) <= 0)
      {
	std::cerr << "Bad address to ipv6" << std::endl;
	std::exit (EXIT_FAILURE);
      }
  }

  void
  SocketBind::bind_socket (int socket_descriptor)
  {
    if (family == AF_INET)
      {
	__configure_addr();
	return (bind (socket_descriptor, (sockaddr*)&saddr,
		      sizeof (saddr)) == -1) ?
	  EXIT_FAILURE : socket_descriptor;
      }
    else
      {
	__configure_addrv6();
	return (bind (socket_descriptor, (sockaddr*)&saddr6,
		      sizeof (saddr6)) == -1) ?
	  EXIT_FAILURE : socket_descriptor;
      }
  }
}
