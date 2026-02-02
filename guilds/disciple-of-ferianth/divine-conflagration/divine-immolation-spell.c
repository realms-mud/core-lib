//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/instantaneousActiveResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Divine Immolation");
    addSpecification("description", "This is a flame guardian ability.");
    addSpecification("effect", "combat");
    addSpecification("scope", "targeted");
    addSpecification("research type", "granted");
    addSpecification("spell point cost", 150);
    addSpecification("damage type", "fire");

    addSpecification("damage hit points", ({ 
        ([
            "probability": 80,
            "base damage": 100,
            "range": 100
        ]),
        ([
            "probability": 20,
            "base damage": 200,
            "range": 150
        ])
    }));
    addSpecification("modifiers", ({ 
        ([
            "type":"skill",
            "name": "elemental fire",
            "formula": "additive",
            "rate": 1.20
        ]), 
        ([
            "type":"level",
            "name": "level",
            "formula": "logarithmic",
            "rate": 1.15
        ])
    }));
    addSpecification("cooldown", 90);
    addSpecification("command template", "divine immolation at ##Target##");
    addSpecification("use ability message", "##InitiatorName## "
        "##Infinitive::channel## Ferianth's divine fire into a devastating "
        "blast that immolates ##TargetName##.");
}
