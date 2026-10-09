//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/persistedActiveResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Divine Storm");
    addSpecification("source", "Drambor Edlothiad");
    addSpecification("description", "This research provides the knowledge to "
        "channel divine lightning into a wielded blade.");

    addPrerequisite(
        "/guilds/drambor-edlothiad/enchantment/primordial-lightning.c",
        (["type": "research"]));
    addPrerequisite("level",
        (["type": "level",
            "guild": "Drambor Edlothiad",
            "value": 65
        ]));

    addSpecification("limited by", (["equipment":
        ({ "long sword", "hand and a half sword",
            "two-handed sword", "short sword",
            "dagger" }) ]));

    addSpecification("scope", "self");
    addSpecification("research type", "points");
    addSpecification("research cost", 1);
    addSpecification("spell point cost", 180);
    addSpecification("stamina point cost", 50);
    addSpecification("cooldown", 120);
    addSpecification("duration", 140);
    addSpecification("bonus electricity enchantment", 25);

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
        "Divine lightning crackles along ##InitiatorPossessive## blade.");
}
