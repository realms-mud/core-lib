//*****************************************************************************
// Copyright (c) 2024 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/instantaneousActiveResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Hand of Xyris");
    addSpecification("description", "This is a persona research item.");
    addSpecification("effect", "combat");
    addSpecification("scope", "targeted");
    addSpecification("research type", "granted");
    addSpecification("spell point cost", 15);
    addSpecification("damage type", "evil");
    addSpecification("damage hit points", ({ ([
        "probability":100,
            "base damage" : 35,
            "range" : 35
    ]) }));
    addSpecification("damage spell points", ({ ([
        "probability":100,
            "base damage" : 35,
            "range" : 35
    ]) }));
    addSpecification("damage stamina points", ({ ([
        "probability":100,
            "base damage" : 35,
            "range" : 35
    ]) }));
    addSpecification("modifiers", ({ ([
        "type":"skill",
        "name": "elemental air",
        "formula": "additive",
        "rate": 1.10
    ]), ([
        "type":"skill",
        "name": "body",
        "formula": "additive",
        "rate": 1.10
    ]), ([
        "type":"skill",
        "name": "blood",
        "formula": "additive",
        "rate": 1.10
    ]), ([
        "type":"attribute",
        "name": "intelligence",
        "formula": "logarithmic",
        "base value": 5,
        "rate": 1.2
    ]) }));
    addSpecification("cooldown", 20);
    addSpecification("command template", "handofxyris at ##Target##");
    addSpecification("use ability message", "##InitiatorName## ##Infinitive::raise## ##InitiatorPossessive## arms and tendrils of dark red lightning descend upon ##TargetName##.");
}
