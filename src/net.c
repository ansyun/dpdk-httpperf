// Copyright (C) 2013 - Will Glozer.  All rights reserved.

#include <errno.h>
#include <unistd.h>
#include <sys/ioctl.h>

#include "net.h"

status sock_connect(connection *c, char *host) {
    return OK;
}

status sock_close(connection *c) {
    return OK;
}

status sock_read(connection *c, size_t *n) {

    ssize_t r = read(c->fd, c->buf, sizeof(c->buf));
    if (r == -1) {
        switch (errno) {
            case EAGAIN: return RETRY;
            default:     return ERROR;
        }
    }
    else if(r == 0)
    {
        return ERROR;
    }
    
    *n = (size_t) r;
    return OK;
    
}

status sock_write(connection *c, char *buf, size_t len, size_t *n) {
    ssize_t r;
    if ((r = write(c->fd, buf, len)) == -1) {
        switch (errno) {
            case EAGAIN: return RETRY;
            default:     return ERROR;
        }
    }
    *n = (size_t) r;
    return OK;
}

size_t sock_readable(connection *c) {
    int n, rc;
    rc = ioctl(c->fd, FIONREAD, &n);
    return rc == -1 ? 0 : n;
}
