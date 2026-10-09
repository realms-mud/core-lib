//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/persistedActiveResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Voltaic Enchantment");
    addSpecification("source", "Drambor Edlothiad");
    addSpecification("description", "This research provides the knowledge to "
        "channel powerful lightning into a wielded blade.");

    addPrerequisite(
        "/guilds/drambor-edlothiad/enchantment/lightning-enchantment.c",
        (["type": "research"]));
    addPrerequisite("level",
        (["type": "level",
            "guild": "Drambor Edlothiad",
            "value": 7
        ]));

    addSpecification("limited by", (["equipment":
        ({ "long sword", "hand and a half sword",
            "two-handed sword", "short sword",
            "dagger" }) ]));

    addSpecification("scope", "self");
    addSpecification("research type", "points");
    addSpecification("research cost", 1);
    addSpecification("spell point cost", 50);
    addSpecification("stamina point cost", 15);
    addSpecification("cooldown", 120);
    addSpecification("duration", 100);
    addSpecification("bonus electricity enchantment", 5);

    addSpecification("modifiers", ({
        (["type": "skill",
            "name": "elemental air",
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
        "Arcs of voltaic power crackle along ##InitiatorPossessive## blade.");
}
