//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/knowledgeResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Expert Efficiency");
    addSpecification("source", "aquamancer");
    addSpecification("description", "This skill provides the user with expert "
        "knowledge to dramatically increase the speed with which they can cast "
        "their constructed spells.");

    addPrerequisite("level",
        (["type":"level",
            "guild": "aquamancer",
            "value": 21
        ]));
    addPrerequisite("/guilds/aquamancer/construct/improved-efficiency.c",
        (["type":"research"]));

    addSpecification("research type", "points");
    addSpecification("research cost", 1);
    addSpecification("affected research", ([
        "Constructed Aquamancer Spells": 10,
    ]));
    addSpecification("affected research type", "decrease cooldown");
}
