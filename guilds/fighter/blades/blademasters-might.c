//*****************************************************************************
// Copyright (c) 2021 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/knowledgeResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Blademaster's Might");
    addSpecification("source", "fighter");
    addSpecification("description", "This skill provides the user with the "
        "knowledge to decrease the stamina cost for which they can use their "
        "blade attack abilities.");

    addPrerequisite("level",
        (["type":"level",
            "guild": "fighter",
            "value": 31
        ]));
    addPrerequisite("guilds/fighter/blades/blademasters-call.c",
        (["type":"research"]));

    addSpecification("research type", "points");
    addSpecification("research cost", 1);
    addSpecification("affected research", ([
        "Slash": 5,
        "Thrust": 5,
        "Whirlwind": 10,
        "Cleave": 10,
        "Piercing Strike": 10,
    ]));
    addSpecification("affected research type", "decrease cost");
}
