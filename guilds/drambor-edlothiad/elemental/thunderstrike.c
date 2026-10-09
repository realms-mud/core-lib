//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/persistedActiveResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Thunderstrike");
    addSpecification("source", "Drambor Edlothiad");
    addSpecification("description", "This research allows the battlemage to "
        "unleash devastating thunderous energy through their blade, "
        "each strike resonating with the power of a lightning bolt.");

    addPrerequisite(
        "/guilds/drambor-edlothiad/elemental/conductivity.c",
        (["type": "research"]));
    addPrerequisite("level",
        (["type": "level",
            "guild": "Drambor Edlothiad",
            "value": 27
        ]));

    addSpecification("limited by", (["equipment": ({ "long sword",
            "hand and a half sword",
            "two-handed sword", "short sword",
            "dagger" }) ]));

    addSpecification("scope", "self");
    addSpecification("research type", "points");
    addSpecification("research cost", 1);
    addSpecification("spell point cost", 75);
    addSpecification("stamina point cost", 35);
    addSpecification("cooldown", 180);
    addSpecification("duration", 120);
    addSpecification("bonus electricity enchantment", 10);
    addSpecification("bonus electricity attack", 10);

    addSpecification("modifiers", ({
        (["type": "research",
            "research item": 
                "/guilds/drambor-edlothiad/elemental/conductivity.c",
            "name": "conductivity",
            "formula": "multiplicative",
            "base value": 1,
            "rate": 1.25]),
        (["type": "skill",
            "name": "elemental air",
            "formula": "additive",
            "rate": 0.15]),
        (["type": "skill",
            "name": "spellcraft",
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

    addSpecification("command template", "thunderstrike");
    addSpecification("use ability message", "Thunder rolls as devastating "
        "lightning engulfs ##InitiatorPossessive## blade in blinding arcs.");
}
