//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/persistedActiveResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Primordial Strike");
    addSpecification("source", "Drambor Edlothiad");
    addSpecification("description", "This research provides the knowledge to "
        "deliver a strike of primordial power, the ultimate spell sword "
            "technique.");

    addPrerequisite(
        "/guilds/drambor-edlothiad/spellsword/worldbreaker-strike.c",
        (["type": "research"]));
    addPrerequisite("level",
        (["type": "level",
            "guild": "Drambor Edlothiad",
            "value": 67
        ]));

    addSpecification("limited by", (["equipment":
        ({ "long sword", "hand and a half sword",
            "two-handed sword", "short sword",
            "dagger" }) ]));

    addSpecification("scope", "self");
    addSpecification("research type", "points");
    addSpecification("research cost", 1);
    addSpecification("spell point cost", 250);
    addSpecification("stamina point cost", 60);
    addSpecification("cooldown", 60);
    addSpecification("duration", 10);
    addSpecification("bonus magical attack", 60);
    addSpecification("bonus fire attack", 15);
    addSpecification("bonus cold attack", 15);
    addSpecification("bonus electricity attack", 15);

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
            "name": "intelligence",
            "formula": "additive",
            "rate": 0.05]),
    }));

    addSpecification("command template", "primordial strike");
    addSpecification("use ability message",
        "##InitiatorName## ##Infinitive::deliver## the Primordial Strike, "
            "the first and last strike, power incarnate.");
}
