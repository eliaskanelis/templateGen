/******************************************************************************
	About
******************************************************************************/

//TODO: Doxygen the about section in file file_io.h

/**
 * \file file_io.h
 *
 * \brief	TODO: Write brief
 *
 * Created:			30/11/2017
 *
 * \author	Ilias Kanelis	hkanelhs@yahoo.gr
 */

/**
* \defgroup	Ungrouped	Ungrouped
*
* \code	#include <file_io.h>	\endcode
*/

/******************************************************************************
	Code
******************************************************************************/

#ifndef FILE_IO_H_ONLY_ONE_INCLUDE_SAFETY
#define FILE_IO_H_ONLY_ONE_INCLUDE_SAFETY

#ifdef __cplusplus
extern "C"
{
#endif

/******************************************************************************
	Include files
******************************************************************************/

//#include <stdio.h>

/******************************************************************************
	Custom definitions
******************************************************************************/


/*  ---   DO NOT TOUCH BELOW THIS LINE!   ---  */

/******************************************************************************
	Definitions
******************************************************************************/

/******************************************************************************
	Type definitions
******************************************************************************/

//int fee;	/**< What is the purpose of fee */

/******************************************************************************
	Function declarations
******************************************************************************/

char*	read_file( const char* filename );

char*	str_replace( char** orig, char *rep, char *with );

char*	get_line(void);

int		addStrings( char** buffer, const char* path, const char* name, const char* filetype );

int		make_template( char* date, char* filename, char* filepath, const char* template_file, const char* filetype );

#ifdef __cplusplus
}
#endif

#endif /* FILE_IO_H_ONLY_ONE_INCLUDE_SAFETY */
