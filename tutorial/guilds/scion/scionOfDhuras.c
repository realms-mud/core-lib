//*****************************************************************************
// Copyright (c) 2018 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/guilds/baseGuild.c";

/////////////////////////////////////////////////////////////////////////////
public void SetupGuild()
{
    guildName("Scion of Dhuras");
    addPreferredSkillType("combat");
    addRank("neophyte", (["name":"neophyte", "title" : "the title of titliness", "pretitle" : "Neophyte", "next rank" : "acolyte"]));
    addRank("acolyte", (["name":"acolyte", "title" : "the title of titliness", "pretitle" : "Acolyte", "previous rank" : "neophyte", "next rank" : "blargyte", "delay for next promotion" : 1]));
    addRank("blargyte", (["name":"blargyte", "title" : "the title of titliness", "pretitle" : "Blargyte"]));
    setDefaultRank("neophyte");

    addCriteria("hit points", ([
        "type":"modifier",
        "apply" : "3 every level",
        "begin at level" : 1
    ]));
    addCriteria("spell points", ([
        "type":"modifier",
        "apply" : "3 every level",
        "begin at level" : 1
    ]));
    addCriteria("stamina points", ([
        "type":"modifier",
        "apply" : "1 every level",
        "begin at level" : 1
    ]));

    addCriteria("weapon attack", ([
        "type":"attack",
        "apply" : "1 every 10 levels"
    ]));
    addCriteria("attribute points", ([
        "type":"attribute points",
            "apply" : "1 every 5 levels"
    ]));
    addCriteria("skill points", ([
        "type":"skill points",
        "apply" : "5 every level"
    ]));
    addCriteria("research points", ([
        "type":"research points",
        "apply" : "1 every level"
    ]));

    addCriteria("spellcraft", ([
        "type":"skill",
        "apply" : "1 every 2 levels"
    ]));

    addCriteria("weapon focus", ([
        "type": "research path",
        "name": "The Focus",
        "description": "Choose your weapon focus",
        "apply": "at level 1",
        "research objects": ({ "lib/tutorial/guilds/scion/paths/sword.c",
            "lib/tutorial/guilds/scion/paths/dagger.c",
            "lib/tutorial/guilds/scion/paths/axe.c", 
            "lib/tutorial/guilds/scion/paths/mace.c",
            "lib/tutorial/guilds/scion/paths/hammer.c",
            "lib/tutorial/guilds/scion/paths/staff.c" })
    ]));

    addCriteria("magical path", ([
        "type": "research choice",
        "name": "The Path",
        "description": "Choose your magical path",
        "apply": "at level 1",
        "research objects": ({ "lib/tutorial/guilds/scion/paths/flame.c",
            "lib/tutorial/guilds/scion/paths/electricity.c",
            "lib/tutorial/guilds/scion/paths/ice.c",
            "lib/tutorial/guilds/scion/paths/blood.c",
            "lib/tutorial/guilds/scion/paths/evocation.c",
            "lib/tutorial/guilds/scion/paths/spirit.c" })
    ]));
}