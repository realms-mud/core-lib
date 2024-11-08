//*****************************************************************************
// Copyright (c) 2024 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/instantaneousActiveResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Sanguine Spear");
    addSpecification("description", "This is a persona research item.");
    addSpecification("effect", "combat");
    addSpecification("scope", "targeted");
    addSpecification("research type", "granted");
    addSpecification("spell point cost", 200);
    addSpecification("damage type", "evil");

    addSpecification("damage hit points", ({ ([
            "probability": 90,
            "base damage" : 100,
            "range" : 200
        ]),
        ([
            "probability":10,
            "base damage" : 200,
            "range" : 500
        ])
    }));
    addSpecification("damage spell points", ({ ([
            "probability":90,
            "base damage" : 50,
            "range" : 100
        ]),
        ([
            "probability": 10,
            "base damage": 100,
            "range" : 200
        ])
    }));

    addSpecification("modifiers", ({ 
    ([
        "type":"skill",
        "name": "blood",
        "formula": "additive",
        "rate": 1.10
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
        "rate": 1.10
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
        "type":"level",
        "name" : "level",
        "formula" : "logarithmic",
        "rate" : 1.05
    ]),
    ([
        "type":"attribute",
        "name": "intelligence",
        "formula": "logarithmic",
        "base value": 1,
        "rate": 1.2
    ]) }));
    addSpecification("cooldown", 100);
    addSpecification("command template", "sanguinespear at ##Target##");
    addSpecification("use ability message", "##InitiatorName## ##Infinitive::raise## "
        "##InitiatorPossessive## arm and a blackened spear of blood "
        "slams into ##TargetName##.");
}
