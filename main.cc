#include "NET/TCPSocket.hh"
int
main (void)
{
  NET::TCPSocket my_socket;
  my_socket.listen_on(0, 9000);
  
  return 0;
}
