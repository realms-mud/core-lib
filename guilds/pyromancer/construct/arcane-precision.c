//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/knowledgeResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Arcane Precision");
    addSpecification("source", "pyromancer");
    addSpecification("description", "This research teaches the pyromancer "
        "arcane precision when constructing spells, resulting in more potent effects.");

    addPrerequisite("level",
        (["type":"level",
            "guild": "pyromancer",
            "value": 41
        ]));
    addPrerequisite("/guilds/pyromancer/construct/spell-mastery.c",
        (["type":"research"]));

    addSpecification("research type", "points");
    addSpecification("research cost", 1);
    addSpecification("affected research", ([
        "Constructed Pyromancer Spells": 15,
    ]));
    addSpecification("affected research type", "percentage");
}
