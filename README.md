<p align="center">
  <img src="logo.svg" width="300"/><br/><br/>
  Every C/C++ developer deserves just to develop his project.<br/><br/>
</p>

# sea_power

Modern features right in your pure C program.

# Motivation

It's a part of the Sea project and the goal is the same: ease the pain of the development. C is a prehistoric language, it almost no evolved, but its simplicity and speed still makes a sense. Why we should bury it, instead of improve the programming experience?

# Core Principles

- Make it ANSI C and MISRA compatible as far as can.
- Make it portable as far as can, don't forget about the embedded platforms.
- Object-orientied emulation should be based on the object pointer and set of functions used this pointer. Common name for it is 'this'
- Inheritance emulation is forbidden. Aggregate and compose objects instead.

# Memory Management

WARNING: THE ALIGNMENT IS NOT IMPLEMENTED YET! IT'S UNSAFE FOR USE IT NOW!

Classical problem: there's no malloc for your platform. At all. GiHhub is full of the bloated allocators, but there's little one.

located at `malloc.h`, it's a singleton.

`sp_malloc_init` - initializes the allocator.
`sp_malloc_space` - checks out the available space at the moment.
`sp_malloc` - allocates the memory.
`sp_free` - deallocates the memory by pointer.
`sp_cpy` - the same as memcpy, but with the convenient arguments sequence.

# Containers

Containers are pretty similar to C++ STL containers, it utilize the dynamical memory, automatocally allocating and freeing it.

## List

`sp_list` - the container object
`sp_list_push_front` - emplace item in front of the list
`sp_list_push_back` - emplece item in back of the list
`sp_list_pop_front` - delete the item from the front of the list
`sp_list_pop_back` - delete the item from the back of the list
`sp_list_iterator` - the container iterator object
`sp_list_iterator_next` - moves iterator to the next position
