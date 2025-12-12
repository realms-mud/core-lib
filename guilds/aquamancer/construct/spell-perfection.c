//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/knowledgeResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Spell Perfection");
    addSpecification("source", "aquamancer");
    addSpecification("description", "This research represents the absolute "
        "pinnacle of spell construction. The aquamancer has achieved perfection "
        "in the art, their constructed spells reaching the theoretical maximum "
        "of magical potential.");

    addPrerequisite("level",
        (["type":"level",
            "guild": "aquamancer",
            "value": 49
        ]));
    addPrerequisite("/guilds/aquamancer/construct/arcane-precision.c",
        (["type":"research"]));

    addSpecification("research type", "points");
    addSpecification("research cost", 1);
    addSpecification("affected research", ([
        "Constructed Aquamancer Spells": 20,
    ]));
    addSpecification("affected research type", "percentage");
}
