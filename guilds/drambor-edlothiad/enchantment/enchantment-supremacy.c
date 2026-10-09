//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved.
//                      See the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/passiveResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Enchantment Supremacy");
    addSpecification("source", "Drambor Edlothiad");
    addSpecification("description", "This research provides the "
        "user with the pinnacle of enchantment "
        "knowledge. The battlemage's understanding "
        "of elemental binding reaches such heights "
        "that every enchantment cast is imbued with "
        "devastating force, transforming even a "
        "simple blade into an instrument of "
        "elemental annihilation.");

    addPrerequisite(
        "/guilds/drambor-edlothiad/enchantment/"
        "enchantment-mastery.c",
        (["type": "research"]));
    addPrerequisite("level",
        (["type": "level",
            "guild": "Drambor Edlothiad",
            "value": 45
        ]));

    addSpecification("scope", "self");
    addSpecification("research type", "points");
    addSpecification("research cost", 1);
    addSpecification("bonus spellcraft", 7);
    addSpecification("bonus elemental fire", 3);
    addSpecification("bonus elemental water", 3);
    addSpecification("bonus elemental air", 3);
    addSpecification("bonus elemental earth", 3);
}
