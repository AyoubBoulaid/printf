#ifndef MAIN_H
#define MAIN_H

#include <stdarg.h>
#include <unistd.h>

#define BUFF_SIZE 1024 // Define the buffer size as needed

int get_flags(const char *format, int *index);
int get_width(const char *format, int *index, va_list args);
int get_precision(const char *format, int *index, va_list args);
int get_size(const char *format, int *index);
int handle_print(const char *format, int *index, va_list args,
                 char buffer[], int flags, int width, int precision, int size);
void print_buffer(char buffer[], int *buff_ind);
int _printf(const char *format, ...);

#endif /* MAIN_H */

