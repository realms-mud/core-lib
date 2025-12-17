//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/knowledgeResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Master Siphon");
    addSpecification("source", "oneiromancer");
    addSpecification("description", "This skill provides the user with "
        "mastery of siphoning techniques.");

    addPrerequisite("/guilds/oneiromancer/psychic-siphon/efficient-drain.c",
        (["type":"research"]));

    addPrerequisite("guild rank",
        (["type": "guild rank",
            "guild": "oneiromancer",
            "value": ({ "psion", "master" })
        ]));

    addPrerequisite("level",
        (["type":"level",
            "guild": "oneiromancer",
            "value": 17
        ]));

    addSpecification("research type", "points");
    addSpecification("research cost", 1);

    addSpecification("affected research", ([
        "Drain Essence": 35,
        "Life Tap": 35
    ]));
    addSpecification("affected research type", "percentage");
}
