//*****************************************************************************
// Copyright (c) 2024 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/knowledgeResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Bludgeoner's Speed");
    addSpecification("source", "fighter");
    addSpecification("description", "This skill provides the user with the "
        "knowledge to increase the speed with which they can use their "
        "blunt weapon combat abilities.");

    addPrerequisite("level",
        (["type":"level",
            "guild": "fighter",
            "value": 17
        ]));
    addPrerequisite("/guilds/fighter/bludgeon/bludgeoners-boon.c",
        (["type":"research"]));

    addSpecification("research type", "points");
    addSpecification("research cost", 1);
    addSpecification("affected research", ([
        "Pummel": 5,
        "Cudgel": 5,
        "Battering Arc": 10,
        "Crush": 10,
        "Crushing Strike": 10,
    ]));
    addSpecification("affected research type", "decrease cooldown");
}
