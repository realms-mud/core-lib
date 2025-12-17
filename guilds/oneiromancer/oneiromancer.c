//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/guilds/baseGuild.c";

/////////////////////////////////////////////////////////////////////////////
public void SetupGuild()
{
    guildName("oneiromancer");
    addPreferredSkillType("magic");

    addRank("initiate", ([
        "name": "initiate",
        "title": "the Oneiromancer",
        "pretitle": "Initiate",
        "next rank": "adept",
        "delay for next promotion": 1200
    ]));

    addRank("adept", ([
        "name": "adept",
        "title": "the Oneiromancer",
        "pretitle": "Adept",
        "previous rank": "initiate",
        "next rank": "mentalist",
        "delay for next promotion": 3600
    ]));

    addRank("mentalist", ([
        "name": "mentalist",
        "title": "the Oneiromancer",
        "pretitle": "Mentalist",
        "previous rank": "adept",
        "next rank": "psion",
        "delay for next promotion": 7200
    ]));

    addRank("psion", ([
        "name": "psion",
        "title": "the Oneiromancer",
        "pretitle": "Psion",
        "previous rank": "mentalist",
        "next rank": "master",
        "delay for next promotion": 7200
    ]));

    addRank("master", ([
        "name": "master",
        "title": ", Master Oneiromancer",
        "pretitle": "Master",
        "previous rank": "psion"
    ]));

    setDefaultRank("initiate");

    // Resources - mage-focused with higher spell points
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

    // Research points
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

    // Core dream magic tree - primary spells and abilities
    addCriteria("dream magic", ([
        "type": "research tree",
        "apply": "at level 1",
        "research tree": "/guilds/oneiromancer/dream-magic.c"
    ]));

    // Psionic focus - single-target attacks and combat passives
    addCriteria("psionic focus", ([
        "type": "research tree",
        "apply": "at level 1",
        "research tree": "/guilds/oneiromancer/psionic-focus.c"
    ]));

    // Projection methods - delivery modifiers for combination attacks
    addCriteria("projection methods", ([
        "type": "research tree",
        "apply": "at level 1",
        "research tree": "/guilds/oneiromancer/projection-methods.c"
    ]));

    // Dream imagery - nightmare effects for combination attacks
    addCriteria("dream imagery", ([
        "type": "research tree",
        "apply": "at level 1",
        "research tree": "/guilds/oneiromancer/dream-imagery.c"
    ]));

    // Psionic combinations - combining attacks for enhanced effects
    addCriteria("psionic combinations", ([
        "type": "research tree",
        "apply": "at level 3",
        "research tree": "/guilds/oneiromancer/psionic-combinations.c"
    ]));

    // Nightmare persona - sustained form with passive bonuses
    addCriteria("nightmare persona", ([
        "type": "research tree",
        "apply": "at level 5",
        "research tree": "/guilds/oneiromancer/nightmare-persona.c"
    ]));

    // Adept rank tree - lucid control techniques
    addCriteria("lucid control", ([
        "type": "research tree",
        "apply": "at rank adept",
        "research tree": "/guilds/oneiromancer/lucid-control.c"
    ]));

    // Mentalist rank tree - mental fortification
    addCriteria("mental bastion", ([
        "type": "research tree",
        "apply": "at rank mentalist",
        "research tree": "/guilds/oneiromancer/mental-bastion.c"
    ]));

    // Psion rank tree - psychic siphon abilities
    addCriteria("psychic siphon", ([
        "type": "research tree",
        "apply": "at rank psion",
        "research tree": "/guilds/oneiromancer/psychic-siphon.c"
    ]));

    // Master rank tree - dream dominion
    addCriteria("dream dominion", ([
        "type": "research tree",
        "apply": "at rank master",
        "research tree": "/guilds/oneiromancer/dream-dominion.c"
    ]));
}
