//*****************************************************************************
// Copyright (c) 2021 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/guilds/baseGuild.c";

/////////////////////////////////////////////////////////////////////////////
public void SetupGuild()
{
    guildName("geomancer");
    addPreferredSkillType("combat");

    addCriteria("hit points", ([
        "type": "modifier",
        "apply" : "3 every level",
        "begin at level" : 1
    ]));

    addCriteria("spell points", ([
        "type": "modifier",
        "apply" : "5 every level",
        "begin at level" : 1
    ]));

    addCriteria("stamina points", ([
        "type": "modifier",
        "apply" : "3 every level",
        "begin at level" : 1
    ]));

    addCriteria("attribute points", ([
        "type":"attribute points",
        "apply": "1 every 5 levels"
    ]));

    addCriteria("skill points", ([
        "type":"skill points",
        "apply" : "5 every level"
    ]));
}
