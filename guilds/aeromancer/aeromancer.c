//*****************************************************************************
// Copyright (c) 2023 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/guilds/baseGuild.c";

/////////////////////////////////////////////////////////////////////////////
public void SetupGuild()
{
    guildName("aeromancer");
    addPreferredSkillType("combat");

    addCriteria("hit points", ([
        "type": "modifier",
        "apply": "3 every level",
        "begin at level" : 1
    ]));

    addCriteria("spell points", ([
        "type": "modifier",
        "apply": "5 every level",
        "begin at level" : 1
    ]));

    addCriteria("stamina points", ([
        "type": "modifier",
        "apply": "3 every level",
        "begin at level" : 1
    ]));

    addCriteria("attribute points", ([
        "type":"attribute points",
        "apply": "1 every 5 levels"
    ]));

    addCriteria("skill points", ([
        "type":"skill points",
        "apply": "5 every level"
    ]));

    addCriteria("lightning", ([
        "type":"research tree",
        "apply": "at level 1",
        "research tree": "/guilds/aeromancer/lightning.c"
    ]));

    addCriteria("air", ([
        "type":"research tree",
        "apply": "at level 1",
        "research tree": "/guilds/aeromancer/air.c"
    ]));
}
