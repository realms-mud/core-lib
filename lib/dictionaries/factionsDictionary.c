//*****************************************************************************
// Copyright (c) 2025 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************

private string BaseFaction = "/lib/modules/factions/baseFaction.c";

/////////////////////////////////////////////////////////////////////////////
public nomask object factionObject(string faction)
{
    object ret = 0;

    if (faction && stringp(faction) &&
        (file_size(faction) > 0))
    {
        ret = load_object(faction);
        if (member(inherit_list(ret), BaseFaction) < 0)
        {
            ret = 0;
        }
    }
    return ret;
}

/////////////////////////////////////////////////////////////////////////////
public nomask int isValidFaction(string faction)
{
    object factionObj = factionObject(faction);
    return factionObj && objectp(factionObj);
}

/////////////////////////////////////////////////////////////////////////////
public nomask string *getTradingFactions()
{
    return ({
        "/lib/modules/factions/merchantsGuild.c",
        "/lib/modules/factions/portAuthorities.c",
        "/lib/modules/factions/caravanMasters.c",
        "/lib/modules/factions/localNobility.c",
        "/lib/modules/factions/brigands.c",
        "/lib/modules/factions/pirates.c"
    });
}

/////////////////////////////////////////////////////////////////////////////
public nomask int canJoinFaction(string faction, object initiator)
{
    //TODO [72]: Finish this 
    return 1;
}

/////////////////////////////////////////////////////////////////////////////
public nomask int canLeaveFaction(string faction, object initiator)
{
    //TODO [72]: Finish this 
    return 1;
}

/////////////////////////////////////////////////////////////////////////////
public nomask string dispositionFromMurder(string faction, string disposition)
{
    string ret = disposition;
    switch (disposition)
    {
        case "enemy":
        case "betrayed":
        {
            break;
        }
        default:
        {
            ret = "hostile";
        }
    }
    return ret;
}
