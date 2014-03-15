#include <stdbool.h>

#include "list.h"

#define TEXT_CHUNK_SIZE 1024

typedef struct {
    bool bold;
    bool italics;
    bool paragraph;
    unsigned int indentation;
    unsigned int bullet_level;
    unsigned int enumeration_level;

    const char *link;
    const char *alt_text;

    const char *image;
    const char *caption;

    char chunk[TEXT_CHUNK_SIZE];
    unsigned int _pos;
} text_chunk_t;

typedef struct {
    list_t *chunks;
} text_field_t;

typedef struct {
    unsigned int col;
    list_t *show; // list of char *
} structure_t;

typedef struct {
    text_field_t *title;
    text_field_t *date;
    structure_t *structure;
    list_t *news;
} newspaper_t;

typedef struct {
    const char *name;
    text_field_t *title;
    const char *image;
    text_field_t *abstract;
    text_field_t *text;
    text_field_t *author;
    text_field_t *source;
    text_field_t *date;
    structure_t *structure;
} news_t;

news_t *news_new(void);
structure_t *structure_new(void);
text_field_t *text_field_new(void);
text_chunk_t *text_chunk_new(void);
text_chunk_t *text_chunk_new_copy_attrs(text_chunk_t *copy);
text_chunk_t *text_field_get_last_chunk(text_field_t *field);
void text_field_append_char(text_field_t *field, char c);
