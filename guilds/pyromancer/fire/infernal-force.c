//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/knowledgeResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Infernal Force");
    addSpecification("source", "pyromancer");
    addSpecification("description", "This research provides the user with "
        "knowledge of channeling infernal power into their fire spells, "
        "enhancing area-effect attacks.");

    addPrerequisite("level",
        (["type":"level",
            "guild": "pyromancer",
            "value": 11
        ]));

    addPrerequisite("/guilds/pyromancer/fire/firestorm.c",
        (["type":"research"]));

    addSpecification("research type", "points");
    addSpecification("research cost", 1);
    addSpecification("affected research", ([
        "Firestorm": 25,
        "Inferno": 25,
        "Volcanic Call": 25,
        "Great Inferno": 25,
        "Disrupt Inferno": 25,
    ]));
    addSpecification("affected research type", "percentage");
}
