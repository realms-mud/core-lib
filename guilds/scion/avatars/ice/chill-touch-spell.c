//*****************************************************************************
// Copyright (c) 2021 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/instantaneousActiveResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Chill Touch");
    addSpecification("description", "This is a persona research item.");
    addSpecification("effect", "combat");
    addSpecification("scope", "targeted");
    addSpecification("research type", "granted");
    addSpecification("spell point cost", 15);
    addSpecification("damage type", "cold");
    addSpecification("damage hit points", ({ ([
        "probability": 100,
            "base damage": 10,
            "range": 10
    ]) }));
    addSpecification("modifiers", ({ 
    ([
        "type":"skill",
        "name": "elemental water",
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
    addSpecification("command template", "chilltouch at ##Target##");
    addSpecification("use ability message", "Sinuous tendrils of "
        "ice from ##InitiatorPossessive::Name## "
        "clawed hand into ##TargetName##.");
}
