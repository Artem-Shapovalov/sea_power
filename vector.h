#ifndef VECTOR_H
#define VECTOR_H

#ifdef __cplusplus
extern "C" {
#endif

#include <stddef.h>

void* sp_vector_create(size_t item_size);
size_t sp_vector_size(void* vector);
int sp_vector_fetch(void* vector, void* buffer, size_t position);
int sp_vector_write(void* vector, void* buffer, size_t position);
int sp_vector_push_back(void* vector, void* buffer);
int sp_vector_pop_back(void* vector, void* buffer);
int sp_vector_push_front(void* vector, void* buffer);
int sp_vector_pop_front(void* vector, void* buffer);

#ifdef __cplusplus
}
#endif

#endif
