#include <stdio.h>
#include <stdarg.h>

int cs392_printf(const char * format, ...){

va_list args;
va_start(args, format);
 
//iterative over “format” and find specifiers
while (*format != '\0') {

	// get the first argument with va_arg
	// the following is an example of handling integer format “%d”

	if(*format == ‘%’){
		format ++;
		if(*format == 0)
			break;
				
		if(*format == ‘d’){
int arg_int = va_arg(args, int); 
// this helps you get the argument corresponding to “%d”
}

if(...)// you check for other formats
}
	++format;
    }
 
    va_end(args);

}
