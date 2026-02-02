//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/guilds/baseGuild.c";

/////////////////////////////////////////////////////////////////////////////
public void SetupGuild()
{
    guildName("Children of Ilyrth");
    addPreferredSkillType("magic");

    prohibitedGuildCombinations(({ "Drambor Edlothiad", "Werric Knight",
        "League of Assassins", "Wrathguard", "necromancer", "Disciple of Ferianth",
        "druid", "Hand of Bilanx" }));

    addRank("initiate", ([
        "name": "initiate", 
        "title": "of the Waters", 
        "pretitle": "Initiate", 
        "next rank": "acolyte",
        "delay for next promotion": 1200
    ]));

    addRank("acolyte", ([
        "name": "acolyte", 
        "title": "of Ilyrth", 
        "pretitle": "Acolyte", 
        "previous rank": "initiate", 
        "next rank": "priest",
        "delay for next promotion": 3600
    ]));

    addRank("priest", ([
        "name": "priest", 
        "title": "of Ilyrth", 
        "pretitle": "Priest", 
        "previous rank": "acolyte", 
        "next rank": "high priest",
        "delay for next promotion": 7200
    ]));

    addRank("high priest", ([
        "name": "high priest", 
        "title": "of Ilyrth", 
        "pretitle": "High Priest", 
        "previous rank": "priest", 
        "next rank": "wavekeeper",
        "delay for next promotion": 7200
    ]));

    addRank("wavekeeper", ([
        "name": "wavekeeper", 
        "title": ", Wavekeeper of Ilyrth", 
        "pretitle": "Wavekeeper", 
        "previous rank": "high priest"
    ]));

    setDefaultRank("initiate");
    prohibitedGuildCombinations(({ "Scion of Dhuras" }));

    addCriteria("hit points", ([
        "type": "modifier",
        "apply": "3 every level",
        "begin at level": 1
    ]));

    addCriteria("spell points", ([
        "type": "modifier",
        "apply": "6 every level",
        "begin at level": 1
    ]));

    addCriteria("stamina points", ([
        "type": "modifier",
        "apply": "2 every level",
        "begin at level": 1
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

    // Core healing tree - the heart of the guild
    addCriteria("healing waters", ([
        "type": "research tree",
        "apply": "at level 1",
        "research tree": "/guilds/children-of-ilyrth/healing/healing-waters.c"
    ]));

    // Defensive/protection tree
    addCriteria("tidal protection", ([
        "type": "research tree",
        "apply": "at level 1",
        "research tree": "/guilds/children-of-ilyrth/protection/tidal-protection.c"
    ]));

    // Passive wisdom/divination tree
    addCriteria("oceans wisdom", ([
        "type": "research tree",
        "apply": "at level 1",
        "research tree": "/guilds/children-of-ilyrth/wisdom/oceans-wisdom.c"
    ]));

    // Cleansing and curing afflictions
    addCriteria("purifying currents", ([
        "type": "research tree",
        "apply": "at level 5",
        "research tree": "/guilds/children-of-ilyrth/purification/purifying-currents.c"
    ]));

    // Offensive water/holy damage - "doing good requires action"
    addCriteria("righteous tide", ([
        "type": "research tree",
        "apply": "at level 7",
        "research tree": "/guilds/children-of-ilyrth/offense/righteous-tide.c"
    ]));

    // Group support and sustained abilities
    addCriteria("depths of devotion", ([
        "type": "research tree",
        "apply": "at level 11",
        "research tree": "/guilds/children-of-ilyrth/devotion/depths-of-devotion.c"
    ]));

    // Advanced spiritual/divine abilities
    addCriteria("divine current", ([
        "type": "research tree",
        "apply": "at level 25",
        "research tree": "/guilds/children-of-ilyrth/divine/divine-current.c"
    ]));

    // Mastery tree - ultimate abilities
    addCriteria("avatar of the deep", ([
        "type": "research tree",
        "apply": "at level 51",
        "research tree": "/guilds/children-of-ilyrth/mastery/avatar-of-the-deep.c"
    ]));
}
