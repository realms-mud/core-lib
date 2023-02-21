//*****************************************************************************
// Copyright (c) 2023 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/knowledgeResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Shieldmaster's Might");
    addSpecification("source", "fighter");
    addSpecification("description", "This skill provides the user with the "
        "knowledge to decrease the stamina cost for which they can use their "
        "axe attack abilities.");

    addPrerequisite("level",
        (["type":"level",
            "guild": "fighter",
            "value": 31
        ]));
    addPrerequisite("/guilds/fighter/shields/shieldmasters-call.c",
        (["type":"research"]));

    addSpecification("research type", "points");
    addSpecification("research cost", 1);
    addSpecification("affected research", ([
        "Shield Bash": 5,
        "Shield Strike": 10,
    ]));
    addSpecification("affected research type", "decrease cost");
}
