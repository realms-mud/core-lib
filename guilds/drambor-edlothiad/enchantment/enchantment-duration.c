//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved.
//                      See the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/passiveResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Enchantment Duration");
    addSpecification("source", "Drambor Edlothiad");
    addSpecification("description", "This research provides the "
        "user with techniques to extend the duration "
        "of blade enchantments. Through refined "
        "control over the binding of elemental "
        "forces to steel, the battlemage learns to "
        "anchor enchantments more deeply into the "
        "weapon's essence, allowing them to persist "
        "far longer than a novice could achieve.");

    addPrerequisite(
        "/guilds/drambor-edlothiad/enchantment/"
        "enchantment-efficiency.c",
        (["type": "research"]));
    addPrerequisite("level",
        (["type": "level",
            "guild": "Drambor Edlothiad",
            "value": 11
        ]));

    addSpecification("scope", "self");
    addSpecification("research type", "points");
    addSpecification("research cost", 1);
    addSpecification("bonus spellcraft", 3);
}
