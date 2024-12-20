//*****************************************************************************
// Copyright (c) 2025 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/knowledgeResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Polemaster's Boon");
    addSpecification("source", "fighter");
    addSpecification("description", "This skill provides the user with the "
        "knowledge to increase the speed with which they can use their "
        "polearm combat abilities.");

    addPrerequisite("level",
        (["type":"level",
            "guild": "fighter",
            "value": 7
        ]));
    addPrerequisite("/guilds/fighter/polearms/skewer.c",
        (["type":"research"]));

    addSpecification("research type", "points");
    addSpecification("research cost", 1);
    addSpecification("affected research", ([
        "Skewer": 5,
        "Gash": 5,
        "Sweeping Strike": 10,
        "Impale": 10,
        "Gore": 10,
    ]));
    addSpecification("affected research type", "decrease cooldown");
}
