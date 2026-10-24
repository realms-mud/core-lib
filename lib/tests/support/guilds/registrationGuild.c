//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/guilds/baseGuild.c";

private int SetupCalls;

/////////////////////////////////////////////////////////////////////////////
public void SetupGuild()
{
    SetupCalls++;
    guildName("registration test guild");
    guildClass("combat");

    addCriteria("hit points", ([
        "type":"modifier",
        "apply":"6 every level",
        "begin at level":1
    ]));
    addCriteria("skill points", ([
        "type":"skill points",
        "apply":"5 every level"
    ]));
}

/////////////////////////////////////////////////////////////////////////////
public int setupCalls()
{
    return SetupCalls;
}
