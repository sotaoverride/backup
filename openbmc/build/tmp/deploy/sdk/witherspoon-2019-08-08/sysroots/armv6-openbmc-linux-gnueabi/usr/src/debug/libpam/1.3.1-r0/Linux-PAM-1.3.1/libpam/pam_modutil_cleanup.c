/*
 * $Id$
 *
 * This function provides a common pam_set_data() friendly version of free().
 */

#include <stdlib.h>

#include "pam_modutil_private.h"

void pam_modutil_cleanup(pam_handle_t* pamh UNUSED, void* data,
                         int error_status UNUSED)
{
    if (data)
    {
        /* junk it */
        (void)free(data);
    }
}
