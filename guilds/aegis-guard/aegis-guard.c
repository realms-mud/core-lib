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

    addRank("recruit", ([
        "name": "recruit", 
        "title": "of the Aegis Guard", 
        "pretitle": "Recruit", 
        "next rank": "guardsman"
    ]));

    addRank("guardsman", ([
        "name": "guardsman", 
        "title": "of the Aegis Guard", 
        "pretitle": "", 
        "previous rank": "recruit", 
        "next rank": "corporal",
        "delay for next promotion": 1200
    ]));

    addRank("corporal", ([
        "name": "corporal", 
        "title": "of the Aegis Guard", 
        "pretitle": "Corporal", 
        "previous rank": "guardsman", 
        "next rank": "sergeant",
        "delay for next promotion": 3600
    ]));

    addRank("sergeant", ([
        "name": "sergeant", 
        "title": "of the Aegis Guard", 
        "pretitle": "Corporal", 
        "previous rank": "corporal", 
        "next rank": "lieutenant",
        "delay for next promotion": 3600
    ]));

    addRank("lieutenant", ([
        "name": "lieutenant", 
        "title": "of the Aegis Guard", 
        "pretitle": "Lieutenant", 
        "previous rank": "sergeant", 
        "next rank": "lieutenant commander",
        "delay for next promotion": 3600
    ]));

    addRank("lieutenant commander", ([
        "name": "lieutenant commander", 
        "title": "of the Aegis Guard", 
        "pretitle": "Lieutenant Commander", 
        "previous rank": "lieutenant", 
        "next rank": "commander",
        "delay for next promotion": 3600
    ]));

    addRank("commander", ([
        "name": "commander", 
        "title": "of the Aegis Guard", 
        "pretitle": "Commander", 
        "previous rank": "lieutenant commander", 
        "next rank": "captain",
        "delay for next promotion": 3600
    ]));

    addRank("captain", ([
        "name": "captain", 
        "title": "of the Aegis Guard", 
        "pretitle": "Captain", 
        "previous rank": "commander", 
        "next rank": "general",
        "delay for next promotion": 7200
    ]));

    addRank("general", ([
        "name": "general", 
        "title": "of the Aegis Guard", 
        "pretitle": "General", 
        "previous rank": "captain", 
    ]));

    setDefaultRank("recruit");
    prohibitedGuildCombinations(({ "Scion of Dhuras", "fighter", "monk" }));

    addCriteria("hit points", ([
        "type": "modifier",
        "apply" : "5 every level",
        "begin at level" : 1
    ]));
    addCriteria("spell points", ([
        "type": "modifier",
        "apply" : "2 every level",
        "begin at level" : 1
    ]));
    addCriteria("stamina points", ([
        "type": "modifier",
        "apply" : "3 every level",
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
        "apply": "1 every level"
    ]));

    addCriteria("supplemental research points", ([
        "type":"research points",
        "apply": "2 every 5 levels"
    ]));

    addCriteria("sword attacks", ([
        "type":"research tree",
        "apply": "at level 1",
        "research tree": "guilds/aegis-guard/sword-attacks.c"
    ]));

    addCriteria("sword evasion", ([
        "type":"research tree",
        "apply": "at level 1",
        "research tree": "guilds/aegis-guard/sword-evading.c"
    ]));

    addCriteria("sword guarding", ([
        "type":"research tree",
        "apply": "at level 1",
        "research tree": "guilds/aegis-guard/sword-guarding.c"
    ]));

    addCriteria("bows", ([
        "type":"research tree",
        "apply": "at level 1",
        "research tree": "guilds/aegis-guard/bows.c"
    ]));

    addCriteria("combinations", ([
        "type":"research tree",
        "apply": "at level 5",
        "research tree": "guilds/aegis-guard/sword-combinations.c"
    ]));

    addCriteria("actions", ([
        "type":"research tree",
        "apply": "at level 11",
        "research tree": "guilds/aegis-guard/sword-actions.c"
    ]));

    addCriteria("mythic", ([
        "type":"research tree",
        "apply": "at level 15",
        "research tree": "guilds/aegis-guard/sword-mythic.c"
    ]));
}
