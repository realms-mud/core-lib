//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/knowledgeResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Elemental Ignition");
    addSpecification("source", "pyromancer");
    addSpecification("description", "This research provides the user with "
        "mastery of elemental ignition, greatly enhancing fire magic.");

    addPrerequisite("level",
        (["type":"level",
            "guild": "pyromancer",
            "value": 45
        ]));

    addPrerequisite("/guilds/pyromancer/fire/heart-of-the-flame.c",
        (["type":"research"]));

    addSpecification("research type", "points");
    addSpecification("research cost", 1);
    addSpecification("affected research", ([
        "Spark": 25,
        "Inferno Mastery": 25,
        "Pyromantic Insight": 25,
    ]));
    addSpecification("affected research type", "percentage");
}
