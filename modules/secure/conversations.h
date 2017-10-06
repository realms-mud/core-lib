//*****************************************************************************
// Copyright (c) 2017 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************

private mapping opinions = ([]);

/////////////////////////////////////////////////////////////////////////////
static nomask void loadConversationData(mapping data, object persistence)
{
    if (isValidPersistenceObject(persistence))
    {
/*        intoxicated = persistence->extractSaveData("intoxicated", data);
        stuffed = persistence->extractSaveData("stuffed", data);
        drugged = persistence->extractSaveData("drugged", data);
        soaked = persistence->extractSaveData("soaked", data);
        headache = persistence->extractSaveData("headache", data);
        */
    }
}

/////////////////////////////////////////////////////////////////////////////
static nomask mapping sendConversation()
{
    return ([
/*        "intoxicated": intoxicated,
        "stuffed": stuffed,
        "drugged": drugged,
        "soaked": soaked,
        "headache": headache, */
    ]);
}
