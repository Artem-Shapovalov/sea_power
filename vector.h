#ifndef VECTOR_H
#define VECTOR_H

#ifdef __cplusplus
extern "C" {
#endif

#include <stddef.h>

/** \brief Creates the vector container.
 *  \param item_size Size of the particular item in the container.
 *  \return Pointer to the container object.
 *  \retval NULL Unable to create the object */
void* sp_vector_create(size_t item_size);

/** \brief Destroys the vector container.
 *  \param vector Pointer to the vector object.
 *  \return Result.
 *  \retval 1 Container successfully destroyed.
 *  \retval 0 Unable to destroy requested container. */
int sp_vector_delete(void* vector);

/** \brief Current size of the requested vector.
 *  \param vector Pointer to the vector object.
 *  \return Number of the items currently held in vector */
size_t sp_vector_size(void* vector);

/** \brief Reads the item at position to the buffer.
 *  \param vector Pointer to the vector object.
 *  \param buffer Pointer to the buffer to read from.
 *  \param position Number of the item inside the container.
 *  \return Result.
 *  \retval 1 The data is readen to the buffer.
 *  \retval 0 Unable to read requested data. */
int sp_vector_fetch(void* vector, void* buffer, size_t position);

/** \brief Writes the item at position to the container.
 *  \param vector Pointer to the vector object.
 *  \param buffer Pointer to the buffer to write from.
 *  \return Result.
 *  \retval 1 The data is written to the container.
 *  \retval 0 Unable to write requested data. */
int sp_vector_write(void* vector, void* buffer, size_t position);

/** \brief Creates the new item at the back of the vector.
 *  \param vector Pointer to the vector object.
 *  \param buffer Pointer to the buffer to init new item.
 *  \return Result.
 *  \retval 1 The item is created at the vector.
 *  \retval 0 Unable to create the new item. */
int sp_vector_push_back(void* vector, void* buffer);

/** \brief Destroys the last item of the vector.
 *  \param vector Pointer to the vector object.
 *  \param buffer Pointer to the buffer to save the item.
 *  \return Result.
 *  \retval 1 The item is extracted from the vector.
 *  \retval 0 Unable to extract the item. */
int sp_vector_pop_back(void* vector, void* buffer);

/** \brief Creates the new item at the front of the vector.
 *  \param vector Pointer to the vector object.
 *  \param buffer Pointer to the buffer to init new item.
 *  \return Result.
 *  \retval 1 The item is created at the vector.
 *  \retval 0 Unable ot create the new item. */
int sp_vector_push_front(void* vector, void* buffer);

/** \brief Destroys the first item of the vector.
 *  \param vector Pointer to the vector object.
 *  \param buffer Pointer to the bufer to save the item.
 *  \return Result.
 *  \retval 1 The item is extracted from the vector.
 *  \retval 0 Unable to extract the item. */
int sp_vector_pop_front(void* vector, void* buffer);

#ifdef __cplusplus
}
#endif

#endif
