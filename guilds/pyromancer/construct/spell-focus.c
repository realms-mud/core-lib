//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/knowledgeResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Spell Focus");
    addSpecification("source", "pyromancer");
    addSpecification("description", "This research teaches the pyromancer to "
        "focus their magical energy more precisely when constructing spells, "
        "resulting in more potent effects.");

    addPrerequisite("level",
        (["type":"level",
            "guild": "pyromancer",
            "value": 9
        ]));
    addPrerequisite("/guilds/pyromancer/construct/efficient-casting.c",
        (["type":"research"]));

    addSpecification("research type", "points");
    addSpecification("research cost", 1);
    addSpecification("affected research", ([
        "Constructed Pyromancer Spells": 15,
    ]));
    addSpecification("affected research type", "percentage");
}
