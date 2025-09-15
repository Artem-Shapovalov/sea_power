#ifndef ALGORITHM_H
#define ALGORITHM_H

#include <stddef.h>

/** \brief Creates the iterator for any container.
 *  \param container Pointer to the container.
 *  \return Pointer to the iterator.
 *  \retval NULL Unable to create iterator */
void* sp_iterator_create(void* container);

/** \brief Destroys the iterator.
 *  \param iterator Pointer to the iterator.
 *  \return Result.
 *  \retval 1 Iterator is destroyed.
 *  \retval 0 Unable to delete iterator. */
int sp_iterator_destroy(void* iterator);

/** \brief Switches the iterator to next item.
 *  \param itertor Pointer to the iterator.
 *  \return Result.
 *  \retval 1 Iterator is switched to the next value.
 *  \retval 0 Unable to switch iterator. */
int sp_iterator_next(void* iterator);

/** \brief Switches iterator to previous item.
 *  \param iterator Pointer to the iterator.
 *  \return Result.
 *  \retval 1 Iterator is switched to the previous value.
 *  \retval 0 Unable to switch iterator. */
int sp_iterator_prev(void* iterator);

/** \brief Reads the current value to the buffer.
 *  \param iterator Pointer to the iterator.
 *  \param buffer Data buffer to read
 *  \return Result.
 *  \retval 1 Value successfully extracted.
 *  \retval 0 Unable to extract the value. */
int sp_iterator_fetch(void* iterator, void* buffer);

/** \brief Writes the value to the container.
 *  \param iterator Pointer to the iterator.
 *  \param buffer Pointer to the value to write.
 *  \return Result.
 *  \retval 1 Value successfully written.
 *  \retval 0 Unable to write the value. */
int sp_iterator_write(void* iterator, void* buffer);

/** \brief Deletes the current item from the container.
 *  \param iterator Pointer to the iterator.
 *  \return Result.
 *  \retval 1 The item is erased.
 *  \retval 0 Unable to erase item. */
int sp_iterator_erase(void* iterator);

/** \brief Inserts the new item into container at the current iterator position.
 *  \param iterator Pointer to the iterator.
 *  \param buffer Pointer to the value to init the new item.
 *  \return Result.
 *  \retval 1 The item is inserted.
 *  \retval 0 Unable to insert item. */
int sp_iterator_insert(void* iterator, void* buffer);

/** \brief Sort the container.
 *  \param container Pointer to the container.
 *  \param comparer Pointer to the comparer function.
 *  \return Result.
 *  \retval 1 The container is sorted.
 *  \retval 0 Unable to sort container. */
int sp_container_sort(void* container, int (*comparer)(void* v1, void* v2));

/** \brief Search the item in the container.
 *  \poram container Pointer to the container.
 *  \param comparer Pointer to the comparer function.
 *  \param buffer Pointer to the value needed to find.
 *  \return Pointer to the iterator, that refers to the first found value.
 *  \retval NULL Unable to find requested item. */
void* sp_container_search(void* container,
		int (*comparer)(void* v1, void* v2), void* buffer);

/** \brief Counts how much items with requested value container held.
 *  \param container Pointer to the container.
 *  \param comparer Pointer to the comparer function.
 *  \param buffer Pointer to the value needed to find.
 *  \return Numbers of items found */
size_t sp_container_count(void* container,
		int (*comparer)(void* v1, void* v2), void* buffer);

/** \brief Compares two char.
 *  \param v1 Pointer to the first value.
 *  \param v2 Pointer to the second value.
 *  \return Result.
 *  \retval 1 v1 > v2
 *  \retval 0 v1 == v2
 *  \retval -1 v1 < v2 */
int sp_compare_char(void* v1, void* v2);

/** \brief Compares two unsigned char.
 *  \param v1 Pointer to the first value.
 *  \param v2 Pointer to the second value.
 *  \return Result.
 *  \retval 1 v1 > v2
 *  \retval 0 v1 == v2
 *  \retval -1 v1 < v2 */
int sp_compare_unsigned_char(void* v1, void* v2);

