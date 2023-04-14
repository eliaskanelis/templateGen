// ############################################################################
// ############################################################################
// Code

// ############################################################################
// ############################################################################
// Include files

#include "${name}.h"

#include <stdlib.h>

// ############################################################################
// ############################################################################
// Local definitions

// #define LOGS

// ############################################################################
// ############################################################################
// Local variables

// int fee; /**< What is the purpose of fee */

// ############################################################################
// ############################################################################
// Local function declarations


// ############################################################################
// ############################################################################
// Local functions


// ############################################################################
// ############################################################################
// Function definitions


int ${name}_open( ${name}_t *const me )
{
	int errorCode = 0;

	if( me == NULL )
	{
		log_error( "Invalid arguments" );
		errorCode = 1;
	}

	if( errorCode != 0 )
	{
		// TODO: Implement
		log_info( "Opened ${name}" );
	}

	return errorCode;
}


int ${name}_read( ${name}_t *const me )
{
	int errorCode = 0;

	if( me == NULL )
	{
		log_error( "Invalid arguments" );
		errorCode = 1;
	}

	if( errorCode != 0 )
	{
		// TODO: Implement
		log_info( "Read ${name}" );
	}

	return errorCode;
}


int ${name}_write( ${name}_t *const me )
{
	int errorCode = 0;

	if( me == NULL )
	{
		log_error( "Invalid arguments" );
		errorCode = 1;
	}

	if( errorCode != 0 )
	{
		// TODO: Implement
		log_info( "Write ${name}" );
	}

	return errorCode;
}


int ${name}_close( const ${name}_t *const me )
{
	int errorCode = 0;

	if( me == NULL )
	{
		log_error( "Invalid arguments" );
		errorCode = 1;
	}

	if( errorCode != 0 )
	{
		// TODO: Implement
		log_info( "Close ${name}" );
	}

	return errorCode;
}
