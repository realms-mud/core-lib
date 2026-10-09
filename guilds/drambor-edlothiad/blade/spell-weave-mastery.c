//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/knowledgeResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Spell Weave Mastery");
    addSpecification("source", "Drambor Edlothiad");
    addSpecification("description", "This research represents the "
        "battlemage's complete mastery of spell weaving, allowing arcane "
        "energy to flow seamlessly through blade techniques with minimal "
        "effort and maximum devastation.");

    addPrerequisite(
        "/guilds/drambor-edlothiad/blade/spell-weave.c",
        (["type": "research"]));
    addPrerequisite("level",
        (["type": "level",
            "guild": "Drambor Edlothiad",
            "value": 21
        ]));

    addSpecification("research type", "points");
    addSpecification("research cost", 1);
    addSpecification("affected research", ([
        "Mana Strike": 35,
        "Arcane Slash": 35,
        "Runic Blade": 35,
        "Spellstorm Strike": 35,
        "Arcane Annihilation": 35,
    ]));
    addSpecification("affected research type", "percentage");
}
