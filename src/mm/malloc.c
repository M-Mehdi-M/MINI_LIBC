// SPDX-License-Identifier: BSD-3-Clause

#include <internal/mm/mem_list.h>
#include <internal/types.h>
#include <internal/essentials.h>
#include <sys/mman.h>
#include <string.h>
#include <stdlib.h>

extern struct mem_list mem_list_head;

void *malloc(size_t size)
{
	/* TODO: Implement malloc(). */
	if (size == 0) {
        return NULL;
    }

    void *ptr = mmap(NULL, size, PROT_READ | PROT_WRITE, MAP_PRIVATE | MAP_ANONYMOUS, -1, 0);

    if (ptr == MAP_FAILED) {
        return NULL;
    }

    mem_list_add(ptr, size);

    return ptr;
}

void *calloc(size_t nmemb, size_t size)
{
	/* TODO: Implement calloc(). */
	size_t total_size = nmemb * size;

    if (nmemb != 0 && total_size / nmemb != size) {
        return NULL;
    }

    void *ptr = malloc(total_size);

    if (ptr != NULL) {
        memset(ptr, 0, total_size);
    }

    return ptr;
}

void free(void *ptr)
{
	/* TODO: Implement free(). */
    if (ptr == NULL) {
        return;
    }

    struct mem_list *item = mem_list_find(ptr);

    if (item == NULL) {
        return;
    }

    item->prev->next = item->next;
    item->next->prev = item->prev;

    munmap(item->start, item->len);

    ptr = NULL;
}

void *realloc(void *ptr, size_t size)
{
	/* TODO: Implement realloc(). */
    if (ptr == NULL) {
        return malloc(size);
    }

    struct mem_list *item = mem_list_find(ptr);

    if (item == NULL) {
        return NULL;
    }

    void *new_ptr = malloc(size);

    if (new_ptr == NULL) {
        return NULL;
    }

    size_t copy_size = (size < item->len) ? size : item->len;
    memcpy(new_ptr, ptr, copy_size);

    free(ptr);

    return new_ptr;
}

void *reallocarray(void *ptr, size_t nmemb, size_t size)
{
	/* TODO: Implement reallocarray(). */
    size_t total_size = nmemb * size;

    if (nmemb != 0 && total_size / nmemb != size) {
        return NULL;
    }

    return realloc(ptr, total_size);
}
