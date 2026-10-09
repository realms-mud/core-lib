//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/knowledgeResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Conductivity");
    addSpecification("source", "Drambor Edlothiad");
    addSpecification("description", "This research deepens the battlemage's "
        "understanding of electrical channeling, enhancing all "
            "lightning-based "
        "blade enchantments.");

    addPrerequisite(
        "/guilds/drambor-edlothiad/elemental/voltaic-brand.c",
        (["type": "research"]));
    addPrerequisite("level",
        (["type": "level",
            "guild": "Drambor Edlothiad",
            "value": 15
        ]));

    addSpecification("research type", "points");
    addSpecification("research cost", 1);
    addSpecification("affected research", ([
        "Shock Edge": 25,
        "Voltaic Brand": 25,
        "Thunderstrike": 25,
        "Storm Conduit": 25,
    ]));
    addSpecification("affected research type", "percentage");
}
