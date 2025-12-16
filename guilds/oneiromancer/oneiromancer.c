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
    
    // Resources - mage-focused with higher spell points
    addCriteria("hit points", ([
        "type": "modifier",
        "apply" : "3 every level",
        "begin at level" : 1
    ]));

    addCriteria("spell points", ([
        "type": "modifier",
        "apply" : "6 every level",
        "begin at level" : 1
    ]));

    addCriteria("stamina points", ([
        "type": "modifier",
        "apply" : "2 every level",
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

    // Research points - generous for a magic guild
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

    // Core research trees
    addCriteria("dream magic", ([
        "type":"research tree",
        "apply": "at level 1",
        "research tree": "/guilds/oneiromancer/dream-magic.c"
    ]));

    addCriteria("psionic attacks", ([
        "type":"research tree",
        "apply": "at level 1",
        "research tree": "/guilds/oneiromancer/psionic-attacks.c"
    ]));

    addCriteria("nightmare persona", ([
        "type":"research tree",
        "apply": "at level 5",
        "research tree": "/guilds/oneiromancer/nightmare-persona.c"
    ]));

    addCriteria("lucid dreaming", ([
        "type":"research tree",
        "apply": "at level 10",
        "research tree": "/guilds/oneiromancer/lucid-dreaming.c"
    ]));

    addCriteria("psionic focus", ([
        "type":"research tree",
        "apply": "at level 1",
        "research tree": "/guilds/oneiromancer/psionic-focus.c"
    ]));
}
