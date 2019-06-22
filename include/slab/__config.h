//
// Created by egl on 6/22/19.
//

#ifndef WORKBENCH___CONFIG_H
#define WORKBENCH___CONFIG_H
#include "__error.h"
#define _SLAB_ERROR(...) apue::err_quit(__VA_ARGS__)
#define _SLAB_WARNING(...) apue::err_msg(__VA_ARGS__)
#endif //WORKBENCH___CONFIG_H

#define SLAB_INT int
#define SLAB_UINT unsigned int

#define _SLAB_ASSERT(x, m)                                            \
  ((x) ? (void)0                                                      \
       : _SLAB_ERROR("%s:%d: _SLAB_ASSERT '%s' failed. %s", __FILE__, \
                     __LINE__, #x, m))

