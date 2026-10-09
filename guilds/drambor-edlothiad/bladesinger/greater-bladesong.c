//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/persistedActiveResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Greater Bladesong");
    addSpecification("source", "Drambor Edlothiad");
    addSpecification("description", "This research provides the knowledge to "
        "perform a greater bladesong, a powerful fusion of song and steel.");

    addPrerequisite(
        "/guilds/drambor-edlothiad/bladesinger/harmonic-precision.c",
        (["type": "research"]));
    addPrerequisite("level",
        (["type": "level",
            "guild": "Drambor Edlothiad",
            "value": 17
        ]));

    addSpecification("limited by", (["equipment":
        ({ "long sword", "hand and a half sword",
            "two-handed sword", "short sword",
            "dagger" }) ]));

    addSpecification("scope", "self");
    addSpecification("research type", "points");
    addSpecification("research cost", 1);
    addSpecification("spell point cost", 65);
    addSpecification("stamina point cost", 25);
    addSpecification("cooldown", 180);
    addSpecification("duration", 120);
    addSpecification("bonus attack", 6);
    addSpecification("bonus defense", 5);
    addSpecification("bonus damage", 4);

    addSpecification("modifiers", ({
        (["type": "skill",
            "name": "long sword",
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
            "name": "charisma",
            "formula": "additive",
            "rate": 0.05]),
    }));

    addSpecification("command template", "greater bladesong");
    addSpecification("use ability message",
        "##InitiatorName## ##Infinitive::begin## the Greater Bladesong, "
            "blade and voice moving as one.");
}
