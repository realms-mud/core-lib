//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/knowledgeResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Spell Weave");
    addSpecification("source", "Drambor Edlothiad");
    addSpecification("description", "This research deepens the battlemage's "
        "ability to weave spells into blade techniques, enhancing all "
        "active spellblade abilities.");

    addPrerequisite(
        "/guilds/drambor-edlothiad/blade/arcane-slash.c",
        (["type": "research"]));
    addPrerequisite("level",
        (["type": "level",
            "guild": "Drambor Edlothiad",
            "value": 9
        ]));

    addSpecification("research type", "points");
    addSpecification("research cost", 1);
    addSpecification("affected research", ([
        "Mana Strike": 25,
        "Arcane Slash": 25,
        "Runic Blade": 25,
        "Spellstorm Strike": 25,
        "Arcane Annihilation": 25,
    ]));
    addSpecification("affected research type", "percentage");
}
