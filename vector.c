#include "vector.h"
#include <stdlib.h>

struct vector_header
{
	char* data;
	size_t size;
	size_t item_size;
};

void* sp_vector_create(size_t item_size)
{
	struct vector_header* res;
	
	res = malloc(sizeof(struct vector_header));
	if (res)
	{
		res->data = NULL;
		res->size = 0;
		res->item_size = item_size;
	}

	return res;
}

size_t sp_vector_size(void* vector)
{
	size_t res;
	res = 0;

	if (vector != NULL)
	{
		res = ((struct vector_header*)vector)->size;
	}

	return res;
}

int sp_vector_fetch(void* vector, void* buffer, size_t position)
{
	int res;
	res = 0;

	if (vector != NULL && buffer != NULL && position < vector->size)
	{
		memcpy(buffer, vector->data + vector->item_size * position,
				vector->item_size);
		res = 1;
	}

	return res;
}

int sp_vector_write(void* vector, void* buffer, size_t position)
{
	int res;
	res = 0;

	if (vector != NULL && buffer != NULL && position < vector->size)
	{
		memcpy(vector->data + vector->item_size * position, buffer,
				vector->item_size);
		res = 1;
	}

	return res;
}

int sp_vector_push_back(void* vector, void* buffer)
{
	int res;
	char* new_data;

	res = 0;
	if (vector != NULL && buffer != NULL)
	{
		new_data = malloc(vector->item_size * (vector->size + 1));

		if (new_data != NULL && vector->data != NULL)
		{
			memcpy(new_data, vector->data,
					vector->size * vector->item_size);
			memcpy(new_data + vector->size * vector->item_size,
					buffer, vector->item_size);
			vector->size++;
			res = 1;
		}
		else if (new_data != NULL && vector->data == NULL)
		{
			memcpy(new_data, buffer, vector->item_size);
			vector->size++;
			res = 1;
		}

		if (vector->data != NULL)
		{
			free(vector->data);
		}
		
		if (new_data != NULL)
		{
			vector->data = new_data;
		}
	}

	return res;
}

int sp_vector_pop_back(void* vector, void* buffer)
{
	int res;
	char* new_data;

	res = 0;
	if (vector != NULL && buffer != NULL && vector->size != 0)
	{
		new_data = malloc(vector->item_size * (vector->size - 1));

		if (new_data != NULL && vector->data != NULL)
		{
			memcpy(new_data, vector->data,
				(vector->size - 1) * vector->item_size);
			memcpy(buffer,
				vector->data +
					(vector->size - 1) * vector->item_size,
				vector->item_size);
			vector->size--;
			res = 1;
		}

		if (vector->data != NULL)
		{
			free(vector->data);
		}

		if (new_data != NULL)
		{
			vector->data = new_data;
		}
	}
	
	return res;
}

int sp_vector_push_front(void* vector, void* buffer)
{
	int res;
	char* new_data;

	res = 0;
	if (vector != NULL && buffer != NULL)
	{
		new_data = malloc(vector->item_size * (vector->size + 1));

		if (new_data != NULL && vector->data != NULL)
		{
			memcpy(new_data, buffer, vector->item_size);
			memcpy(new_data + vector->item_size,
					vector->data,
					vector->item_size * (vector->size));
			vector->size++;
			res = 1;
		}
		else if (new_data != NULL && vector->data == NULL)
		{
			memcpy(new_data, buffer, vector->item_size);
			vector->size++;
			res = 1;
		}

		if (vector->data != NULL)
		{
			free(vector->data);
		}

		if (new_data != NULL)
		{
			vector->data = new_data;
		}
	}

	return res;
}

int sp_vector_pop_front(void* vector, void* buffer)
{
	int res;
	char* new_data;

	res = 0;
	if (vector != NULL && buffer != NULL && vector->size != 0)
	{
		new_data = malloc(vector->item_size * (vector->size - 1));

		if (new_data != NULL && vector->data != NULL)
		{
			memcpy(buffer, vector->data, vector->item_size);
			memcpy(new_data, vector->data + vector->item_size,
					vector->item_size * (vector->size - 1));
			vector->size--;
			res = 1;
		}

		if (vector->data != NULL)
		{
			free(vector->data);
		}

		if (new_data != NULL)
		{
			vector->data = new_data;
		}
	}

	return res;
}
