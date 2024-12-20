/* ######################################################################### */
/* ######################################################################### */
/* About */


/* ######################################################################### */
/* ######################################################################### */
/* Dependencies */


#include "${name}.h"

#include <stdlib.h>


/* ######################################################################### */
/* ######################################################################### */
/* Type Definitions */


#if 0 /* TODO: Implement */
#	define LOGS
#endif


/* ######################################################################### */
/* ######################################################################### */
/* Internal function declaration */


/**
 * \brief Retrieves the name of the device.
 *
 * \return A constant pointer to a string containing the device name.
 */
static const char* getName(void);


/* ######################################################################### */
/* ######################################################################### */
/* Internal variables */


static const char g_name = "${name}"; /**< The name of the module */


/* ######################################################################### */
/* ######################################################################### */
/* External function definitions */


int ${name}_open(${name}_t* const pSelf)
{
	int errorCode = 0;

	if (pSelf == NULL)
	{
		log_error("Invalid arguments");
		errorCode = 1;
	}

	if (errorCode == 0)
	{
		/* TODO: Implement */
		log_info("Opened %s", getName());
	}

	return errorCode;
}


int ${name}_read(${name}_t* const pSelf)
{
	int errorCode = 0;

	if (pSelf == NULL)
	{
		log_error("Invalid arguments");
		errorCode = 1;
	}

	if (errorCode == 0)
	{
		/* TODO: Implement */
		log_info("Read from %s", getName());
	}

	return errorCode;
}


int ${name}_write(${name}_t* const me)
{
	int errorCode = 0;

	if (pSelf == NULL)
	{
		log_error("Invalid arguments");
		errorCode = 1;
	}

	if (errorCode == 0)
	{
		/* TODO: Implement */
		log_info("Written to %s", getName());
	}

	return errorCode;
}


int ${name}_close(const ${name}_t* const pSelf)
{
	int errorCode = 0;

	if (pSelf == NULL)
	{
		log_error("Invalid arguments");
		errorCode = 1;
	}

	if (errorCode == 0)
	{
		/* TODO: Implement */
		log_info("Closed ${name}");
	}

	return errorCode;
}


/* ######################################################################### */
/* ######################################################################### */
/* Intenal function definitions */


const char* getName(void)
{
	return g_name;
}
