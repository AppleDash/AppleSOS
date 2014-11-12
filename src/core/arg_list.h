#ifndef _KERNEL_ARG_LIST_H_
#define _KERNEL_ARG_LIST_H_

/*!
 * @brief Describes a kernel boot parameter.
 */
typedef struct {
	/*! The name of the boot parameter (i.e. 'debug') */
	unsigned char name[255];
	/*! The value of the boot parameter (i.e. 'true') */
	unsigned char value[255];
} k_arg;

/*!
 * @brief The arguments passed to the kernel on boot.
 */
typedef struct args {
	/*! The number of arguments. */
	unsigned int size;
	/* Each argument's description. */
	k_arg param[255];
} arg_list;

arg_list make_arg_list(const unsigned char *the_string);

#endif /*!_KERNEL_ARG_LIST_H_*/
