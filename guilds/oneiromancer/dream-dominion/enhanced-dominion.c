//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/knowledgeResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Enhanced Dominion");
    addSpecification("source", "oneiromancer");
    addSpecification("description", "This skill provides the user with "
        "enhanced dominion over the dream realm, improving crushing attacks.");

    addPrerequisite("/guilds/oneiromancer/dream-dominion/mind-crush.c",
        (["type":"research"]));

    addPrerequisite("guild rank",
        (["type": "guild rank",
            "guild": "oneiromancer",
            "value": ({ "master" })
        ]));

    addPrerequisite("level",
        (["type":"level",
            "guild": "oneiromancer",
            "value": 13
        ]));

    addSpecification("research type", "points");
    addSpecification("research cost", 1);

    addSpecification("affected research", ([
        "Mind Crush": 25
    ]));
    addSpecification("affected research type", "percentage");
}
