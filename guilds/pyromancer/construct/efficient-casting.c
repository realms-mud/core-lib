//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/knowledgeResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Efficient Casting");
    addSpecification("source", "pyromancer");
    addSpecification("description", "This skill provides the user with the "
        "knowledge to increase the speed with which they can cast their "
        "constructed spells.");

    addPrerequisite("level",
        (["type":"level",
            "guild": "pyromancer",
            "value": 5
        ]));
    addPrerequisite("/guilds/pyromancer/construct/root.c",
        (["type":"research"]));

    addSpecification("research type", "points");
    addSpecification("research cost", 1);
    addSpecification("affected research", ([
        "Constructed Pyromancer Spells": 10,
    ]));
    addSpecification("affected research type", "decrease cooldown");
}
