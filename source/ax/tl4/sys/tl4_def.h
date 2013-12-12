/* This file protected by faith_base_00 license
 * No part of this file could be copyed or changed without Develop Project agreement
 * No part of this file could be used or viewed without Develop Project agreement
 */

#ifndef _TL4_DEF_H_
#define _TL4_DEF_H_

#ifdef DEPRECATED_ERRORS_IGNORE
#undef DEPRECATED_ERRORS_IGNORE
#endif
#define DEPRECATED_ERRORS_IGNORE 1

#ifndef _IAM_UNDER_BILL_GATES
#include "../tl4.h"

#include "../../structs/local_db.h"

#ifndef _TL4_DEBUG
#define _TL4_DEBUG _DEBUG_
#endif

#ifndef _TL4_MAX_CONNECTIONS
#define _TL4_MAX_CONNECTIONS 1000
#endif

#ifndef _TL4_CONNECTION_TIMEOUT
#define _TL4_CONNECTION_TIMEOUT 5000
#endif

#ifndef _TL4_PORT_OPEN_ATTEMPTS
#define _TL4_PORT_OPEN_ATTEMPTS 10
#endif

#ifndef _TL4_DATA_SEGMENT_SIZE
#define _TL4_DATA_SEGMENT_SIZE 1460
#else
#error Maximum size of TCP data segmend (_TL4_DATA_SEGMENT_SIZE) is 1500(default value)
#endif

#ifndef _TL4_RECIEVE_CYCLES
#define _TL4_RECIEVE_CYCLES 100
#endif

#ifndef _TL4_SENDING_CYCLES
#define _TL4_SENDING_CYCLES 100
#endif

#ifndef _TL4_MAX_SEND_BUFFER
#define _TL4_MAX_SEND_BUFFER (32<<10)
#endif

#define _TL4_NOT_SOCKET_ (~0)
#define _TL4_NOT_IP_     (~0)
#define _TL4_NOT_PORT_     0

#endif

#endif