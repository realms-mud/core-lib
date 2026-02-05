//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/knowledgeResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Heart of the Flame");
    addSpecification("source", "pyromancer");
    addSpecification("description", "This research provides the user with "
        "knowledge of the true heart of fire, greatly enhancing fire magic.");

    addPrerequisite("level",
        (["type":"level",
            "guild": "pyromancer",
            "value": 39
        ]));

    addPrerequisite("/guilds/pyromancer/fire/pyretic-flow.c",
        (["type":"research"]));

    addSpecification("research type", "points");
    addSpecification("research cost", 1);
    addSpecification("affected research", ([
        "Spark": 25,
        "Elemental Ignition": 25,
        "Inferno Mastery": 25,
    ]));
    addSpecification("affected research type", "percentage");
}
