//*****************************************************************************
// Copyright (c) 2020 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/guilds/baseGuild.c";

/////////////////////////////////////////////////////////////////////////////
public void SetupGuild()
{
    guildName("Scion of Dhuras");
    addPreferredSkillType("combat");

    addRank("neophyte", ([
        "name": "neophyte", 
        "title": "the Scion of Dhuras", 
        "pretitle": "Neophyte", 
        "next rank": "acolyte",
        "delay for next promotion": 1200
    ]));

    addRank("acolyte", ([
        "name": "acolyte", 
        "title": "the Scion of Dhuras", 
        "pretitle": "Acolyte", 
        "previous rank": "neophyte", 
        "next rank": "adept",
        "delay for next promotion": 3600
    ]));

    addRank("adept", ([
        "name": "adept", 
        "title": "the Scion of Dhuras", 
        "pretitle": "Adept", 
        "previous rank": "acolyte", 
        "next rank": "master",
        "delay for next promotion": 7200
    ]));

    addRank("master", ([
        "name": "master", 
        "title": "the Scion of Dhuras", 
        "pretitle": "Master", 
        "previous rank": "adept", 
    ]));

    setDefaultRank("neophyte");
    prohibitedGuildCombinations(({ "Aegis Guard", "fighter", "monk" }));

    addCriteria("hit points", ([
        "type": "modifier",
        "apply" : "3 every level",
        "begin at level" : 1
    ]));
    addCriteria("spell points", ([
        "type": "modifier",
        "apply" : "3 every level",
        "begin at level" : 1
    ]));
    addCriteria("stamina points", ([
        "type": "modifier",
        "apply" : "1 every level",
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

    addCriteria("spellcraft", ([
        "type":"skill",
        "apply": "1 every 2 levels"
    ]));

    addCriteria("mana shield tree", ([
        "type":"research tree",
        "apply": "at level 1",
        "research tree": "guilds/scion/common/mana-shield/mana-shield.c"
    ]));

    addCriteria("weapon focus", ([
        "type": "research path",
        "name": "The Focus",
        "description": "Choose your weapon focus",
        "apply": "at level 1",
        "research objects": ({ "guilds/scion/paths/sword.c",
            "guilds/scion/paths/dagger.c",
            "guilds/scion/paths/axe.c", 
            "guilds/scion/paths/mace.c",
            "guilds/scion/paths/hammer.c",
            "guilds/scion/paths/staff.c" })
    ]));

    addCriteria("magical sword path", ([
        "type": "research choice",
        "name": "The Path (Sword)",
        "description": "Choose your magical path",
        "apply": "at level 1",
        "apply if chosen": ({ "guilds/scion/paths/sword.c" }),
        "research objects": ({ "guilds/scion/paths/sword/flame.c",
            "guilds/scion/paths/sword/electricity.c",
            "guilds/scion/paths/sword/ice.c",
            "guilds/scion/paths/sword/blood.c",
            "guilds/scion/paths/sword/evocation.c",
            "guilds/scion/paths/sword/spirit.c" })
    ])); 

    addCriteria("magical axe path", ([
        "type": "research choice",
        "name": "The Path (Axe)",
        "description": "Choose your magical path",
        "apply": "at level 1",
        "apply if chosen": ({ "guilds/scion/paths/axe.c" }),
        "research objects": ({ "guilds/scion/paths/axe/flame.c",
            "guilds/scion/paths/axe/electricity.c",
            "guilds/scion/paths/axe/ice.c",
            "guilds/scion/paths/axe/blood.c",
            "guilds/scion/paths/axe/evocation.c",
            "guilds/scion/paths/axe/spirit.c" })
    ])); 

    addCriteria("magical dagger path", ([
        "type": "research choice",
        "name": "The Path (Dagger)",
        "description": "Choose your magical path",
        "apply": "at level 1",
        "apply if chosen": ({ "guilds/scion/paths/dagger.c" }),
        "research objects": ({ "guilds/scion/paths/dagger/flame.c",
            "guilds/scion/paths/dagger/electricity.c",
            "guilds/scion/paths/dagger/ice.c",
            "guilds/scion/paths/dagger/blood.c",
            "guilds/scion/paths/dagger/evocation.c",
            "guilds/scion/paths/dagger/spirit.c" })
    ])); 

    addCriteria("magical mace path", ([
        "type": "research choice",
        "name": "The Path (Mace)",
        "description": "Choose your magical path",
        "apply": "at level 1",
        "apply if chosen": ({ "guilds/scion/paths/mace.c" }),
        "research objects": ({ "guilds/scion/paths/mace/flame.c",
            "guilds/scion/paths/mace/electricity.c",
            "guilds/scion/paths/mace/ice.c",
            "guilds/scion/paths/mace/blood.c",
            "guilds/scion/paths/mace/evocation.c",
            "guilds/scion/paths/mace/spirit.c" })
    ])); 

    addCriteria("magical hammer path", ([
        "type": "research choice",
        "name": "The Path (Hammer)",
        "description": "Choose your magical path",
        "apply": "at level 1",
        "apply if chosen": ({ "guilds/scion/paths/hammer.c" }),
        "research objects": ({ "guilds/scion/paths/hammer/flame.c",
            "guilds/scion/paths/hammer/electricity.c",
            "guilds/scion/paths/hammer/ice.c",
            "guilds/scion/paths/hammer/blood.c",
            "guilds/scion/paths/hammer/evocation.c",
            "guilds/scion/paths/hammer/spirit.c" })
    ])); 

    addCriteria("magical staff path", ([
        "type": "research choice",
        "name": "The Path (Staff)",
        "description": "Choose your magical path",
        "apply": "at level 1",
        "apply if chosen": ({ "guilds/scion/paths/staff.c" }),
        "research objects": ({ "guilds/scion/paths/staff/flame.c",
            "guilds/scion/paths/staff/electricity.c",
            "guilds/scion/paths/staff/ice.c",
            "guilds/scion/paths/staff/blood.c",
            "guilds/scion/paths/staff/evocation.c",
            "guilds/scion/paths/staff/spirit.c" })
    ])); 
}
