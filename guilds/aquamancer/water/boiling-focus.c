//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/knowledgeResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Boiling Focus");
    addSpecification("source", "aquamancer");
    addSpecification("description", "This research provides the user with "
        "enhanced knowledge of heat transfer within water. By understanding "
        "how to efficiently superheat water without losing energy, the "
        "aquamancer can deliver more devastating scalding attacks.");

    addPrerequisite("level",
        (["type":"level",
            "guild": "aquamancer",
            "value": 7
        ]));

    addPrerequisite("/guilds/aquamancer/water/scalding-blast.c",
        (["type":"research"]));

    addSpecification("research type", "points");
    addSpecification("research cost", 1);
    addSpecification("affected research", ([
        "Scalding Blast": 25,
        "Steamweaving": 25,
        "Boiling Convergence": 25,
        "Tsunami": 25,
    ]));
    addSpecification("affected research type", "percentage");
}
