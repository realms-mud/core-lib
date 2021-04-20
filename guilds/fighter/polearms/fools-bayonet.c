//*****************************************************************************
// Copyright (c) 2021 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/knowledgeResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Fool's Bayonet");
    addSpecification("source", "fighter");
    addSpecification("description", "This skill provides the user with "
        "knowledge of a feint attack that enhances the fighter's "
        "combat abilities.");

    addPrerequisite("level",
        (["type":"level",
            "guild": "fighter",
            "value": 15
        ]));
    addPrerequisite("/guilds/fighter/polearms/forceful-thrust.c",
        (["type":"research"]));

    addSpecification("research type", "points");
    addSpecification("research cost", 1);
    addSpecification("affected research", ([
        "Skewer": 25,
        "Gash": 25,
        "Sweeping Strike": 25,
        "Impale": 25,
        "Gore": 25,
    ]));
    addSpecification("affected research type", "percentage");
}
