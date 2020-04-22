#include <stdio.h>
#include <string.h>
#include <stddef.h>
#include <sys/time.h>
#include <stdlib.h>
#include <ctype.h>

#include <time.h>

#include "file_io.h"

#define TEMPLATE_INSTALL_PATH			"${HOME}/.config/templateGen/templates/template"
static const char *g_filepath = TEMPLATE_INSTALL_PATH;

static const char *g_module_filepath = "";

/**
 * @brief
 * @param argc
 * @param argv
 * @return
 */
int main( int argc, char **argv )
{
	/* Variables */
	char *template = NULL;
	char *module_name = NULL;
	char *module_filepath = NULL;

	/* Check arguments */
	if( argc == 1 )
	{
		//module name
		printf( "Name: " );
		module_name = get_line();

		//module filepath
		size_t g_module_filepath_len = strlen( g_module_filepath );
		module_filepath = malloc( g_module_filepath_len + 1 );//TODO Check +1
		strcpy( module_filepath, g_module_filepath );

		//template filepath
		size_t filepath_len = strlen( g_filepath );
		template = malloc( filepath_len + 1 );//TODO Check +1
		strcpy( template, g_filepath );
	}
	else if( argc == 3 )
	{
		//module name
		printf( "Name: " );
		module_name = get_line();

		//module filepath
		size_t arg_1_len = strlen( argv[1] );
		module_filepath = malloc( arg_1_len + 1 );//TODO Check +1
		strcpy( module_filepath, argv[1] );

		//template filepath
		size_t arg_2_len = strlen( argv[2] );
		template = malloc( arg_2_len + 1 );//TODO Check +1
		strcpy( template, argv[2] );
	}
	else if( argc == 4 )
	{
		//module name
		size_t arg_1_len = strlen( argv[1] );
		module_name = malloc( arg_1_len + 1 );//TODO Check +1
		strcpy( module_name, argv[1] );

		//module filepath
		size_t arg_2_len = strlen( argv[2] );
		module_filepath = malloc( arg_2_len + 1 );//TODO Check +1
		strcpy( module_filepath, argv[2] );

		//template filepath
		size_t arg_3_len = strlen( argv[3] );
		template = malloc( arg_3_len + 1 );//TODO Check +1
		strcpy( template, argv[3] );
	}
	else
	{
		printf( "[ERROR] There are a few arguments...\n" );
		return 1;
	}

	/* Get time */
	char date[26];
	struct tm *tm_info;
	struct timeval tv;
	gettimeofday( &tv, NULL );
	tm_info = localtime( &tv.tv_sec );
	strftime( date, 26, "%d/%m/%Y", tm_info );

	/* Do the job */
	if( make_template( date, module_name, module_filepath, template, ".c" ) )
	{
		printf( "[ERROR] Failed to generate source file...\n" );
		return 1;
	}

	if( make_template( date, module_name, module_filepath, template, ".h" ) )
	{
		printf( "[ERROR] Failed to generate source file...\n" );
		return 1;
	}

	/* Garbage collection */
	free( template );
	free( module_name );
	free( module_filepath );

	/* Exit */
	printf( "\n[SUCCESS] Files generated...\n" );

	/* Stealth */
	/*	if( argc != 1 )
		{
			printf("\n\nPress any key to continue...\n");
			getchar();
		}*/

	return 0;
}
