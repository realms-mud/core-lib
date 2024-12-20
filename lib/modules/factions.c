//*****************************************************************************
// Copyright (c) 2025 - Allen Cummings, RealmsMUD, All rights reserved. See
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
private nomask int isValidFaction(string faction)
{
    object dictionary = getDictionary("factions");
    return dictionary && dictionary->isValidFaction(faction);
}

/////////////////////////////////////////////////////////////////////////////
private nomask varargs int isKnownFaction(string faction, int whenNotMember)
{
    int ret = 0;
    if(isValidFaction(faction))
    {
        if (!member(factions, faction))
        {
            factions[faction] = ([
                "disposition": "neutral",
                "reputation": 0,
                "last interaction": dispositionTime(),
                "last interaction reputation": 0,
                "number of interactions": 0,
                "disposition time": dispositionTime()
            ]);
            ret = whenNotMember;
        }
        else
        {
            ret = 1;
        }
    }
    return ret;
}

/////////////////////////////////////////////////////////////////////////////
public nomask string factionDispositionToward(string faction)
{
    string ret = "invalid";

    if(isKnownFaction(faction, 1))
    {
        ret = factions[faction]["disposition"];
    }
    return ret;
}

/////////////////////////////////////////////////////////////////////////////
public nomask int factionReputationToward(string faction)
{
    int ret = 0;

    if (isKnownFaction(faction))
    {
        ret = factions[faction]["reputation"];
    }
    return ret;
}

/////////////////////////////////////////////////////////////////////////////
public nomask int joinFaction(string faction)
{
    int ret = 0;
    object dictionary = getDictionary("factions");

    if (dictionary && isValidFaction(faction) &&
        (member(memberOfFactions, faction) < 0) &&
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
            "last interaction reputation": reputation,
            "number of interactions": interactions + 1,
            "disposition time": dispositionTime()
        ]);

        memberOfFactions += ({ faction });
    }
    return ret;
}

/////////////////////////////////////////////////////////////////////////////
public nomask int leaveFaction(string faction)
{
    int ret = 0;
    object dictionary = getDictionary("factions");

    if (dictionary && isValidFaction(faction) &&
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
            "last interaction reputation": reputation - 1000,
            "disposition time": dispositionTime()
        ]);

        memberOfFactions -= ({ faction });
    }
    return ret;
}

/////////////////////////////////////////////////////////////////////////////
private nomask varargs void checkForDispositionChange(string faction, int killedMember)
{
    float reputationTrend = (to_float(factions[faction]["reputation"]) - 
        to_float(factions[faction]["last interaction reputation"])) /
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
    else if (killedMember)
    {
        factions[faction] = ([
            "disposition":getDictionary("factions")->dispositionFromMurder(faction,
                factions[faction]["disposition"]),
            "reputation": factions[faction]["reputation"],
            "number of interactions": 1,
            "last interaction": dispositionTime(),
            "disposition time": dispositionTime()
        ]);
    }
}

/////////////////////////////////////////////////////////////////////////////
public nomask varargs void updateFactionDisposition(string faction, int reputation, int killedMember)
{
    if (isValidFaction(faction))
    {
        if (!member(factions, faction))
        {
            factions[faction] = ([
                "disposition":"neutral",
                "reputation" : reputation,
                "number of interactions" : 1,
                "last interaction" : dispositionTime(),
                "disposition time" : dispositionTime()
            ]);
        }
        else
        {
            factions[faction]["reputation"] += reputation;
            factions[faction]["number of interactions"] += 1;
            factions[faction]["last interaction"] = dispositionTime();
        }
        checkForDispositionChange(faction, killedMember);

        factions[faction]["last interaction reputation"] =
            factions[faction]["reputation"];
    }
}

/////////////////////////////////////////////////////////////////////////////
public nomask void toggleUnsafeFactionInteractions()
{

}

/////////////////////////////////////////////////////////////////////////////
public nomask int unsafeFactionInteractions()
{
    return 0;
}
