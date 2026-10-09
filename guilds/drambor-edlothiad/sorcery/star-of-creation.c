//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/persistedActiveResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Star of Creation");
    addSpecification("source", "Drambor Edlothiad");
    addSpecification("description", "The ultimate elven sorcery spell, "
        "calling  forth a star of pure creation energy.");
    addPrerequisite(
        "/guilds/drambor-edlothiad/sorcery/primordial-light.c",
        (["type": "research"]));
    addPrerequisite("level",
        (["type": "level",
            "guild": "Drambor Edlothiad",
            "value": 59
        ]));
    addSpecification("scope", "area");
    addSpecification("research type", "points");
    addSpecification("research cost", 1);
    addSpecification("spell point cost", 250);
    addSpecification("cooldown", 90);
    addSpecification("duration", 4);
    addSpecification("bonus magical attack", 50);
    addSpecification("bonus radiant attack", 35);
    addSpecification("modifiers", ({
        (["type": "research",
            "research item": 
                "/guilds/drambor-edlothiad/sorcery/sorcery-supremacy.c",
            "name": "sorcery-supremacy",
            "formula": "multiplicative",
            "base value": 1,
            "rate": 1.25]),
        (["type": "research",
            "research item": 
                "/guilds/drambor-edlothiad/sorcery/sorcery-transcendence.c",
            "name": "sorcery-transcendence",
            "formula": "multiplicative",
            "base value": 1,
            "rate": 1.25]),
        (["type": "skill",
            "name": "spellcraft",
            "formula": "logarithmic",
            "rate": 2.50]),
        (["type": "level",
            "name": "Drambor Edlothiad",
            "formula": "logarithmic",
            "rate": 1.30]),
        (["type": "attribute",
            "name": "wisdom",
            "formula": "additive",
            "rate": 0.15]),
    }));
    addSpecification("command template", "star of creation");
    addSpecification("use ability message", "##InitiatorName## "
        "##Infinitive::call## forth a Star of Creation, its primordial "
        "radiance annihilating all before it.");
}
