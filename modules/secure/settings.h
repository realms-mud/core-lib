//*****************************************************************************
// Copyright (c) 2017 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************

private int IsBusy = 0;
private mapping blockedUsers = ([ ]);

private nosave object ReplyTo;

/////////////////////////////////////////////////////////////////////////////
static nomask void loadSettings(mapping data, object persistence)
{
    if (isValidPersistenceObject(persistence))
    {
    }
}

/////////////////////////////////////////////////////////////////////////////
static nomask mapping sendSettings()
{
    return ([

    ]);
}
