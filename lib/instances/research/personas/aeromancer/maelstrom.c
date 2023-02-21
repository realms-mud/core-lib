//*****************************************************************************
// Copyright (c) 2023 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/instantaneousActiveResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Maelstrom");
    addSpecification("description", "This is a persona research item.");
    addSpecification("effect", "combat");
    addSpecification("scope", "area");
    addSpecification("research type", "granted");
    addSpecification("spell point cost", 25);
    addSpecification("damage type", "electricity");
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
        "name": "elemental air",
        "formula": "additive",
        "rate": 1.25
    ]), ([
        "type":"attribute",
        "name": "intelligence",
        "formula": "logarithmic",
        "base value": 5,
        "rate": 1.2
    ]) }));
    addSpecification("cooldown", 60);
    addSpecification("command template", "maelstrom at ##Target##");
    addSpecification("use ability message", "##InitiatorName## ##Infinitive::scream## words of power. Wind and lightning batters everyone in the area.");
}
