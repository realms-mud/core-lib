//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/knowledgeResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Steamweaving");
    addSpecification("source", "aquamancer");
    addSpecification("description", "This research provides the user with "
        "advanced knowledge of manipulating water in its gaseous state. By "
        "understanding the principles of vaporization and condensation, the "
        "aquamancer can create more devastating scalding attacks and control "
        "steam with precision.");

    addPrerequisite("level",
        (["type":"level",
            "guild": "aquamancer",
            "value": 9
        ]));

    addPrerequisite("/guilds/aquamancer/water/scalding-blast.c",
        (["type":"research"]));

    addSpecification("research type", "points");
    addSpecification("research cost", 1);
    addSpecification("affected research", ([
        "Scalding Blast": 25,
        "Boiling Convergence": 25,
        "Tsunami": 25,
        "Corrosive Spray": 25,
    ]));
    addSpecification("affected research type", "percentage");
}
