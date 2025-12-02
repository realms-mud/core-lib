//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/knowledgeResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Using the Edge");
    addSpecification("source", "fighter");
    addSpecification("description", "This skill provides the user with "
        "knowledge that enhances the fighter's abilities that use shields "
        "as offensive weapons.");

    addPrerequisite("level",
        (["type":"level",
            "guild": "fighter",
            "value": 21
        ]));
    addPrerequisite("/guilds/fighter/shields/reverse-sweep.c",
        (["type":"research"]));

    addSpecification("research type", "points");
    addSpecification("research cost", 1);
    addSpecification("affected research", ([
        "Shield Bash": 50,
        "Shield Strike": 50,
    ]));
    addSpecification("affected research type", "percentage");
}
