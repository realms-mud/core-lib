//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/knowledgeResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Pyretic Flow");
    addSpecification("source", "pyromancer");
    addSpecification("description", "This research provides the user with "
        "mastery of the flow of fire energy, enhancing all fire spells.");

    addPrerequisite("level",
        (["type":"level",
            "guild": "pyromancer",
            "value": 33
        ]));

    addPrerequisite("/guilds/pyromancer/fire/fire-channeling.c",
        (["type":"research"]));

    addSpecification("research type", "points");
    addSpecification("research cost", 1);
    addSpecification("affected research", ([
        "Spark": 25,
        "Firestorm": 25,
        "Eruption": 25,
        "Heart of the Flame": 25,
    ]));
    addSpecification("affected research type", "percentage");
}
