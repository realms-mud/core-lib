//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/knowledgeResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Arcane Precision");
    addSpecification("source", "aeromancer");
    addSpecification("description", "This research grants the aeromancer "
        "extraordinary precision in channeling magical energy, ensuring that "
        "every aspect of their constructed spells achieves maximum impact.");

    addPrerequisite("level",
        (["type":"level",
            "guild": "aeromancer",
            "value": 41
        ]));
    addPrerequisite("/guilds/aeromancer/construct/spell-mastery.c",
        (["type":"research"]));

    addSpecification("research type", "points");
    addSpecification("research cost", 1);
    addSpecification("affected research", ([
        "Constructed Aeromancer Spells": 15,
    ]));
    addSpecification("affected research type", "percentage");
}
