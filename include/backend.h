/* See LICENSE in the main directory for copyright. */
#ifndef __BACKEND_H__
#define __BACKEND_H__
/*---------------------------------------------------------------------*/
/* pktengine def'n */
#include "pkt_engine.h"
/*---------------------------------------------------------------------*/
/**
 *
 * NETWORK BACKEND OF BRICKS
 *
 * This module handles the network communications of the system.
 * meaning... it handles NIC I/O as well as apps I/O
 *
 */
/*---------------------------------------------------------------------*/
/**
 * MACROS
 */
/* Sets the limit on how many processes each engine can handle */
/* __linux__ */
#define EPOLL_MAX_EVENTS		FD_SETSIZE
/* __FreeBSD__ */
#define KQUEUE_MAX_EVENTS		EPOLL_MAX_EVENTS
/* epoll timeout = 500ms */
#define EPOLL_TIMEOUT			500
/* passive sock port */
#define PKTENGINE_LISTEN_PORT		1234
/* listen queue length */
#define LISTEN_BACKLOG			10
/*---------------------------------------------------------------------*/
/**
 * Creates listening socket to serve as a conduit between userland
 * applications and the system. Starts listening on all sockets 
 * thereafter.
 */
void
initiate_backend(engine *eng);

/**
 * Connects to a bricks server for remote shell commands
 * rshell_args contains either NULL (use default) or
 * string "ipaddr:port"
 */
int
connect_to_bricks_server(char *rshell_args);
/*---------------------------------------------------------------------*/
#endif /* __BACKEND_H__ */
