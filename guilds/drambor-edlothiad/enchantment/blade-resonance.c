//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/passiveResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Blade Resonance");
    addSpecification("source", "Drambor Edlothiad");
    addSpecification("description", "This research creates a resonant bond "
        "between enchanter and blade.");

    addPrerequisite(
        "/guilds/drambor-edlothiad/enchantment/persistent-enchantments.c",
        (["type": "research"]));
    addPrerequisite("level",
        (["type": "level",
            "guild": "Drambor Edlothiad",
            "value": 45
        ]));

    addSpecification("scope", "self");
    addSpecification("research type", "points");
    addSpecification("research cost", 1);
    addSpecification("bonus attack", 3);
    addSpecification("bonus damage", 3);
    addSpecification("bonus spellcraft", 5);
}
