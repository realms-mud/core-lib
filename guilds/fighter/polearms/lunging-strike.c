//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/knowledgeResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "lunging Strike");
    addSpecification("source", "fighter");
    addSpecification("description", "This skill provides the user with "
        "knowledge that enhances the fighter's combat abilities.");

    addPrerequisite("level",
        (["type":"level",
            "guild": "fighter",
            "value": 57
        ]));
    addPrerequisite("/guilds/fighter/polearms/slicing-stroke.c",
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
