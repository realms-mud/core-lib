//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/passiveResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Dual Attunement");
    addSpecification("source", "Drambor Edlothiad");
    addSpecification("description", "This research allows the enchanter to "
        "maintain enchantments with greater "
        "ease.");

    addPrerequisite(
        "/guilds/drambor-edlothiad/enchantment/enchantment-duration.c",
        (["type": "research"]));
    addPrerequisite("level",
        (["type": "level",
            "guild": "Drambor Edlothiad",
            "value": 13
        ]));

    addSpecification("scope", "self");
    addSpecification("research type", "points");
    addSpecification("research cost", 1);
    addSpecification("bonus spell points", 25);
    addSpecification("bonus intelligence", 1);
}
