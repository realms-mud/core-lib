//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/persistedActiveResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Void Blade");
    addSpecification("source", "Drambor Edlothiad");
    addSpecification("description", "This research allows the battlemage to "
        "channel the emptiness of the void through their blade, each strike "
        "tearing at the fabric of reality.");

    addPrerequisite(
        "/guilds/drambor-edlothiad/elemental/shadow-mastery.c",
        (["type": "research"]));
    addPrerequisite("level",
        (["type": "level",
            "guild": "Drambor Edlothiad",
            "value": 37
        ]));

    addSpecification("limited by", (["equipment": ({ "long sword",
            "hand and a half sword",
            "two-handed sword", "short sword",
            "dagger" }) ]));

    addSpecification("scope", "self");
    addSpecification("research type", "points");
    addSpecification("research cost", 1);
    addSpecification("spell point cost", 80);
    addSpecification("stamina point cost", 35);
    addSpecification("cooldown", 180);
    addSpecification("duration", 120);
    addSpecification("bonus shadow enchantment", 10);
    addSpecification("bonus shadow attack", 10);

    addSpecification("modifiers", ({
        (["type": "research",
            "research item": 
                "/guilds/drambor-edlothiad/elemental/shadow-mastery.c",
            "name": "shadow-mastery",
            "formula": "multiplicative",
            "base value": 1,
            "rate": 1.25]),
        (["type": "skill",
            "name": "spellcraft",
            "formula": "logarithmic",
            "rate": 1.25]),
        (["type": "skill",
            "name": "magical essence",
            "formula": "logarithmic",
            "rate": 1.25]),
        (["type": "level",
            "name": "Drambor Edlothiad",
            "formula": "logarithmic",
            "rate": 1.10]),
        (["type": "attribute",
            "name": "intelligence",
            "formula": "additive",
            "rate": 0.05]),
    }));

    addSpecification("command template", "void blade");
    addSpecification("use ability message", "Reality tears along the edge of "
        "##InitiatorPossessive## blade as void energy wells forth from "
            "within.");
}
