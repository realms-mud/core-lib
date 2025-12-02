//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/guilds/baseGuild.c";

/////////////////////////////////////////////////////////////////////////////
public void SetupGuild()
{
    guildName("fighter");
    addPreferredSkillType("combat");
    prohibitedGuildCombinations(({ "Scion of Dhuras", "Aegis Guard" }));

    addCriteria("hit points", ([
        "type": "modifier",
        "apply" : "6 every level",
        "begin at level" : 1
    ]));

    addCriteria("stamina points", ([
        "type": "modifier",
        "apply" : "4 every level",
        "begin at level" : 1
    ]));

    addCriteria("weapon attack", ([
        "type":"attack",
        "apply" : "1 every 15 levels"
    ]));

    addCriteria("attribute points", ([
        "type":"attribute points",
        "apply": "1 every 5 levels"
    ]));

    addCriteria("skill points", ([
        "type":"skill points",
        "apply" : "5 every level"
    ]));

    addCriteria("blade attacks", ([
        "type":"research tree",
        "apply": "at level 1",
        "research tree": "/guilds/fighter/blade-attacks.c"
    ]));

    addCriteria("axe attacks", ([
        "type":"research tree",
        "apply": "at level 1",
        "research tree": "/guilds/fighter/axe-attacks.c"
    ]));

    addCriteria("polearm attacks", ([
        "type":"research tree",
        "apply": "at level 1",
        "research tree": "/guilds/fighter/polearm-attacks.c"
    ]));

    addCriteria("shields", ([
        "type":"research tree",
        "apply": "at level 1",
        "research tree": "/guilds/fighter/shields.c"
    ]));

    addCriteria("bludgeon attacks", ([
        "type":"research tree",
        "apply": "at level 1",
        "research tree": "/guilds/fighter/bludgeon-attacks.c"
    ]));

    addCriteria("combat techniques", ([
        "type":"research tree",
        "apply": "at level 1",
        "research tree": "/guilds/fighter/combat-techniques.c"
    ]));
}
