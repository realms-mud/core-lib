//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/knowledgeResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Perfect Lucidity");
    addSpecification("source", "oneiromancer");
    addSpecification("description", "This skill provides the user with "
        "perfect mental lucidity, greatly enhancing focused attacks.");

    addPrerequisite("/guilds/oneiromancer/lucid-control/enhanced-clarity.c",
        (["type":"research"]));

    addPrerequisite("guild rank",
        (["type": "guild rank",
            "guild": "oneiromancer",
            "value": ({ "adept", "mentalist", "psion", "master" })
        ]));

    addPrerequisite("level",
        (["type":"level",
            "guild": "oneiromancer",
            "value": 15
        ]));

    addSpecification("research type", "points");
    addSpecification("research cost", 1);

    addSpecification("affected research", ([
        "Lucid Burst": 35
    ]));
    addSpecification("affected research type", "percentage");
}
