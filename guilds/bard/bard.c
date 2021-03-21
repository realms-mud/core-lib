//*****************************************************************************
// Copyright (c) 2021 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/guilds/baseGuild.c";

/////////////////////////////////////////////////////////////////////////////
public void SetupGuild()
{
    guildName("bard");
    addPreferredSkillType("combat");
    prohibitedGuildCombinations(({ "Scion of Dhuras", "monk" }));

    addCriteria("hit points", ([
        "type": "modifier",
        "apply" : "4 every level",
        "begin at level" : 1
    ]));

    addCriteria("spell points", ([
        "type": "modifier",
        "apply" : "3 every level",
        "begin at level" : 1
    ]));

    addCriteria("stamina points", ([
        "type": "modifier",
        "apply" : "3 every level",
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

    addCriteria("initial research points", ([
        "type":"research points",
        "apply": "5 at level 1"
    ]));

    addCriteria("research points", ([
        "type":"research points",
        "apply": "1 every level"
    ]));

    addCriteria("supplemental research points", ([
        "type":"research points",
        "apply": "2 every 5 levels"
    ]));

    addCriteria("compose songs", ([
        "type": "research",
        "apply": "at level 1",
        "research object": "guilds/bard/compositions/compose-song.c"
    ]));

    addCriteria("stop performance", ([
        "type": "research",
        "apply": "at level 1",
        "research object": "guilds/bard/compositions/stop-performance.c"
    ]));

    addCriteria("bows", ([
        "type":"research tree",
        "apply": "at level 1",
        "research tree": "guilds/bard/bows.c"
    ]));

    addCriteria("melee weapons", ([
        "type":"research tree",
        "apply": "at level 1",
        "research tree": "guilds/bard/melee-attacks.c"
    ]));

    addCriteria("chants", ([
        "type":"research tree",
        "apply": "at level 1",
        "research tree": "guilds/bard/chants.c"
    ]));

    addCriteria("compositions", ([
        "type":"research tree",
        "apply": "at level 1",
        "research tree": "guilds/bard/compositions.c"
    ]));

    addCriteria("lyrics", ([
        "type":"research tree",
        "apply": "at level 1",
        "research tree": "guilds/bard/lyrics.c"
    ]));

    addCriteria("strings", ([
        "type":"research tree",
        "apply": "at level 1",
        "research tree": "guilds/bard/strings.c"
    ]));

    addCriteria("woodwind-brass", ([
        "type":"research tree",
        "apply": "at level 1",
        "research tree": "guilds/bard/woodwind-brass.c"
    ]));

    addCriteria("percussion", ([
        "type":"research tree",
        "apply": "at level 1",
        "research tree": "guilds/bard/percussion.c"
    ]));
}
