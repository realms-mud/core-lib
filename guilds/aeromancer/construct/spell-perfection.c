//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/knowledgeResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Spell Perfection");
    addSpecification("source", "aeromancer");
    addSpecification("description", "This research represents the pinnacle of "
        "spell construction knowledge. The aeromancer has achieved perfect "
        "understanding of how to weave magical components together, resulting "
        "in constructed spells of unparalleled power.");

    addPrerequisite("level",
        (["type":"level",
            "guild": "aeromancer",
            "value": 49
        ]));
    addPrerequisite("/guilds/aeromancer/construct/arcane-precision.c",
        (["type":"research"]));

    addSpecification("research type", "points");
    addSpecification("research cost", 1);
    addSpecification("affected research", ([
        "Constructed Aeromancer Spells": 20,
    ]));
    addSpecification("affected research type", "percentage");
}
