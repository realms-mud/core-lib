//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/knowledgeResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Arcane Focus");
    addSpecification("source", "Drambor Edlothiad");
    addSpecification("description", "This research deepens the battlemage's "
        "ability to channel pure magical energy, enhancing all arcane blade "
        "enchantments.");

    addPrerequisite(
        "/guilds/drambor-edlothiad/elemental/mystic-brand.c",
        (["type": "research"]));
    addPrerequisite("level",
        (["type": "level",
            "guild": "Drambor Edlothiad",
            "value": 19
        ]));

    addSpecification("research type", "points");
    addSpecification("research cost", 1);
    addSpecification("affected research", ([
        "Arcane Edge": 25,
        "Mystic Brand": 25,
        "Eldritch Blade": 25,
        "Transcendence Edge": 25,
    ]));
    addSpecification("affected research type", "percentage");
}
