/* dynlist.c: Dynamic lists and buffers in C.
 * created 1999-Jan-06 15:34 jmk
 * autodate: 2001-Sep-16 18:08
 *
 * by Jim Knoble <jmknoble@pobox.com>
 * Copyright (C) 1999,2000,2001 Jim Knoble
 *
 * Disclaimer:
 *
 * The software is provided "as is", without warranty of any kind,
 * express or implied, including but not limited to the warranties of
 * merchantability, fitness for a particular purpose and
 * noninfringement. In no event shall the author(s) be liable for any
 * claim, damages or other liability, whether in an action of
 * contract, tort or otherwise, arising from, out of or in connection
 * with the software or the use or other dealings in the software.
 *
 * Permission to use, copy, modify, distribute, and sell this software
 * and its documentation for any purpose is hereby granted without
 * fee, provided that the above copyright notice appear in all copies
 * and that both that copyright notice and this permission notice
 * appear in supporting documentation.
 */

#include <stdio.h>
#include <stdlib.h>

#include "dynlist.h"

#define LIST_CHUNK_SIZE 512
#define BUF_CHUNK_SIZE 512

/* For lists of pointers cast to char *. */
int append_to_list(char ***list_ptr, int *list_len, int *i, char *item) {
  char **tmp_ptr;

  if (*i >= *list_len) {
    *list_len += LIST_CHUNK_SIZE;
    if (NULL == *list_ptr) {
      tmp_ptr = malloc(sizeof(**list_ptr) * *list_len);
    } else {
      tmp_ptr = realloc(*list_ptr, (sizeof(**list_ptr) * *list_len));
    }
    if (NULL == tmp_ptr) {
      return (APPEND_FAILURE);
    }
    *list_ptr = tmp_ptr;
  }
  (*list_ptr)[*i] = item;
  (*i)++;
  return (APPEND_SUCCESS);
}

/* For single-dimensional buffers. */
int append_to_buf(char **buf, int *buflen, int *i, int c) {
  char *tmp_buf;

  if (*i >= *buflen) {
    *buflen += BUF_CHUNK_SIZE;
    if (NULL == *buf) {
      tmp_buf = malloc(sizeof(**buf) * *buflen);
    } else {
      tmp_buf = realloc(*buf, (sizeof(**buf) * *buflen));
    }
    if (NULL == tmp_buf) {
      return (APPEND_FAILURE);
    }
    *buf = tmp_buf;
#ifdef DEBUG
    printf("-->Allocated buffer of size %d\n", *buflen);
#endif /* DEBUG */
  }
  (*buf)[*i] = (char)c;
  (*i)++;
  return (APPEND_SUCCESS);
}
