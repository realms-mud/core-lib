//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/guilds/baseGuild.c";

/////////////////////////////////////////////////////////////////////////////
public void SetupGuild()
{
    guildName("Disciple of Argloth");
    addPreferredSkillType("combat");

    prohibitedGuildCombinations(({ "Scion of Dhuras", "fighter", "monk", 
        "Drambor Edlothiad", "Guardian of Khazurath", "Children of Ilyrth",
        "League of Assassins", "phaedra", "ranger", "rogue", "Werric Knight",
        "Wrathguard", "necromancer", "Aegis Guard", "Disciple of Ferianth",
        "druid" }));

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
