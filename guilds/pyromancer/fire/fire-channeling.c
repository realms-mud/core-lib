//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/knowledgeResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Fire Channeling");
    addSpecification("source", "pyromancer");
    addSpecification("description", "This research provides the user with "
        "advanced knowledge of channeling fire energy, enhancing all fire spells.");

    addPrerequisite("level",
        (["type":"level",
            "guild": "pyromancer",
            "value": 25
        ]));

    addPrerequisite("/guilds/pyromancer/fire/fire-mastery.c",
        (["type":"research"]));

    addSpecification("research type", "points");
    addSpecification("research cost", 1);
    addSpecification("affected research", ([
        "Spark": 25,
        "Firestorm": 25,
        "Heat Wave": 25,
        "Flame Pillar": 25,
        "Conflagration": 25,
        "Backdraft": 25,
        "Eruption": 25,
        "Daggers of Fire": 25,
    ]));
    addSpecification("affected research type", "percentage");
}
