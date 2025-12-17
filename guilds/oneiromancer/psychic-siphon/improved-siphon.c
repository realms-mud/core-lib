//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/knowledgeResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Improved Siphon");
    addSpecification("source", "oneiromancer");
    addSpecification("description", "This skill provides the user with "
        "improved siphoning techniques.");

    addPrerequisite("/guilds/oneiromancer/psychic-siphon/drain-essence.c",
        (["type":"research"]));

    addPrerequisite("guild rank",
        (["type": "guild rank",
            "guild": "oneiromancer",
            "value": ({ "psion", "master" })
        ]));

    addPrerequisite("level",
        (["type":"level",
            "guild": "oneiromancer",
            "value": 9
        ]));

    addSpecification("research type", "points");
    addSpecification("research cost", 1);

    addSpecification("affected research", ([
        "Drain Essence": 25,
        "Life Tap": 20
    ]));
    addSpecification("affected research type", "percentage");
}
