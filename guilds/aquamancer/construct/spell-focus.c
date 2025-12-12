//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/knowledgeResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Spell Focus");
    addSpecification("source", "aquamancer");
    addSpecification("description", "This research teaches the aquamancer to "
        "focus their magical energy more precisely when constructing spells, "
        "resulting in more potent effects.");

    addPrerequisite("level",
        (["type":"level",
            "guild": "aquamancer",
            "value": 9
        ]));
    addPrerequisite("/guilds/aquamancer/construct/efficient-casting.c",
        (["type":"research"]));

    addSpecification("research type", "points");
    addSpecification("research cost", 1);
    addSpecification("affected research", ([
        "Constructed Aquamancer Spells": 15,
    ]));
    addSpecification("affected research type", "percentage");
}
