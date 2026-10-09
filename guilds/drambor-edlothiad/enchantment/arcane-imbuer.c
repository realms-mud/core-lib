//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/passiveResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Arcane Imbuer");
    addSpecification("source", "Drambor Edlothiad");
    addSpecification("description", "This research allows the enchanter to "
        "imbue blades with unprecedented power.");

    addPrerequisite(
        "/guilds/drambor-edlothiad/enchantment/enchantment-supremacy.c",
        (["type": "research"]));
    addPrerequisite("level",
        (["type": "level",
            "guild": "Drambor Edlothiad",
            "value": 61
        ]));

    addSpecification("scope", "self");
    addSpecification("research type", "points");
    addSpecification("research cost", 1);
    addSpecification("bonus spellcraft", 8);
    addSpecification("bonus attack", 2);
    addSpecification("bonus damage", 5);
}
