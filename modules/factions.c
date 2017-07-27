//*****************************************************************************
// Copyright (c) 2017 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
virtual inherit "/lib/core/organizations.c";
#include "/lib/modules/secure/factions.h"

/////////////////////////////////////////////////////////////////////////////
public nomask int memberOfFaction(string faction)
{
    return (member(factions, faction) &&
        (member(memberOfFactions, faction) > -1));
}

/////////////////////////////////////////////////////////////////////////////
public nomask string factionDispositionToward(string faction)
{
    string ret = "neutral";

    if (!member(factions, faction))
    {
        factions[faction] = ([
            "disposition": "neutral",
            "reputation": 0,
            "last interaction": time(),
            "disposition time": time()
        ]);
    }
    else
    {
        ret = factions[faction]["disposition"];
        factions[faction]["last interaction"] = time();
    }

    return ret;
}

/////////////////////////////////////////////////////////////////////////////
public nomask int joinFaction(string faction)
{
    int ret = 0;
    object dictionary = getDictionary("factions");

    if (dictionary && dictionary->isValidFaction(faction) &&
        dictionary->canJoinFaction(faction, this_object()))
    {
        ret = 1;
        int reputation = 0;
        if (member(factions, faction))
        {
            reputation = factions[faction]["reputation"];
        }

        factions[faction] = ([
                "disposition": "ally",
                "reputation": reputation,
                "last interaction": time(),
                "disposition time": time()
        ]);
    }
    return ret;
}

/////////////////////////////////////////////////////////////////////////////
public nomask int leaveFaction(string faction)
{
    int ret = 0;
    object dictionary = getDictionary("factions");

    if (dictionary && dictionary->isValidFaction(faction) &&
        dictionary->canLeaveFaction(faction, this_object()) &&
        memberOfFaction(faction))
    {
        ret = 1;
        int reputation = factions[faction]["reputation"];

        factions[faction] = ([
                "disposition": "betrayed",
                "reputation": reputation - 1000,
                "last interaction": time(),
                "disposition time": time()
        ]);

        memberOfFactions -= ({ faction });
    }
    return ret;
}