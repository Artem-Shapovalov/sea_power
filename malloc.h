#ifndef MALLOC_H
#define MALLOC_H

#ifdef __cplusplus
extern "C" {
#endif

#include <stddef.h>

void sp_malloc_init(void* buf, size_t size);
size_t sp_malloc_space();
void* sp_malloc(size_t size);
void sp_free(void* ptr);
void sp_cpy(void* from, void* to, size_t num);

#ifdef __cplusplus
}
#endif

#endif
