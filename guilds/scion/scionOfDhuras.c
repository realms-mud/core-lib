//*****************************************************************************
// Copyright (c) 2019 - Allen Cummings, RealmsMUD, All rights reserved. See
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
    prohibitedGuildCombinations(({ "fighter", "monk" }));

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
        "research tree": "lib/guilds/scion/common/mana-shield/mana-shield.c"
    ]));

    addCriteria("weapon focus", ([
        "type": "research path",
        "name": "The Focus",
        "description": "Choose your weapon focus",
        "apply": "at level 1",
        "research objects": ({ "lib/guilds/scion/paths/sword.c",
            "lib/guilds/scion/paths/dagger.c",
            "lib/guilds/scion/paths/axe.c", 
            "lib/guilds/scion/paths/mace.c",
            "lib/guilds/scion/paths/hammer.c",
            "lib/guilds/scion/paths/staff.c" })
    ]));

    addCriteria("magical sword path", ([
        "type": "research choice",
        "name": "The Path (Sword)",
        "description": "Choose your magical path",
        "apply": "at level 1",
        "apply if chosen": ({ "lib/guilds/scion/paths/sword.c" }),
        "research objects": ({ "lib/guilds/scion/paths/sword/flame.c",
            "lib/guilds/scion/paths/sword/electricity.c",
            "lib/guilds/scion/paths/sword/ice.c",
            "lib/guilds/scion/paths/sword/blood.c",
            "lib/guilds/scion/paths/sword/evocation.c",
            "lib/guilds/scion/paths/sword/spirit.c" })
    ])); 

    addCriteria("magical axe path", ([
        "type": "research choice",
        "name": "The Path (Axe)",
        "description": "Choose your magical path",
        "apply": "at level 1",
        "apply if chosen": ({ "lib/guilds/scion/paths/axe.c" }),
        "research objects": ({ "lib/guilds/scion/paths/axe/flame.c",
            "lib/guilds/scion/paths/axe/electricity.c",
            "lib/guilds/scion/paths/axe/ice.c",
            "lib/guilds/scion/paths/axe/blood.c",
            "lib/guilds/scion/paths/axe/evocation.c",
            "lib/guilds/scion/paths/axe/spirit.c" })
    ])); 

    addCriteria("magical dagger path", ([
        "type": "research choice",
        "name": "The Path (Dagger)",
        "description": "Choose your magical path",
        "apply": "at level 1",
        "apply if chosen": ({ "lib/guilds/scion/paths/dagger.c" }),
        "research objects": ({ "lib/guilds/scion/paths/dagger/flame.c",
            "lib/guilds/scion/paths/dagger/electricity.c",
            "lib/guilds/scion/paths/dagger/ice.c",
            "lib/guilds/scion/paths/dagger/blood.c",
            "lib/guilds/scion/paths/dagger/evocation.c",
            "lib/guilds/scion/paths/dagger/spirit.c" })
    ])); 

    addCriteria("magical mace path", ([
        "type": "research choice",
        "name": "The Path (Mace)",
        "description": "Choose your magical path",
        "apply": "at level 1",
        "apply if chosen": ({ "lib/guilds/scion/paths/mace.c" }),
        "research objects": ({ "lib/guilds/scion/paths/mace/flame.c",
            "lib/guilds/scion/paths/mace/electricity.c",
            "lib/guilds/scion/paths/mace/ice.c",
            "lib/guilds/scion/paths/mace/blood.c",
            "lib/guilds/scion/paths/mace/evocation.c",
            "lib/guilds/scion/paths/mace/spirit.c" })
    ])); 

    addCriteria("magical hammer path", ([
        "type": "research choice",
        "name": "The Path (Hammer)",
        "description": "Choose your magical path",
        "apply": "at level 1",
        "apply if chosen": ({ "lib/guilds/scion/paths/hammer.c" }),
        "research objects": ({ "lib/guilds/scion/paths/hammer/flame.c",
            "lib/guilds/scion/paths/hammer/electricity.c",
            "lib/guilds/scion/paths/hammer/ice.c",
            "lib/guilds/scion/paths/hammer/blood.c",
            "lib/guilds/scion/paths/hammer/evocation.c",
            "lib/guilds/scion/paths/hammer/spirit.c" })
    ])); 

    addCriteria("magical staff path", ([
        "type": "research choice",
        "name": "The Path (Staff)",
        "description": "Choose your magical path",
        "apply": "at level 1",
        "apply if chosen": ({ "lib/guilds/scion/paths/staff.c" }),
        "research objects": ({ "lib/guilds/scion/paths/staff/flame.c",
            "lib/guilds/scion/paths/staff/electricity.c",
            "lib/guilds/scion/paths/staff/ice.c",
            "lib/guilds/scion/paths/staff/blood.c",
            "lib/guilds/scion/paths/staff/evocation.c",
            "lib/guilds/scion/paths/staff/spirit.c" })
    ])); 
}
