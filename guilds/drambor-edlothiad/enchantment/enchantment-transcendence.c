//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/passiveResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Enchantment Transcendence");
    addSpecification("source", "Drambor Edlothiad");
    addSpecification("description", "This research represents the ultimate "
        "mastery of blade enchantment, the "
        "pinnacle of Drambor tradition.");

    addPrerequisite(
        "/guilds/drambor-edlothiad/enchantment/arcane-imbuer.c",
        (["type": "research"]));
    addPrerequisite("level",
        (["type": "level",
            "guild": "Drambor Edlothiad",
            "value": 70
        ]));

    addSpecification("scope", "self");
    addSpecification("research type", "points");
    addSpecification("research cost", 1);
    addSpecification("bonus spellcraft", 12);
    addSpecification("bonus intelligence", 4);
    addSpecification("bonus spell points", 100);
    addSpecification("bonus attack", 3);
}
