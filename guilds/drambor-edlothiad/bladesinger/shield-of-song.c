//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/persistedActiveResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Shield of Song");
    addSpecification("source", "Drambor Edlothiad");
    addSpecification("description", "This research provides the knowledge to "
        "create a shield of harmonic energy around the singer.");

    addPrerequisite(
        "/guilds/drambor-edlothiad/bladesinger/warding-song.c",
        (["type": "research"]));
    addPrerequisite("level",
        (["type": "level",
            "guild": "Drambor Edlothiad",
            "value": 11
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
    addSpecification("duration", 90);
    addSpecification("bonus defense", 5);
    addSpecification("bonus armor class", 3);

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

    addSpecification("command template", "shield of song");
    addSpecification("use ability message",
        "A shimmering shield of harmonic energy surrounds "
            "##InitiatorName##.");
}
