//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/knowledgeResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Boiling Convergence");
    addSpecification("source", "aquamancer");
    addSpecification("description", "This research represents a breakthrough "
        "in the aquamancer's understanding of thermal manipulation. By learning "
        "to rapidly concentrate heat within water, they can create devastating "
        "scalding effects with greater efficiency.");

    addPrerequisite("level",
        (["type":"level",
            "guild": "aquamancer",
            "value": 17
        ]));

    addPrerequisite("/guilds/aquamancer/water/steamweaving.c",
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
