//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/guilds/baseGuild.c";

/////////////////////////////////////////////////////////////////////////////
public void SetupGuild()
{
    guildName("therianthrope");
    addPreferredSkillType("combat");
    prohibitedGuildCombinations(({ "Scion of Dhuras", "monk" }));

    addCriteria("hit points", ([
        "type": "modifier",
        "apply" : "4 every level",
        "begin at level" : 1
    ]));

    addCriteria("spell points", ([
        "type": "modifier",
        "apply" : "4 every level",
        "begin at level" : 1
    ]));

    addCriteria("stamina points", ([
        "type": "modifier",
        "apply" : "3 every level",
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
        "apply": "6 at level 1"
    ]));

    addCriteria("research points", ([
        "type": "research points",
        "apply": "1 every level"
    ]));

    addCriteria("supplemental research points", ([
        "type": "research points",
        "apply": "2 every 5 levels"
    ]));

    addCriteria("bear", ([
        "type": "research tree",
        "apply": "at level 1",
        "research tree": "/guilds/therianthrope/bear.c"
    ]));
    addCriteria("panther", ([
        "type": "research tree",
        "apply": "at level 1",
        "research tree": "/guilds/therianthrope/panther.c"
    ]));
    addCriteria("serpent", ([
        "type": "research tree",
        "apply": "at level 7",
        "research tree": "/guilds/therianthrope/serpent.c"
    ]));
    addCriteria("griffin", ([
        "type": "research tree",
        "apply": "at level 15",
        "research tree": "/guilds/therianthrope/griffin.c"
    ]));
    addCriteria("chimera", ([
        "type": "research tree",
        "apply": "at level 21",
        "research tree": "/guilds/therianthrope/chimera.c"
    ]));
    addCriteria("dragon", ([
        "type": "research tree",
        "apply": "at level 27",
        "research tree": "/guilds/therianthrope/dragon.c"
    ]));

}
