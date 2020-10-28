//*****************************************************************************
// Copyright (c) 2020 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/guilds/baseGuild.c";

/////////////////////////////////////////////////////////////////////////////
public void SetupGuild()
{
    guildName("Aegis Guard");
    addPreferredSkillType("combat");
    addRank("recruit", (["name":"recruit", "title" : "the title of titliness", "pretitle" : "Recruit", "next rank" : "acolyte"]));
    addRank("acolyte", (["name":"acolyte", "title" : "the title of titliness", "pretitle" : "Acolyte", "previous rank" : "neophyte", "next rank" : "master", "delay for next promotion" : 1]));
    addRank("master", (["name":"master", "title" : "the title of titliness", "pretitle" : "Master"]));
    setDefaultRank("recruit");
    prohibitedGuildCombinations(({ "Scion of Dhuras", "fighter", "monk" }));

    addCriteria("hit points", ([
        "type": "modifier",
        "apply" : "4 every level",
        "begin at level" : 1
    ]));
    addCriteria("spell points", ([
        "type": "modifier",
        "apply" : "2 every level",
        "begin at level" : 1
    ]));
    addCriteria("stamina points", ([
        "type": "modifier",
        "apply" : "2 every level",
        "begin at level" : 1
    ]));

    addCriteria("weapon attack", ([
        "type":"attack",
        "apply" : "1 every 10 levels"
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
        "apply": "at level 1"
    ]));

    addCriteria("research points", ([
        "type":"research points",
        "apply": "2 every level"
    ]));
}
