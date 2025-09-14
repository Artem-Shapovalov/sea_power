#include "locator.h"

static char* buf = NULL;
static size_t buf_size = 0;
static size_t alloc_tab_len = 0;
static size_t allocated = 0;

void sp_cpy(void* from, void* to, size_t num)
{
	while (num)
	{
		((char*)to)[num - 1] = ((char*)from)[num - 1];
		num--;
	}
}

static char* alloc_tab_begin()
{
	return (buf + buf_size) - alloc_tab_len * (2 * sizeof(char*));
}

static char* alloc_tab_insert(size_t size)
{
	char* res;
	char* start;
	char* end;
	char* iter;

	res = NULL;

	if (alloc_tab_len == 0)
	{
		start = buf;
		end = buf + size;
		sp_cpy(start, buf + buf_size - 2 * sizeof(char*), sizeof(char*));
		sp_cpy(end, buf + buf_size - sizeof(char*), sizeof(char*));
		res = start;
		alloc_tab_len++;
	}
	else
	{
		iter = alloc_tab_begin();

		while (iter < buf + buf_size - 2 * sizeof(char*))
		{
			sp_cpy(iter + sizeof(char*), end, sizeof(char*));
			sp_cpy(iter + 2 * sizeof(char*), start, sizeof(char*));
			if (start - end >= size)
			{
				res = end + 1;
				iter += 2 * sizeof(char*);
				break;
			}
			
			iter += 2 * sizeof(char*);
		}

		if (res == NULL)
		{
			sp_cpy(buf + buf_size - sizeof(char*), end,
					sizeof(char*));
			start = alloc_tab_begin() - 2 * sizeof(char*);

			if (start - end >= size)
			{
				res = end + 1;
				iter = buf + buf_size;
			}
		}

		if (res != NULL)
		{
			sp_cpy(alloc_tab_begin(),
					alloc_tab_begin() - 2 * sizeof(char*),
					iter - alloc_tab_begin());
			alloc_tab_len++;
		}
	}

	return res;
}

static size_t alloc_tab_remove(char* start)
{
	char* iter;
	char* _start;
	char* _end;

	_start = NULL;
	_end = NULL;

	for (iter = alloc_tab_begin(); iter < buf + buf_size;
			iter += 2 * sizeof(char*))
	{
		sp_cpy(iter, _start, sizeof(char*));
		_end = _start;
		if (start == _start)
		{
			sp_cpy(iter + sizeof(char*), _end, sizeof(char*));
			sp_cpy(alloc_tab_begin(),
				alloc_tab_begin() + 2 * sizeof(char*),
				iter - alloc_tab_begin());
			alloc_tab_len--;
			break;
		}
	}

	return _end - _start;
}

void sp_malloc_init(void* buffer, size_t size)
{
	buf = buffer;
	buf_size = size;
	alloc_tab_len = 0;
	allocated = 0;
}

size_t sp_malloc_space()
{
	size_t res;
	res = buf_size;
	res -= (alloc_tab_len + 1) * 2 * sizeof(char*);
	res -= allocated;
	return res;
}

void* sp_malloc(size_t size)
{
	if (locator_space() < size)
	{
		return NULL;
	}
	else
	{
		allocated += size;
		return alloc_tab_insert(size);
	}
}

void sp_free(void* ptr)
{
	allocated -= alloc_tab_remove(ptr);
}
