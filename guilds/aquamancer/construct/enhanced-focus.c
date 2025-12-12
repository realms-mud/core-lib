//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/knowledgeResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Enhanced Focus");
    addSpecification("source", "aquamancer");
    addSpecification("description", "This research teaches the aquamancer "
        "advanced techniques for focusing their magical energy, resulting in "
        "significantly more powerful constructed spells.");

    addPrerequisite("level",
        (["type":"level",
            "guild": "aquamancer",
            "value": 17
        ]));
    addPrerequisite("/guilds/aquamancer/construct/spell-focus.c",
        (["type":"research"]));

    addSpecification("research type", "points");
    addSpecification("research cost", 1);
    addSpecification("affected research", ([
        "Constructed Aquamancer Spells": 15,
    ]));
    addSpecification("affected research type", "percentage");
}
