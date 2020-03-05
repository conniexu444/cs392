
#include <stdio.h>
#include <stdarg.h>
#include <string.h>
#include "cs392_printf.h"

int cs392_printf(const char *format, ...) {
	va_list args;
	va_start(args, format);
	static char number_list[] = "0123456789";
	static char buffer[50];
	char* stringA;
	 
	//iterative over “format” and find specifiers
	while (*format != '\0') {

		// get the first argument with va_arg
		// the following is an example of handling integer format “%d”

		if(*format == '%') {
			format ++;
					
			if(*format == 'd') {
				int integer_a = va_arg(args, int); 
				// this helps you get the argument corresponding to “%d”
				int temp = integer_a;
				int digits;

				// Calculate the number of digits in the number for the string
				if (temp != 0) {
					digits = 0;
					if (integer_a < 0) {
						integer_a = -integer_a;
						putchar('-');
					}
					stringA = &buffer[49];
					*stringA = '\0';
					while(temp != 0) {
						*--stringA = number_list[temp % 10];
						temp = temp / 10;
					}
					fputs(stringA, stdout);
				} else {
					putchar('0');
				}
				
			}
	    	if (*format == 's') { //If it is a string
	    		char* string_a = va_arg(args, char*);
				fputs(string_a, stdout);
	    	}
	    	if (*format == 'c') { //if it is a character
	    		char char_a = va_arg(args, int);
	    		putchar(char_a);
	    	}
	    } else {
	    	putchar(*format);
	    	}
		++format;
	    }
	    va_end(args);
	}

