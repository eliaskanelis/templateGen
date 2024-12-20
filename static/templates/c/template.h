/* ######################################################################### */
/* ######################################################################### */
/* About */

/* TODO: Doxygen the about section in file ${name}.h */

/**
 * \file     ${name}.h
 *
 * \brief    TODO: Write brief
 *
 * Created:  ${date}
 *
 * \author   ${author}    ${email}
 */

/**
 * \defgroup Ungrouped    Ungrouped
 *
 * \code
 * #include <${name}.h>
 * \endcode
 */

/* ######################################################################### */
/* ######################################################################### */
/* Start of Include Guard and C++ Compatibility */


#ifndef ${NAME}_H_ONLY_ONE_INCLUDE_SAFETY
#define ${NAME}_H_ONLY_ONE_INCLUDE_SAFETY

#ifdef __cplusplus
extern "C"
{
#endif


/* ######################################################################### */
/* ######################################################################### */
/* Dependencies */


#include <stdbool.h>
#include <stdint.h>


/* ######################################################################### */
/* ######################################################################### */
/* Configs */


/*  ---   DO NOT TOUCH BELOW THIS LINE!   ---  */

/* ######################################################################### */
/* ######################################################################### */
/* Definitions */


/* ######################################################################### */
/* ######################################################################### */
/* Types */


/**
 * \brief Represents a device with an ID and initialization status.
 */
typedef struct
{
	/** Unique identifier for the device. */
	uint32_t id;

	/** Status of initialization (true if initialized, false otherwise) */
	bool isInitialized;
} ${name}_t;


typedef struct
{
	uint32_t id;
	bool     isIinitialised;
} ${name}_t;


/* ######################################################################### */
/* ######################################################################### */
/* Public API */


/**
 * \brief Open.
 *
 * \param[in] pSelf The handle.
 *
 * \retval 0 On success.
 * \retval 1 On failure.
 */
extern int ${name}_open(const ${name} _t* const me);


/**
 * \brief Read.
 *
 * \param[in] pSelf The handle.
 *
 * \retval 0 On success.
 * \retval 1 On failure.
 */
extern int ${name}_read(const ${name} _t* const me);


/**
 * \brief Write.
 *
 * \param[in] pSelf The handle.
 *
 * \retval 0 On success.
 * \retval 1 On failure.
 */
extern int ${name}_write(const ${name} _t* const me);


/**
 * \brief Close.
 *
 * \param[in] pSelf The handle.
 *
 * \retval 0 On success.
 * \retval 1 On failure.
 */
extern int ${name}_close(const ${name} _t* const me);


/* ######################################################################### */
/* ######################################################################### */
/* End of Include Guard and C++ Compatibility */


#ifdef __cplusplus
}
#endif


#endif /* ${NAME}_H_ONLY_ONE_INCLUDE_SAFETY */
