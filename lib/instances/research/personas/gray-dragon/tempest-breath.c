//*****************************************************************************
// Copyright (c) 2024 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/instantaneousActiveResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Tempest Breath");
    addSpecification("description", "This is a persona research item.");
    addSpecification("effect", "combat");
    addSpecification("scope", "targeted");
    addSpecification("research type", "granted");
    addSpecification("spell point cost", 15);
    addSpecification("damage type", "earth");
    addSpecification("damage hit points", ({ ([
        "probability":100,
        "base damage" : 25,
        "range" : 25
    ]) }));
    addSpecification("modifiers", ({ ([
        "type":"skill",
        "name": "elemental earth",
        "formula": "additive",
        "rate": 1.15
    ]), ([
        "type":"skill",
        "name": "evocation",
        "formula": "additive",
        "rate": 1.10
    ]), ([
        "type":"attribute",
        "name": "intelligence",
        "formula": "logarithmic",
        "base value": 10,
        "rate": 1.2
    ]) }));
    addSpecification("cooldown", 10);
    addSpecification("command template", "tempestbreath at ##Target##");
    addSpecification("use ability message", "##InitiatorName## "
        "##Infinitive::open## ##InitiatorPossessive## maw and "
        "##Infinitive::breathe## a molten silica on ##TargetName##.");
}
