//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/knowledgeResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Absolute Dominion");
    addSpecification("source", "oneiromancer");
    addSpecification("description", "This skill provides the user with "
        "absolute dominion over the dream realm, greatly enhancing all "
        "master techniques.");

    addPrerequisite("/guilds/oneiromancer/dream-dominion/enhanced-dominion.c",
        (["type":"research"]));

    addPrerequisite("guild rank",
        (["type": "guild rank",
            "guild": "oneiromancer",
            "value": ({ "master" })
        ]));

    addPrerequisite("level",
        (["type":"level",
            "guild": "oneiromancer",
            "value": 17
        ]));

    addSpecification("research type", "points");
    addSpecification("research cost", 1);

    addSpecification("affected research", ([
        "Mind Crush": 35,
        "Nightmare": 35,
        "Dreamscape": 35,
    ]));
    addSpecification("affected research type", "percentage");
}
