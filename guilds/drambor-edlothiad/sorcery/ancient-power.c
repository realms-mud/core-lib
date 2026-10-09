//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/persistedActiveResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Ancient Power");
    addSpecification("source", "Drambor Edlothiad");
    addSpecification("description", "A spell drawing on the accumulated power "
        " of ancient elven civilization.");
    addPrerequisite(
        "/guilds/drambor-edlothiad/sorcery/eldritch-star.c",
        (["type": "research"]));
    addPrerequisite("level",
        (["type": "level",
            "guild": "Drambor Edlothiad",
            "value": 19
        ]));
    addSpecification("scope", "area");
    addSpecification("research type", "points");
    addSpecification("research cost", 1);
    addSpecification("spell point cost", 90);
    addSpecification("cooldown", 30);
    addSpecification("duration", 4);
    addSpecification("bonus magical attack", 20);
    addSpecification("bonus radiant attack", 12);
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
            "rate": 1.75]),
        (["type": "level",
            "name": "Drambor Edlothiad",
            "formula": "logarithmic",
            "rate": 1.20]),
        (["type": "attribute",
            "name": "wisdom",
            "formula": "additive",
            "rate": 0.10]),
    }));
    addSpecification("command template", "ancient power");
    addSpecification("use ability message", "Ancient power surges through "
        "##InitiatorName##, elven magic of ages past erupting in devastating "
            "force.");
}
