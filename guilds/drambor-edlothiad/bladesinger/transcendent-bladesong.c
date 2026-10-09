//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/persistedActiveResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Transcendent Bladesong");
    addSpecification("source", "Drambor Edlothiad");
    addSpecification("description", "This research provides the knowledge to "
        "achieve a transcendent state through the bladesong.");

    addPrerequisite(
        "/guilds/drambor-edlothiad/bladesinger/bladesong-mastery.c",
        (["type": "research"]));
    addPrerequisite("level",
        (["type": "level",
            "guild": "Drambor Edlothiad",
            "value": 29
        ]));

    addSpecification("limited by", (["equipment":
        ({ "long sword", "hand and a half sword",
            "two-handed sword", "short sword",
            "dagger" }) ]));

    addSpecification("scope", "self");
    addSpecification("research type", "points");
    addSpecification("research cost", 1);
    addSpecification("spell point cost", 100);
    addSpecification("stamina point cost", 35);
    addSpecification("cooldown", 180);
    addSpecification("duration", 120);
    addSpecification("bonus attack", 10);
    addSpecification("bonus defense", 8);
    addSpecification("bonus damage", 8);

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

    addSpecification("command template", "transcendent bladesong");
    addSpecification("use ability message",
        "##InitiatorName## ##Infinitive::achieve## transcendence through the "
            "bladesong, every movement perfect.");
}
