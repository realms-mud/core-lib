//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/persistedActiveResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Elder Star");
    addSpecification("source", "Drambor Edlothiad");
    addSpecification("description", "The elder star spell, drawing on the "
        "deepest wells of elven magical power.");
    addPrerequisite(
        "/guilds/drambor-edlothiad/sorcery/celestial-lance.c",
        (["type": "research"]));
    addPrerequisite("level",
        (["type": "level",
            "guild": "Drambor Edlothiad",
            "value": 35
        ]));
    addSpecification("scope", "area");
    addSpecification("research type", "points");
    addSpecification("research cost", 1);
    addSpecification("spell point cost", 130);
    addSpecification("cooldown", 40);
    addSpecification("duration", 4);
    addSpecification("bonus magical attack", 30);
    addSpecification("bonus radiant attack", 20);
    addSpecification("modifiers", ({
        (["type": "research",
            "research item": 
                "/guilds/drambor-edlothiad/sorcery/sorcery-amplification.c",
            "name": "sorcery-amplification",
            "formula": "multiplicative",
            "base value": 1,
            "rate": 1.25]),
        (["type": "research",
            "research item": 
                "/guilds/drambor-edlothiad/sorcery/sorcery-mastery.c",
            "name": "sorcery-mastery",
            "formula": "multiplicative",
            "base value": 1,
            "rate": 1.25]),
        (["type": "research",
            "research item": 
                "/guilds/drambor-edlothiad/sorcery/sorcery-supremacy.c",
            "name": "sorcery-supremacy",
            "formula": "multiplicative",
            "base value": 1,
            "rate": 1.25]),
        (["type": "skill",
            "name": "spellcraft",
            "formula": "logarithmic",
            "rate": 2.0]),
        (["type": "level",
            "name": "Drambor Edlothiad",
            "formula": "logarithmic",
            "rate": 1.25]),
        (["type": "attribute",
            "name": "wisdom",
            "formula": "additive",
            "rate": 0.10]),
    }));
    addSpecification("command template", "elder star");
    addSpecification("use ability message", "An elder star blazes into "
        "existence, its ancient light devastating everything beneath it.");
}
