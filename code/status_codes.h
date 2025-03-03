#ifndef STATUS_CODES_H
#define STATUS_CODES_H

typedef enum status {
    OK,
    ERROR,
    NOT_INIT_ERROR,
    MALLOC_ERROR,
    FILE_ERROR,
    FORMAT_ERROR
} status_t;

#endif //STATUS_CODES_H
