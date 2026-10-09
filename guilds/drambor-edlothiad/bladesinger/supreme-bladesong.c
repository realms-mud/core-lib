//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/persistedActiveResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Supreme Bladesong");
    addSpecification("source", "Drambor Edlothiad");
    addSpecification("description", "This research provides the knowledge to "
        "perform the supreme bladesong, the pinnacle of the art.");

    addPrerequisite(
        "/guilds/drambor-edlothiad/bladesinger/eternal-melody.c",
        (["type": "research"]));
    addPrerequisite("level",
        (["type": "level",
            "guild": "Drambor Edlothiad",
            "value": 41
        ]));

    addSpecification("limited by", (["equipment":
        ({ "long sword", "hand and a half sword",
            "two-handed sword", "short sword",
            "dagger" }) ]));

    addSpecification("scope", "self");
    addSpecification("research type", "points");
    addSpecification("research cost", 1);
    addSpecification("spell point cost", 130);
    addSpecification("stamina point cost", 40);
    addSpecification("cooldown", 180);
    addSpecification("duration", 120);
    addSpecification("bonus attack", 14);
    addSpecification("bonus defense", 12);
    addSpecification("bonus damage", 10);

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

    addSpecification("command template", "supreme bladesong");
    addSpecification("use ability message",
        "##InitiatorName## ##Infinitive::perform## the Supreme Bladesong, "
            "reality itself bending to the melody.");
}
