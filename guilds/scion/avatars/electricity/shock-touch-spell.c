//*****************************************************************************
// Copyright (c) 2024 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/instantaneousActiveResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Shock Touch");
    addSpecification("description", "This is a persona research item.");
    addSpecification("effect", "combat");
    addSpecification("scope", "targeted");
    addSpecification("research type", "granted");
    addSpecification("spell point cost", 15);
    addSpecification("damage type", "electricity");
    addSpecification("damage hit points", ({ ([
        "probability": 100,
            "base damage": 10,
            "range": 10
    ]) }));
    addSpecification("modifiers", ({ 
    ([
        "type":"skill",
        "name": "elemental air",
        "formula": "additive",
        "rate": 1.05
    ]), 
    ([
        "type":"skill",
        "name": "spellcraft",
        "formula": "additive",
        "rate": 1.05
    ]), 
    ([
        "type":"skill",
        "name": "evocation",
        "formula": "additive",
        "rate": 1.05
    ]),
    ([
        "type":"skill",
        "name": "physics",
        "formula": "additive",
        "rate": 1.05
    ]),
    ([
        "type":"skill",
        "name": "magical essence",
        "formula": "logarithmic",
        "base value" : 1,
        "rate" : 1.05
    ]),
    ([
        "type":"attribute",
        "name": "intelligence",
        "formula": "logarithmic",
        "base value": 1,
        "rate": 1.2
    ]) }));
    addSpecification("cooldown", 10);
    addSpecification("command template", "shocktouch at ##Target##");
    addSpecification("use ability message", "##InitiatorName## ##Infinitive::raise## "
        "##InitiatorPossessive## clawed hand and shards of sickly dark energy "
        "fly into ##TargetName##.");
}
