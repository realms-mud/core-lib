//*****************************************************************************
// Copyright (c) 2019 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************

private mapping holdings = ([]);

/////////////////////////////////////////////////////////////////////////////
static nomask void loadDomains(mapping data, object persistence)
{
    if (isValidPersistenceObject(persistence))
    {
        holdings = persistence->extractSavedMapping("holdings", data);
    }
}

/////////////////////////////////////////////////////////////////////////////
static nomask mapping sendDomains()
{
    mapping ret = ([
        "holdings": holdings + ([])
    ]);

    return ret;
}
