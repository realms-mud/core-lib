//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved.
//                      See the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/passiveResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Enchantment Mastery");
    addSpecification("source", "Drambor Edlothiad");
    addSpecification("description", "This research provides the "
        "user with true mastery of the enchanting "
        "arts. Years of practice have refined the "
        "battlemage's ability to imbue weapons with "
        "elemental power, resulting in enchantments "
        "that burn brighter, bite deeper, and "
        "resonate with greater potency than those "
        "of lesser practitioners.");

    addPrerequisite(
        "/guilds/drambor-edlothiad/enchantment/"
        "enchantment-duration.c",
        (["type": "research"]));
    addPrerequisite("level",
        (["type": "level",
            "guild": "Drambor Edlothiad",
            "value": 25
        ]));

    addSpecification("scope", "self");
    addSpecification("research type", "points");
    addSpecification("research cost", 1);
    addSpecification("bonus spellcraft", 5);
    addSpecification("bonus elemental fire", 2);
    addSpecification("bonus elemental water", 2);
    addSpecification("bonus elemental air", 2);
}
