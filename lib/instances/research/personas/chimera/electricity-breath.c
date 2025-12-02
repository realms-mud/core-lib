//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/instantaneousActiveResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Electricity Breath");
    addSpecification("description", "This is a persona research item.");
    addSpecification("effect", "combat");
    addSpecification("scope", "targeted");
    addSpecification("research type", "granted");
    addSpecification("spell point cost", 15);
    addSpecification("damage type", "electricity");
    addSpecification("damage hit points", ({ ([
        "probability":100,
        "base damage" : 25,
        "range" : 25
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
        "base value": 10,
        "rate": 1.2
    ]) }));
    addSpecification("cooldown", 10);
    addSpecification("command template", "electricitybreath at ##Target##");
    addSpecification("use ability message", "##InitiatorName## ##Infinitive::open## ##InitiatorPossessive## maw and ##Infinitive::breathe## a ball of electrical plasma at ##TargetName##.");
}
