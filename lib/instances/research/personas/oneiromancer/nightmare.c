//*****************************************************************************
// Copyright (c) 2024 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/instantaneousActiveResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Nightmare");
    addSpecification("description", "This is a persona research item.");
    addSpecification("effect", "combat");
    addSpecification("scope", "area");
    addSpecification("research type", "granted");
    addSpecification("spell point cost", 25);
    addSpecification("damage type", "psionic");
    addSpecification("damage hit points", ({ ([
        "probability":100,
            "base damage" : 50,
            "range" : 50
    ]) }));
    addSpecification("damage spell points", ({ ([
        "probability":100,
            "base damage" : 100,
            "range" : 100
    ]) }));
    addSpecification("damage stamina points", ({ ([
        "probability":100,
            "base damage" : 50,
            "range" : 50
    ]) }));
    addSpecification("modifiers", ({ ([
        "type":"skill",
        "name": "mind",
        "formula": "additive",
        "rate": 1.10
    ]), ([
        "type":"skill",
        "name": "senses",
        "formula": "additive",
        "rate": 1.10
    ]), ([
        "type":"skill",
        "name": "spirit",
        "formula": "additive",
        "rate": 1.10
    ]),([
        "type":"attribute",
        "name": "intelligence",
        "formula": "logarithmic",
        "base value": 5,
        "rate": 1.2
    ]) }));
    addSpecification("cooldown", 60);
    addSpecification("command template", "nightmare at ##Target##");
    addSpecification("use ability message", "##InitiatorName## "
        "##Infinitive::scream## words of power. Horrible, crippling "
        "nightmares overcome everyone in the area.");
}
