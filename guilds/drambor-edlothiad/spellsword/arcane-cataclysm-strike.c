//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/persistedActiveResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Arcane Cataclysm Strike");
    addSpecification("source", "Drambor Edlothiad");
    addSpecification("description", "This research provides the knowledge to "
        "deliver a cataclysmic strike of combined arcane power.");

    addPrerequisite(
        "/guilds/drambor-edlothiad/spellsword/spell-strike-supremacy.c",
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
    addSpecification("stamina point cost", 35);
    addSpecification("cooldown", 30);
    addSpecification("duration", 8);
    addSpecification("bonus magical attack", 30);
    addSpecification("bonus fire attack", 10);
    addSpecification("bonus cold attack", 10);

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

    addSpecification("command template", "arcane cataclysm strike");
    addSpecification("use ability message",
        "##InitiatorName## ##Infinitive::unleash## a cataclysmic strike of "
            "devastating arcane power.");
}
