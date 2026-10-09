//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/persistedActiveResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Celestial Bladesong");
    addSpecification("source", "Drambor Edlothiad");
    addSpecification("description", "This research provides the knowledge to "
        "perform the legendary celestial bladesong.");

    addPrerequisite(
        "/guilds/drambor-edlothiad/bladesinger/song-of-the-stars.c",
        (["type": "research"]));
    addPrerequisite("level",
        (["type": "level",
            "guild": "Drambor Edlothiad",
            "value": 53
        ]));

    addSpecification("limited by", (["equipment":
        ({ "long sword", "hand and a half sword",
            "two-handed sword", "short sword",
            "dagger" }) ]));

    addSpecification("scope", "self");
    addSpecification("research type", "points");
    addSpecification("research cost", 1);
    addSpecification("spell point cost", 160);
    addSpecification("stamina point cost", 45);
    addSpecification("cooldown", 180);
    addSpecification("duration", 120);
    addSpecification("bonus attack", 18);
    addSpecification("bonus defense", 15);
    addSpecification("bonus damage", 14);

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

    addSpecification("command template", "celestial bladesong");
    addSpecification("use ability message",
        "##InitiatorName## ##Infinitive::perform## the Celestial Bladesong, "
            "starlight trailing from each stroke.");
}
