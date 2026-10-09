//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/persistedActiveResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Eldritch Star");
    addSpecification("source", "Drambor Edlothiad");
    addSpecification("description", "An intensified starlight spell that "
        "calls down an eldritch star of devastating radiance.");
    addPrerequisite(
        "/guilds/drambor-edlothiad/sorcery/moonfire.c",
        (["type": "research"]));
    addPrerequisite("level",
        (["type": "level",
            "guild": "Drambor Edlothiad",
            "value": 15
        ]));
    addSpecification("scope", "targeted");
    addSpecification("research type", "points");
    addSpecification("research cost", 1);
    addSpecification("spell point cost", 70);
    addSpecification("cooldown", 20);
    addSpecification("duration", 4);
    addSpecification("bonus magical attack", 15);
    addSpecification("bonus radiant attack", 10);
    addSpecification("modifiers", ({
        (["type": "research",
            "research item": 
                "/guilds/drambor-edlothiad/sorcery/sorcery-amplification.c",
            "name": "sorcery-amplification",
            "formula": "multiplicative",
            "base value": 1,
            "rate": 1.25]),
        (["type": "skill",
            "name": "spellcraft",
            "formula": "logarithmic",
            "rate": 1.50]),
        (["type": "level",
            "name": "Drambor Edlothiad",
            "formula": "logarithmic",
            "rate": 1.15]),
        (["type": "attribute",
            "name": "wisdom",
            "formula": "additive",
            "rate": 0.08]),
    }));
    addSpecification("command template", "eldritch star");
    addSpecification("use ability message", "An eldritch star blazes to life "
        "above ##TargetName##, raining devastating radiance upon them.");
}
