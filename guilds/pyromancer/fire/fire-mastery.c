//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/knowledgeResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Fire Mastery");
    addSpecification("source", "pyromancer");
    addSpecification("description", "This research provides the user with "
        "mastery over fire magic, enhancing all fire-based attacks.");

    addPrerequisite("level",
        (["type":"level",
            "guild": "pyromancer",
            "value": 19
        ]));

    addPrerequisite("/guilds/pyromancer/fire/firestorm.c",
        (["type":"research"]));

    addSpecification("research type", "points");
    addSpecification("research cost", 1);
    addSpecification("affected research", ([
        "Spark": 25,
        "Ember": 25,
        "Searing Blast": 25,
        "Smoke Screen": 25,
        "Burning Grasp": 25,
        "Firestorm": 25,
        "Heat Wave": 25,
        "Talons of Fire": 25,
        "Ash Cloud": 25,
        "Battering Flames": 25,
        "Inferno": 25,
        "Flame Pillar": 25,
        "Conflagration": 25,
        "Burning Touch": 25,
    ]));
    addSpecification("affected research type", "percentage");
}
