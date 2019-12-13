//*****************************************************************************
// Copyright (c) 2020 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************

/////////////////////////////////////////////////////////////////////////////
public void onTraitAdded(object caller, string data)
{
    raise_error(sprintf("event handler: onTraitAdded called, data: %s, caller: %s",
        data, program_name(caller)));
}

/////////////////////////////////////////////////////////////////////////////
public void onTraitRemoved(object caller, string data)
{
    raise_error(sprintf("event handler: onTraitRemoved called, data: %s, caller: %s",
        data, program_name(caller)));
}
