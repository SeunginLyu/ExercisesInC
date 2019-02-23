#include <signal.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <sys/time.h>
#include <time.h>
#include <netinet/in.h>
#include <netinet/in_systm.h>
#include <netinet/ip.h>
#include <netinet/ip_icmp.h>
#include <netinet/udp.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <errno.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <getopt.h>
#include <sys/un.h>
#include <stdarg.h>
#include <syslog.h>
#include <strings.h>

#define BUFSIZE 1500

typedef struct rec {                /* outgoing UDP data */
  u_short seq;          /* sequence number */
} Rec;
typedef struct timeval Timeval;
typedef struct sockaddr Sockaddr;

#define max(a,b) ((a) > (b) ? (a) : (b))

// for trout.c
int Signal();
void loop_ttl ();
void send_dgram (int ttl);
void Write(int fd, void *ptr, size_t nbytes);
void Gettimeofday(struct timeval *tv, void *foo);
void Pipe(int *fds);
void Bind(int fd, const struct sockaddr *sa, socklen_t salen);
void Setsockopt(int fd, int level, int optname, const void *optval,
		socklen_t optlen);
struct addrinfo *Host_serv(const char *host, const char *serv,
			   int family, int socktype);
ssize_t Read(int fd, void *ptr, size_t nbytes);
void err_sys (char *fmt, ...);
void err_quit (char *fmt, ...);
char *Sock_ntop_host(const struct sockaddr *sa, socklen_t salen);
void sock_set_port(struct sockaddr *sa, socklen_t salen, int port);
int sock_cmp_addr(const struct sockaddr *sa1,
		  const struct sockaddr *sa2, socklen_t salen);

// for main.c
char recvbuf[BUFSIZE];
char sendbuf[BUFSIZE];
Rec *rec;
int sendfd, recvfd;
int pipefd[2];
Sockaddr *sasend;    /* socket addresses for various purposes */
Sockaddr *sarecv;
Sockaddr *salast;
Sockaddr *sabind;
socklen_t salen;                    /* length of a socket address */
u_short sport;                      /* source UDP port # */
u_short dport;
Timeval sendtv[1];
Timeval recvtv[1];
Timeval difftv[1];
int max_ttl;
int nprobes;
int seq;
int datalen;
void *Calloc(size_t n, size_t size);