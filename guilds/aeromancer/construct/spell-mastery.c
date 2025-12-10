//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/knowledgeResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Spell Mastery");
    addSpecification("source", "aeromancer");
    addSpecification("description", "This research represents a deep mastery "
        "of spell construction principles. The aeromancer's understanding of "
        "magical energy flow allows them to create significantly more powerful "
        "constructed spells.");

    addPrerequisite("level",
        (["type":"level",
            "guild": "aeromancer",
            "value": 33
        ]));
    addPrerequisite("/guilds/aeromancer/construct/spell-amplification.c",
        (["type":"research"]));

    addSpecification("research type", "points");
    addSpecification("research cost", 1);
    addSpecification("affected research", ([
        "Constructed Aeromancer Spells": 15,
    ]));
    addSpecification("affected research type", "percentage");
}
