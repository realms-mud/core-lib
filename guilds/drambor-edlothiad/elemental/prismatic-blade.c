//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/persistedActiveResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Prismatic Blade");
    addSpecification("source", "Drambor Edlothiad");
    addSpecification("description", "This research allows the battlemage to "
        "infuse their blade with prismatic energy, cycling through multiple "
        "elemental types simultaneously for devastating effect.");

    addPrerequisite(
        "/guilds/drambor-edlothiad/elemental/elemental-transcendence.c",
        (["type": "research"]));
    addPrerequisite("level",
        (["type": "level",
            "guild": "Drambor Edlothiad",
            "value": 59
        ]));

    addSpecification("limited by", (["equipment": ({ "long sword",
            "hand and a half sword",
            "two-handed sword", "short sword",
            "dagger" }) ]));

    addSpecification("scope", "self");
    addSpecification("research type", "points");
    addSpecification("research cost", 1);
    addSpecification("spell point cost", 150);
    addSpecification("stamina point cost", 75);
    addSpecification("cooldown", 240);
    addSpecification("duration", 150);

    addSpecification("bonus fire enchantment", 5);
    addSpecification("bonus cold enchantment", 5);
    addSpecification("bonus electricity enchantment", 5);
    addSpecification("bonus acid enchantment", 5);
    addSpecification("bonus energy enchantment", 5);

    addSpecification("modifiers", ({
        (["type": "research",
            "research item": 
                "/guilds/drambor-edlothiad/elemental/elemental-supremacy.c",
            "name": "elemental-supremacy",
            "formula": "multiplicative",
            "base value": 1,
            "rate": 1.25]),
        (["type": "skill",
            "name": "spellcraft",
            "formula": "logarithmic",
            "rate": 1.50]),
        (["type": "skill",
            "name": "magical essence",
            "formula": "logarithmic",
            "rate": 1.50]),
        (["type": "level",
            "name": "Drambor Edlothiad",
            "formula": "logarithmic",
            "rate": 1.15]),
        (["type": "attribute",
            "name": "intelligence",
            "formula": "additive",
            "rate": 0.10]),
    }));

    addSpecification("command template", "prismatic blade");
    addSpecification("use ability message", "##InitiatorPossessive::Name## "
        "blade erupts in a cascade of prismatic energy, cycling through "
            "fire, "
        "ice, lightning, acid, and pure force in a dazzling display.");
}
