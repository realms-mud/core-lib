//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/knowledgeResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Bludgeoner's Call");
    addSpecification("source", "fighter");
    addSpecification("description", "This skill provides the user with the "
        "knowledge to decrease the stamina cost for which they can use their "
        "blunt weapon attack abilities.");

    addPrerequisite("level",
        (["type":"level",
            "guild": "fighter",
            "value": 21
        ]));
    addPrerequisite("/guilds/fighter/bludgeon/bludgeoners-reserve.c",
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
    addSpecification("affected research type", "decrease cost");
}
