//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/knowledgeResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Arcane Amplification");
    addSpecification("source", "Drambor Edlothiad");
    addSpecification("description", "This research deepens the battlemage's "
        "ability to channel raw energy, enhancing all force-based blade "
        "enchantments.");

    addPrerequisite(
        "/guilds/drambor-edlothiad/elemental/force-brand.c",
        (["type": "research"]));
    addPrerequisite("level",
        (["type": "level",
            "guild": "Drambor Edlothiad",
            "value": 19
        ]));

    addSpecification("research type", "points");
    addSpecification("research cost", 1);
    addSpecification("affected research", ([
        "Energy Edge": 25,
        "Force Brand": 25,
        "Resonance Blade": 25,
        "Annihilation Edge": 25,
    ]));
    addSpecification("affected research type", "percentage");
}
