//*****************************************************************************
// Copyright (c) 2020 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
#include "/sys/input_to.h"

protected string ipAddress = query_ip_number(this_object());

protected object authenticationService = 
    load_object("/lib/modules/secure/dataServices/authenticationDataService.c");

/////////////////////////////////////////////////////////////////////////////
public nomask int preventShadows()
{
    return 1;
}

/////////////////////////////////////////////////////////////////////////////
protected nomask void removeTimeout()
{
    while (remove_call_out("timeout") != -1);
}

/////////////////////////////////////////////////////////////////////////////
static nomask void timeout()
{
    printf("\nThe time limit for this operation has been exceeded.\n"
        "Please try again.\n");
    destruct(this_object());
}
