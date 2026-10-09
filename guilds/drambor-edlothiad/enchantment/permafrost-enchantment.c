//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/persistedActiveResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Permafrost Enchantment");
    addSpecification("source", "Drambor Edlothiad");
    addSpecification("description", "This research provides the knowledge to "
        "encase a wielded blade in unmelting ice.");

    addPrerequisite(
        "/guilds/drambor-edlothiad/enchantment/glacial-enchantment.c",
        (["type": "research"]));
    addPrerequisite("level",
        (["type": "level",
            "guild": "Drambor Edlothiad",
            "value": 15
        ]));

    addSpecification("limited by", (["equipment":
        ({ "long sword", "hand and a half sword",
            "two-handed sword", "short sword",
            "dagger" }) ]));

    addSpecification("scope", "self");
    addSpecification("research type", "points");
    addSpecification("research cost", 1);
    addSpecification("spell point cost", 70);
    addSpecification("stamina point cost", 20);
    addSpecification("cooldown", 120);
    addSpecification("duration", 110);
    addSpecification("bonus cold enchantment", 8);

    addSpecification("modifiers", ({
        (["type": "skill",
            "name": "elemental water",
            "formula": "additive",
            "rate": 0.10]),
        (["type": "skill",
            "name": "spellcraft",
            "formula": "logarithmic",
            "rate": 1.25]),
        (["type": "level",
            "name": "Drambor Edlothiad",
            "formula": "logarithmic",
            "rate": 1.05]),
        (["type": "attribute",
            "name": "intelligence",
            "formula": "additive",
            "rate": 0.05]),
    }));

    
    addSpecification("use ability message",
        "Unmelting ice encases ##InitiatorPossessive## blade, freezing the "
            "air.");
}
