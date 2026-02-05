//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/knowledgeResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Spell Perfection");
    addSpecification("source", "pyromancer");
    addSpecification("description", "This research teaches the pyromancer "
        "perfection when constructing spells, resulting in the most potent effects.");

    addPrerequisite("level",
        (["type":"level",
            "guild": "pyromancer",
            "value": 49
        ]));
    addPrerequisite("/guilds/pyromancer/construct/arcane-precision.c",
        (["type":"research"]));

    addSpecification("research type", "points");
    addSpecification("research cost", 1);
    addSpecification("affected research", ([
        "Constructed Pyromancer Spells": 20,
    ]));
    addSpecification("affected research type", "percentage");
}
