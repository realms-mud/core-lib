//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/knowledgeResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Frozen Depths");
    addSpecification("source", "aquamancer");
    addSpecification("description", "This research provides the user with "
        "mastery over extreme temperature manipulation within water. The "
        "aquamancer can now rapidly transition between scalding and freezing "
        "effects, maximizing thermal shock damage.");

    addPrerequisite("level",
        (["type":"level",
            "guild": "aquamancer",
            "value": 27
        ]));

    addPrerequisite("/guilds/aquamancer/water/boiling-convergence.c",
        (["type":"research"]));

    addSpecification("research type", "points");
    addSpecification("research cost", 1);
    addSpecification("affected research", ([
        "Scalding Blast": 25,
        "Tsunami": 25,
        "Crushing Tide": 25,
        "Mist Veil": 25,
    ]));
    addSpecification("affected research type", "percentage");
}
