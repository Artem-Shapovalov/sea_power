#ifndef STRING_H
#define STRING_H

#include <stddef.h>

/** \brief Creates a string object.
 *  \return Pointer to the string object.
 *  \retval NULL Unable to create object */
void* sp_string_create();

/** \brief Destroys the string object.
 *  \param string Pointer to the string object.
 *  \return Result.
 *  \retval 1 String is destroyed.
 *  \retval 0 Unable to destroy requested string. */
int sp_string_destroy(void* string);

/** \brief Extracts the c-string from the string object.
 *  \param strig Pointer to the string object.
 *  \return Pointer to the c-string. */
const char* sp_string_c_string(void* string);

/** \brief Append the one string with another.
 *  \param string Pointer to the string object.
 *  \param another Pointer to another string object.
 *  \return Result.
 *  \retval 1 String is appended.
 *  \retval 0 Unable to append the string. */
int sp_string_append_string(void* string, void* another);

/** \brief Append the string object with a c-string.
 *  \param string Pointer to the string object.
 *  \param c_string Pointer to the c-string to append.
 *  \return Result.
 *  \retval 1 String is appended.
 *  \retval 0 Unable to append the string. */
int sp_string_append_c_string(void* string, const char* c_string);

/** \brief Clears the string.
 *  \param string Pointer to the string object.
 *  \return Result.
 *  \retval 1 String is cleared.
 *  \retval 0 Unable to clear the string. */
int sp_string_clear(void* string);

/** \brief Returns the length of the string in bytes.
 *  \param string Pointer to the string object.
 *  \return Number of the characters without null-terminator. */
size_t sp_string_length(void* string);

#endif
