// ############################################################################
// ############################################################################
// About

// TODO: Doxygen the about section in file ${name}.h

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

// ############################################################################
// ############################################################################
// Code

#ifndef ${NAME}_H_ONLY_ONE_INCLUDE_SAFETY
#define ${NAME}_H_ONLY_ONE_INCLUDE_SAFETY

#ifdef __cplusplus
extern "C"
{
#endif

// ############################################################################
// ############################################################################
// Dependencies

#include <stdint.h>
#include <stdbool.h>

// ############################################################################
// ############################################################################
// Configs


/*  ---   DO NOT TOUCH BELOW THIS LINE!   ---  */

// ############################################################################
// ############################################################################
// Definitions


// ############################################################################
// ############################################################################
// Types

typedef struct
{
	uint32_t id;
	bool isIinitialised;
} ${name}_t;

// ############################################################################
// ############################################################################
// Function declarations


/**
 * \brief    Open.
 *
 * \param[in,out] me    The handle.
 *
 * \retval   0 on success.
 * \retval   1 on failure.
 */
int ${name}_open( ${name}_t *const me );


/**
 * \brief   Read.
 *
 * \param[in,out] me    The handle.
 *
 * \retval   0 on success.
 * \retval   1 on failure.
 */
int ${name}_read( ${name}_t *const me );


/**
 * \brief   Write.
 *
 * \param[in,out] me    The handle.
 *
 * \retval   0 on success.
 * \retval   1 on failure.
 */
int ${name}_write( ${name}_t *const me );


/**
 * \brief    Close.
 *
 * \param[in] me    The handle.
 *
 * \retval   0 on success.
 * \retval   1 on failure.
 */
int ${name}_close( const ${name}_t *const me );


#ifdef __cplusplus
}
#endif

#endif /* ${NAME}_H_ONLY_ONE_INCLUDE_SAFETY */
