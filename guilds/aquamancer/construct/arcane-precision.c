//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/knowledgeResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Arcane Precision");
    addSpecification("source", "aquamancer");
    addSpecification("description", "This research teaches the aquamancer to "
        "channel magical energy with surgical precision, maximizing the "
        "effectiveness of every constructed spell.");

    addPrerequisite("level",
        (["type":"level",
            "guild": "aquamancer",
            "value": 41
        ]));
    addPrerequisite("/guilds/aquamancer/construct/spell-mastery.c",
        (["type":"research"]));

    addSpecification("research type", "points");
    addSpecification("research cost", 1);
    addSpecification("affected research", ([
        "Constructed Aquamancer Spells": 15,
    ]));
    addSpecification("affected research type", "percentage");
}
