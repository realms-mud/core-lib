//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/knowledgeResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Shieldmaster's Endurance");
    addSpecification("source", "fighter");
    addSpecification("description", "This skill provides the user with the "
        "knowledge to increase the speed with which they can use their "
        "axe combat abilities.");

    addPrerequisite("level",
        (["type":"level",
            "guild": "fighter",
            "value": 27
        ]));
    addPrerequisite("/guilds/fighter/shields/shieldmasters-speed.c",
        (["type":"research"]));

    addSpecification("research type", "points");
    addSpecification("research cost", 1);
    addSpecification("affected research", ([
        "Shield Bash": 5,
        "Shield Strike": 10,
    ]));
    addSpecification("affected research type", "decrease cooldown");
}
