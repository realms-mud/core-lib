//*****************************************************************************
// Copyright (c) 2019 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************

/////////////////////////////////////////////////////////////////////////////
public void onDeath(object caller)
{
    raise_error(sprintf("event handler: onDeath called: %s", program_name(caller)));
}
