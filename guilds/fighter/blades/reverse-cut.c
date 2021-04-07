//*****************************************************************************
// Copyright (c) 2021 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/knowledgeResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Reverse Cut");
    addSpecification("source", "fighter");
    addSpecification("description", "This skill provides the user with "
        "knowledge that enhances the fighter's combat abilities.");

    addPrerequisite("level",
        (["type":"level",
            "guild": "fighter",
            "value": 15
        ]));
    addPrerequisite("guilds/fighter/blades/under-cutting.c",
        (["type":"research"]));

    addSpecification("research type", "points");
    addSpecification("research cost", 1);
    addSpecification("affected research", ([
        "Slash": 25,
        "Thrust": 25,
        "Whirlwind": 25,
        "Cleave": 25,
        "Piercing Strike": 25,
    ]));
    addSpecification("affected research type", "percentage");
}
