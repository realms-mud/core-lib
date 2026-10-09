//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/persistedActiveResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Resonance Blade");
    addSpecification("source", "Drambor Edlothiad");
    addSpecification("description", "This research allows the battlemage to "
        "attune their blade to a resonant frequency of arcane energy, "
        "creating devastating harmonic vibrations on impact.");

    addPrerequisite(
        "/guilds/drambor-edlothiad/elemental/arcane-amplification.c",
        (["type": "research"]));
    addPrerequisite("level",
        (["type": "level",
            "guild": "Drambor Edlothiad",
            "value": 31
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
    addSpecification("bonus energy enchantment", 10);
    addSpecification("bonus energy attack", 10);

    addSpecification("modifiers", ({
        (["type": "research",
            "research item": 
                "/guilds/drambor-edlothiad/elemental/arcane-amplification.c",
            "name": "arcane-amplification",
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

    addSpecification("command template", "resonance blade");
    addSpecification("use ability message", "##InitiatorPossessive::Name## "
        "blade hums with resonant arcane energy, vibrating at a devastating "
            "frequency.");
}
