//*****************************************************************************
// Copyright (c) 2017 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************

private string race;

/////////////////////////////////////////////////////////////////////////////
static nomask void loadRaces(mapping data, object persistence)
{
    if (isValidPersistenceObject(persistence))
    {
        race = persistence->extractSaveData("race", data);
    }
}

/////////////////////////////////////////////////////////////////////////////
static nomask mapping sendRaces()
{
    return ([
        "race": race
    ]);
}