/** \brief Compares two short.
 *  \param v1 Pointer to the first value.
 *  \param v2 Pointer to the second value.
 *  \return Result.
 *  \retval 1 v1 > v2
 *  \retval 0 v1 == v2
 *  \retval -1 v1 < v2 */
int sp_compare_short(void* v1, void* v2);

/** \brief Compares two unsigned short.
 *  \param v1 Pointer to the first value.
 *  \param v2 Pointer to the second value.
 *  \return Result.
 *  \retval 1 v1 > v2
 *  \retval 0 v1 == v2
 *  \retval -1 v1 < v2 */
int sp_compare_unsigned_short(void* v1, void* v2);

/** \brief Compares two int.
 *  \param v1 Pointer to the first value.
 *  \param v2 Pointer to the second value.
 *  \return Result.
 *  \retval 1 v1 > v2
 *  \retval 0 v1 == v2
 *  \retval -1 v1 < v2 */
int sp_compare_int(void* v1, void* v2);

/** \brief Compares two unsigned int.
 *  \param v1 Pointer to the first value.
 *  \param v2 Pointer to the second value.
 *  \return Result.
 *  \retval 1 v1 > v2
 *  \retval 0 v1 == v2
 *  \retval -1 v1 < v2 */
int sp_compare_unsigned_int(void* v1, void* v2);

/** \brief Compares two long.
 *  \param v1 Pointer to the first value.
 *  \param v2 Pointer to the second value.
 *  \return Result.
 *  \retval 1 v1 > v2
 *  \retval 0 v1 == v2
 *  \retval -1 v1 < v2 */
int sp_compare_long(void* v1, void* v2);

/** \brief Compares two unsigned long.
 *  \param v1 Pointer to the first value.
 *  \param v2 Pointer to the second value.
 *  \return Result.
 *  \retval 1 v1 > v2
 *  \retval 0 v1 == v2
 *  \retval -1 v1 < v2 */
int sp_compare_unsigned_long(void* v1, void* v2);

/** \brief Compares two long long.
 *  \param v1 Pointer to the first value.
 *  \param v2 Pointer to the second value.
 *  \return Result.
 *  \retval 1 v1 > v2
 *  \retval 0 v1 == v2
 *  \retval -1 v1 < v2 */
int sp_compare_long_long(void* v1, void* v2);

/** \brief Compares two unsigned long long.
 *  \param v1 Pointer to the first value.
 *  \param v2 Pointer to the second value.
 *  \return Result.
 *  \retval 1 v1 > v2
 *  \retval 0 v1 == v2
 *  \retval -1 v1 < v2 */
int sp_compare_unsigned_long_long(void* v1, void* v2);

/** \brief Compares two float.
 *  \param v1 Pointer to the first value.
 *  \param v2 Pointer to the second value.
 *  \return Result.
 *  \retval 1 v1 > v2
 *  \retval 0 v1 == v2
 *  \retval -1 v1 < v2 */
int sp_compare_float(void* v1, void* v2);

/** \brief Compares two double.
 *  \param v1 Pointer to the first value.
 *  \param v2 Pointer to the second value.
 *  \return Result.
 *  \retval 1 v1 > v2
 *  \retval 0 v1 == v2
 *  \retval -1 v1 < v2 */
int sp_compare_double(void* v1, void* v2);

/** \brief Compares two long double.
 *  \param v1 Pointer to the first value.
 *  \param v2 Pointer to the second value.
 *  \return Result.
 *  \retval 1 v1 > v2
 *  \retval 0 v1 == v2
 *  \retval -1 v1 < v2 */
int sp_compare_long_double(void* v1, void* v2);

/** \brief Compares two strings.
 *  \details Checks characters one-by-one. Result is the first difference.
 *  \param v1 Pointer to the first value.
 *  \param v2 Pointer to the second value.
 *  \return Result.
 *  \retval 1 v1 > v2
 *  \retval 0 v1 == v2
 *  \retval -1 v1 < v2 */
int sp_compare_string(void* v1, void* v2);

#endif
