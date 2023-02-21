//*****************************************************************************
// Copyright (c) 2023 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
#ifndef factionsModule_h
#define factionsModule_h

private mapping factions = ([
    //  <faction file name>: ([
    //      "disposition": ally, friendly, admiring, cautious, neutral, wary, fearful, hostile, enemy, betrayed 
    //      "reputation": value,
    //      "last interaction": <time>,
    //      "last interaction reputation": value,
    //      "number of interactions": <number>,
    //      "disposition time": <time>,
    //  ])
]);

private string *memberOfFactions = ({ });

////////////////////////////////////////////////////////////////////////////
static nomask void loadFactions(mapping data, object persistence)
{
    if (isValidPersistenceObject(persistence))
    {
        memberOfFactions =
            persistence->extractSaveData("memberOfFactions", data);

        factions = persistence->extractSavedMapping("factions", data);
    }
}

/////////////////////////////////////////////////////////////////////////////
static nomask mapping sendFactions()
{
    mapping ret = ([
        "memberOfFactions": memberOfFactions,
        "factions": ([ ])
    ]);

    string *list = m_indices(factions);
    foreach(string faction in list)
    {
        ret["factions"][faction] = factions[faction];
    }

    return ret;
}

#endif
