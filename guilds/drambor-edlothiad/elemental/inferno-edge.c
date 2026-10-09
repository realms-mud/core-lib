//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/knowledgeResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Inferno Edge");
    addSpecification("source", "Drambor Edlothiad");
    addSpecification("description", "This research deepens the battlemage's "
        "understanding of fire channeling, enhancing all fire-based blade "
        "enchantments.");

    addPrerequisite(
        "/guilds/drambor-edlothiad/elemental/searing-brand.c",
        (["type": "research"]));
    addPrerequisite("level",
        (["type": "level",
            "guild": "Drambor Edlothiad",
            "value": 13
        ]));

    addSpecification("research type", "points");
    addSpecification("research cost", 1);
    addSpecification("affected research", ([
        "Flame Edge": 25,
        "Searing Brand": 25,
        "Blazing Vortex": 25,
        "Pyroclasm Edge": 25,
    ]));
    addSpecification("affected research type", "percentage");
}
