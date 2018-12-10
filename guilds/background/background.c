//*****************************************************************************
// Copyright (c) 2018 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/guilds/baseGuild.c";

/////////////////////////////////////////////////////////////////////////////
public void SetupGuild()
{
    guildName("background");
    addPreferredSkillType("combat");

    addCriteria("hit points", ([
        "type": "modifier",
        "apply": "2 every level",
        "end at level": 5
    ]));
    addCriteria("spell points", ([
        "type": "modifier",
        "apply": "2 every level",
        "end at level": 5
    ]));
    addCriteria("stamina points", ([
        "type": "modifier",
        "apply": "2 every level",
        "end at level": 5
    ]));

    addCriteria("attribute points", ([
        "type": "attribute points",
        "apply": "1 every 2 levels",
        "end at level": 5
    ]));

    addCriteria("skill points", ([
        "type": "skill points",
        "apply": "5 every level",
        "end at level": 5
    ]));

    addCriteria("research points", ([
        "type": "research points",
        "apply": "1 every level",
        "end at level": 5
    ]));

    addCriteria("background focus", ([
        "type": "research path",
        "name": "Your Focus",
        "description": "What types of activities were you most interested "
            "in during your childhood?",
        "apply": "at level 1",
        "research objects": ({ 
            "lib/guilds/background/paths/learning.c"
        })
    ]));
}
