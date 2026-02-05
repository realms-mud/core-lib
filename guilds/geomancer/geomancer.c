//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
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
        "type": "attribute points",
        "apply": "1 every 5 levels"
    ]));

    addCriteria("skill points", ([
        "type": "skill points",
        "apply": "5 every level"
    ]));

    addCriteria("initial research points", ([
        "type": "research points",
        "apply": "5 at level 1"
    ]));

    addCriteria("research points", ([
        "type": "research points",
        "apply": "1 every level"
    ]));

    addCriteria("supplemental research points", ([
        "type": "research points",
        "apply": "2 every 5 levels"
    ]));

    addCriteria("stone", ([
        "type": "research tree",
        "apply": "at level 1",
        "research tree": "/guilds/geomancer/stone.c"
    ]));

    addCriteria("earth", ([
        "type": "research tree",
        "apply": "at level 1",
        "research tree": "/guilds/geomancer/earth.c"
    ]));

    addCriteria("forms", ([
        "type": "research tree",
        "apply": "at level 1",
        "research tree": "/guilds/geomancer/forms.c"
    ]));

    addCriteria("functions", ([
        "type": "research tree",
        "apply": "at level 1",
        "research tree": "/guilds/geomancer/functions.c"
    ]));

    addCriteria("effects", ([
        "type": "research tree",
        "apply": "at level 1",
        "research tree": "/guilds/geomancer/effects.c"
    ]));

    addCriteria("construct", ([
        "type": "research tree",
        "apply": "at level 1",
        "research tree": "/guilds/geomancer/construct.c"
    ]));
}
