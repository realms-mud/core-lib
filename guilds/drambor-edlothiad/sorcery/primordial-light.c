//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/persistedActiveResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Primordial Light");
    addSpecification("source", "Drambor Edlothiad");
    addSpecification("description", "The primordial light spell, calling "
        "forth  the first light of creation.");
    addPrerequisite(
        "/guilds/drambor-edlothiad/sorcery/elder-star.c",
        (["type": "research"]));
    addPrerequisite("level",
        (["type": "level",
            "guild": "Drambor Edlothiad",
            "value": 43
        ]));
    addSpecification("scope", "area");
    addSpecification("research type", "points");
    addSpecification("research cost", 1);
    addSpecification("spell point cost", 170);
    addSpecification("cooldown", 60);
    addSpecification("duration", 4);
    addSpecification("bonus magical attack", 40);
    addSpecification("bonus radiant attack", 25);
    addSpecification("modifiers", ({
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
            "rate": 2.25]),
        (["type": "level",
            "name": "Drambor Edlothiad",
            "formula": "logarithmic",
            "rate": 1.25]),
        (["type": "attribute",
            "name": "wisdom",
            "formula": "additive",
            "rate": 0.10]),
    }));
    addSpecification("command template", "primordial light");
    addSpecification("use ability message", "##InitiatorName## "
        "##Infinitive::call## forth the primordial light, the first radiance "
        "of creation burning with devastating intensity.");
}
