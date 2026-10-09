//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/persistedActiveResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Celestial Lance");
    addSpecification("source", "Drambor Edlothiad");
    addSpecification("description", "A lance of celestial energy that pierces "
        " through magical defenses.");
    addPrerequisite(
        "/guilds/drambor-edlothiad/sorcery/ancient-power.c",
        (["type": "research"]));
    addPrerequisite("level",
        (["type": "level",
            "guild": "Drambor Edlothiad",
            "value": 25
        ]));
    addSpecification("scope", "targeted");
    addSpecification("research type", "points");
    addSpecification("research cost", 1);
    addSpecification("spell point cost", 100);
    addSpecification("cooldown", 30);
    addSpecification("duration", 4);
    addSpecification("bonus magical attack", 25);
    addSpecification("bonus radiant attack", 15);
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
    addSpecification("command template", "celestial lance");
    addSpecification("use ability message", "A lance of celestial energy "
        "streaks from ##InitiatorPossessive## hand, piercing through "
        "##TargetName##'s defenses.");
}
