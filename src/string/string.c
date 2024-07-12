// SPDX-License-Identifier: BSD-3-Clause

#include <string.h>

char *strcpy(char *destination, const char *source)
{
	/* TODO: Implement strcpy(). */
	if (destination == NULL || source == NULL) {
        return NULL;
    }

    char *dest_ptr = destination;
    const char *src_ptr = source;

    while (*src_ptr != '\0') {
        *dest_ptr = *src_ptr;
        dest_ptr++;
        src_ptr++;
    }

    *dest_ptr = '\0';

	return destination;
}

char *strncpy(char *destination, const char *source, size_t len)
{
	/* TODO: Implement strncpy(). */
	if (destination == NULL || source == NULL || len == 0) {
        return destination;
    }

    char *dest_ptr = destination;
    const char *src_ptr = source;
    size_t i;

    for (i = 0; i < len && *src_ptr != '\0'; i++) {
        *dest_ptr = *src_ptr;
        dest_ptr++;
        src_ptr++;
    }


    for (; i < len; i++) {
        *dest_ptr = '\0';
        dest_ptr++;
    }

	return destination;
}

char *strcat(char *destination, const char *source)
{
	/* TODO: Implement strcat(). */
	if (destination == NULL || source == NULL) {
        return destination;
    }

    char *dest_ptr = destination;

    while (*dest_ptr != '\0') {
        dest_ptr++;
    }

    const char *src_ptr = source;

    while (*src_ptr != '\0') {
        *dest_ptr = *src_ptr;
        dest_ptr++;
        src_ptr++;
    }

    *dest_ptr = '\0';

	return destination;
}

char *strncat(char *destination, const char *source, size_t len)
{
	/* TODO: Implement strncat(). */
	char *dest_ptr = destination;
    while (*dest_ptr != '\0') {
        dest_ptr++;
    }

    while (*source != '\0' && len > 0) {
        *dest_ptr = *source;
        dest_ptr++;
        source++;
        len--;
    }

    *dest_ptr = '\0';

	return destination;
}

int strcmp(const char *str1, const char *str2)
{
	/* TODO: Implement strcmp(). */
	while (*str1 != '\0' || *str2 != '\0') {
        if (*str1 != *str2) {
            return (*str1 - *str2);
        }
        str1++;
        str2++;
    }

    return 0;
}

int strncmp(const char *str1, const char *str2, size_t len)
{
	/* TODO: Implement strncmp(). */
	while (len > 0) {
        if (*str1 != *str2) {
            return *str1 - *str2;
        }

        if (*str1 == '\0') {
            return 0;
        }

        str1++;
        str2++;
        len--;
    }

    return 0;
}

size_t strlen(const char *str)
{
	size_t i = 0;

	for (; *str != '\0'; str++, i++)
		;

	return i;
}

char *strchr(const char *str, int c)
{
	/* TODO: Implement strchr(). */
	while (*str != '\0') {
        if (*str == (char)c) {
            return (char *)str;
        }
        str++;
    }

	return NULL;
}

char *strrchr(const char *str, int c)
{
	/* TODO: Implement strrchr(). */
	if (str == NULL)
        return NULL;

    const char *last = NULL;

    while (*str != '\0')
    {
        if (*str == c)
            last = str;
        str++;
    }

    return (char *)last;
}

char *strstr(const char *haystack, const char *needle)
{
	/* TODO: Implement strstr(). */
	if (haystack == NULL || needle == NULL)
        return NULL;

    size_t haystack_len = strlen(haystack);
    size_t needle_len = strlen(needle);

    if (needle_len == 0)
        return (char *)haystack;

    if (haystack_len < needle_len)
        return NULL;

    for (size_t i = 0; i <= haystack_len - needle_len; i++)
    {
        if (strncmp(haystack + i, needle, needle_len) == 0)
            return (char *)(haystack + i);
    }

	return NULL;
}

char *strrstr(const char *haystack, const char *needle)
{
	/* TODO: Implement strrstr(). */
	if (haystack == NULL || needle == NULL)
        return NULL;

    size_t haystack_len = strlen(haystack);
    size_t needle_len = strlen(needle);

    if (needle_len == 0)
        return (char *)(haystack + haystack_len);

    if (haystack_len < needle_len)
        return NULL;

    for (size_t i = haystack_len - needle_len; i > 0; i--) {
        if (strncmp(haystack + i, needle, needle_len) == 0)
            return (char *)(haystack + i);
    }

	return NULL;
}

void *memcpy(void *destination, const void *source, size_t num)
{
	/* TODO: Implement memcpy(). */
	char *dest = (char *)destination;
    const char *src = (const char *)source;

    for (size_t i = 0; i < num; i++) {
        dest[i] = src[i];
    }

	return destination;
}

void *memmove(void *destination, const void *source, size_t num)
{
	/* TODO: Implement memmove(). */
	char *dest = (char *)destination;
    const char *src = (const char *)source;

    if (dest > src && dest < src + num) {
        for (size_t i = num; i > 0; i--) {
            dest[i - 1] = src[i - 1];
        }
    } else {
        for (size_t i = 0; i < num; i++) {
            dest[i] = src[i];
        }
    }

	return destination;
}

int memcmp(const void *ptr1, const void *ptr2, size_t num)
{
	/* TODO: Implement memcmp(). */
	const unsigned char *p1 = (const unsigned char *)ptr1;
    const unsigned char *p2 = (const unsigned char *)ptr2;

    for (size_t i = 0; i < num; i++) {
        if (p1[i] < p2[i]) {
            return -1;
        } else if (p1[i] > p2[i]) {
            return 1;
        }
    }

    return 0;
}

void *memset(void *source, int value, size_t num)
{
	/* TODO: Implement memset(). */
	unsigned char *p = (unsigned char *)source;
    unsigned char val = (unsigned char)value;

    for (size_t i = 0; i < num; i++) {
        p[i] = val;
    }

	return source;
}
