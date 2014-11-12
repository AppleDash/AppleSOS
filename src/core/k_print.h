#ifndef __K_PRINT_H_
#define __K_PRINT_H_

#include <kstdarg.h>

/*!
 * @brief Write a formatting string as a kernel message to a string.
 * @param buffer The buffer to write the result to.
 * @param fmt The format of the string.
 * @param args The arguments to use with the format string.
 * @result <buffer> contains the result.
 * @returns The number of characters written to buffer.
 */
int vsprintf(char *buffer, const char *fmt, va_list args);
/*!
 * @brief Like <vsprintf>, but with variable arguments.
 * @see <vsprintf> for more details.
 */
int sprintf(char *buffer, const char *fmt, ...);
/*!
 * @brief Output a formatted string as a kernel message.
 * @param fmt The format of the string.
 * @param args The arguments to see with the format string
 * @result The formatted string is written to wherever kernel messages go.
 * @returns The number of characters written to the kernel message sink.
 * @note This assumes the default level of 'warning'.  If you want a different
 * level, use vprintf_level.
 */
int vprintf(const char *fmt, va_list args);
/*!
 * @brief Like <vprintf>, but with variable arguments.
 * @see <vprintf> for more details.
 */
int printf(const char *fmt, ...);

#endif /*!__K_PRINT_H_*/
