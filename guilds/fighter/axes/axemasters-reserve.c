//*****************************************************************************
// Copyright (c) 2024 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/knowledgeResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Axemaster's Reserve");
    addSpecification("source", "fighter");
    addSpecification("description", "This skill provides the user with the "
        "knowledge to decrease the stamina cost for which they can use their "
        "axe attack abilities.");

    addPrerequisite("level",
        (["type":"level",
            "guild": "fighter",
            "value": 11
        ]));
    addPrerequisite("/guilds/fighter/axes/chop.c",
        (["type":"research"]));

    addSpecification("research type", "points");
    addSpecification("research cost", 1);
    addSpecification("affected research", ([
        "Chop": 5,
        "Thrash": 5,
        "Sweeping Hew": 10,
        "Hack": 10,
        "Punishing Hack": 10,
    ]));
    addSpecification("affected research type", "decrease cost");
}
