//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/knowledgeResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Volcanic Call");
    addSpecification("source", "pyromancer");
    addSpecification("description", "This research provides the user with "
        "knowledge of calling upon volcanic forces to enhance their spells.");

    addPrerequisite("level",
        (["type":"level",
            "guild": "pyromancer",
            "value": 19
        ]));

    addPrerequisite("/guilds/pyromancer/fire/infernal-force.c",
        (["type":"research"]));

    addSpecification("research type", "points");
    addSpecification("research cost", 1);
    addSpecification("affected research", ([
        "Firestorm": 25,
        "Inferno": 25,
        "Great Inferno": 25,
        "Eruption": 25,
    ]));
    addSpecification("affected research type", "percentage");
}
