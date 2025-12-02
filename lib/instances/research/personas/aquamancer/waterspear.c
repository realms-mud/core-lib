//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/instantaneousActiveResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Waterspear");
    addSpecification("description", "This is a persona research item.");
    addSpecification("effect", "combat");
    addSpecification("scope", "targeted");
    addSpecification("research type", "granted");
    addSpecification("spell point cost", 5);
    addSpecification("damage type", "water");
    addSpecification("damage hit points", ({ ([
        "probability":100,
            "base damage" : 25,
            "range" : 25
    ]) }));
    addSpecification("modifiers", ({ ([
        "type":"skill",
        "name": "elemental water",
        "formula": "additive",
        "rate": 1.25
    ]), ([
        "type":"attribute",
        "name": "intelligence",
        "formula": "logarithmic",
        "base value": 5,
        "rate": 1.2
    ]) }));
    addSpecification("cooldown", 4);
    addSpecification("command template", "waterspear at ##Target##");
    addSpecification("use ability message", "##InitiatorName## ##Infinitive::raise## "
        "##InitiatorPossessive## hand and a thin blade of high velocity "
        "water slams into ##TargetName##.");
}
