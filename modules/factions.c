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
public nomask string *Factions()
{
    return memberOfFactions + ({ });
}

/////////////////////////////////////////////////////////////////////////////
private nomask int dispositionTime()
{
    return getService("materialAttributes") ?
        getService("materialAttributes")->Age() : time();
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
            "last interaction": dispositionTime(),
            "number of interactions": 0,
            "disposition time": dispositionTime()
        ]);
    }
    else
    {
        ret = factions[faction]["disposition"];
        factions[faction]["last interaction"] = dispositionTime();
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
        int interactions = 0;

        if (member(factions, faction))
        {
            reputation = factions[faction]["reputation"];
            interactions = factions[faction]["number of interactions"];
        }

        factions[faction] = ([
                "disposition": "ally",
                "reputation": reputation,
                "last interaction": dispositionTime(),
                "number of interactions": interactions + 1,
                "disposition time": dispositionTime()
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
        int interactions = factions[faction]["number of interactions"];

        factions[faction] = ([
                "disposition": "betrayed",
                "reputation": reputation - 1000,
                "number of interactions": interactions + 1,
                "last interaction": dispositionTime(),
                "disposition time": dispositionTime()
        ]);

        memberOfFactions -= ({ faction });
    }
    return ret;
}

/////////////////////////////////////////////////////////////////////////////
private nomask void checkForDispositionChange(string faction)
{
    float reputationTrend = to_float(factions[faction]["reputation"]) /
        to_float(factions[faction]["number of interactions"]);
    
    // if there's a general trend toward positive or negative
    // after 8 hours in a disposition OR there is a very large single
    // event, change it.
    if (((factions[faction]["last interaction"] >
        (factions[faction]["disposition time"] + 28800)) &&
        (abs(reputationTrend) > 1.25)) || (abs(reputationTrend) > 25.25))
    {
        string newDisposition = getDictionary("factions")->getDisposition(
            factions[faction]["disposition"], reputationTrend);

        factions[faction] = ([
            "disposition": newDisposition,
            "reputation": 0,
            "number of interactions": 1,
            "last interaction": dispositionTime(),
            "disposition time": dispositionTime()
        ]);
    }
}

/////////////////////////////////////////////////////////////////////////////
public nomask void updateFactionDisposition(string faction, int reputation)
{
    if (!member(factions, faction))
    {
        factions[faction] = ([
            "disposition": "neutral",
            "reputation": reputation,
            "number of interactions": 1,
            "last interaction": dispositionTime(),
            "disposition time": dispositionTime()
        ]);
    }
    else
    {
        factions[faction]["reputation"] += reputation;
        factions[faction]["number of interactions"] += 1;
        factions[faction]["last interaction"] = dispositionTime();
    }
    checkForDispositionChange(faction);
}