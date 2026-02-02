//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/instantaneousActiveResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Searing Strikes");
    addSpecification("description", "This is a flame guardian ability.");
    addSpecification("effect", "combat");
    addSpecification("scope", "targeted");
    addSpecification("research type", "granted");
    addSpecification("spell point cost", 50);
    addSpecification("damage type", "fire");

    addSpecification("damage hit points", ({ 
        ([
            "probability": 90,
            "base damage": 25,
            "range": 50
        ]),
        ([
            "probability": 10,
            "base damage": 50,
            "range": 75
        ])
    }));
    addSpecification("modifiers", ({ 
        ([
            "type":"skill",
            "name": "elemental fire",
            "formula": "additive",
            "rate": 1.10
        ]), 
        ([
            "type":"level",
            "name": "level",
            "formula": "logarithmic",
            "rate": 1.05
        ])
    }));
    addSpecification("cooldown", 30);
    addSpecification("command template", "searing strikes at ##Target##");
    addSpecification("use ability message", "##InitiatorName## "
        "##Infinitive::lash## out with blazing claws, searing ##TargetName##.");
}
