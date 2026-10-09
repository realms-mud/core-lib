//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/passiveResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Enchantment Potency");
    addSpecification("source", "Drambor Edlothiad");
    addSpecification("description", "This research deepens understanding of "
        "enchantment magic, increasing "
        "effectiveness.");

    addPrerequisite(
        "/guilds/drambor-edlothiad/enchantment/dual-attunement.c",
        (["type": "research"]));
    addPrerequisite("level",
        (["type": "level",
            "guild": "Drambor Edlothiad",
            "value": 21
        ]));

    addSpecification("scope", "self");
    addSpecification("research type", "points");
    addSpecification("research cost", 1);
    addSpecification("bonus spellcraft", 5);
    addSpecification("bonus intelligence", 1);
}
