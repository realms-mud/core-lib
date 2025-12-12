//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/knowledgeResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Spell Mastery");
    addSpecification("source", "aquamancer");
    addSpecification("description", "This research represents mastery over the "
        "art of spell construction. The aquamancer's constructed spells reach "
        "new heights of power and precision.");

    addPrerequisite("level",
        (["type":"level",
            "guild": "aquamancer",
            "value": 33
        ]));
    addPrerequisite("/guilds/aquamancer/construct/spell-amplification.c",
        (["type":"research"]));

    addSpecification("research type", "points");
    addSpecification("research cost", 1);
    addSpecification("affected research", ([
        "Constructed Aquamancer Spells": 15,
    ]));
    addSpecification("affected research type", "percentage");
}
