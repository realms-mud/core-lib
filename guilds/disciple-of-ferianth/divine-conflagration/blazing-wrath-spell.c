//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/instantaneousActiveResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Blazing Wrath");
    addSpecification("description", "This is a flame guardian ability.");
    addSpecification("effect", "combat");
    addSpecification("scope", "area");
    addSpecification("research type", "granted");
    addSpecification("spell point cost", 100);
    addSpecification("damage type", "fire");

    addSpecification("damage hit points", ({ 
        ([
            "probability": 90,
            "base damage": 50,
            "range": 75
        ]),
        ([
            "probability": 10,
            "base damage": 100,
            "range": 100
        ])
    }));
    addSpecification("modifiers", ({ 
        ([
            "type":"skill",
            "name": "elemental fire",
            "formula": "additive",
            "rate": 1.15
        ]), 
        ([
            "type":"level",
            "name": "level",
            "formula": "logarithmic",
            "rate": 1.10
        ])
    }));
    addSpecification("cooldown", 60);
    addSpecification("command template", "blazing wrath");
    addSpecification("use ability message", "##InitiatorName## "
        "##Infinitive::erupt## in a blazing fury, flames sweeping outward "
        "to engulf all nearby foes.");
}
