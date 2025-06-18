//*****************************************************************************
// Copyright (c) 2025 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/instantaneousActiveResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Age Touch");
    addSpecification("description", "This is a persona research item.");
    addSpecification("scope", "targeted");
    addSpecification("research type", "granted");
    addSpecification("spell point cost", 15);
    addSpecification("damage type", "temporal");
    addSpecification("damage hit points", ({ ([
        "probability":100,
        "base damage" : 40,
        "range" : 40
    ]) }));
    addSpecification("modifiers", ({ ([
        "type":"skill",
        "name" : "time",
        "formula" : "additive",
        "rate" : 1.5
    ]), ([
        "type":"attribute",
        "name" : "intelligence",
        "formula" : "logarithmic",
        "base value" : 5,
        "rate" : 1.3
    ]) }));
    addSpecification("cooldown", 12);
    addSpecification("command template", "age touch at ##Target##");
    addSpecification("use ability message", "##InitiatorName## "
        "##Infinitive::reach## out, and the years weigh heavily upon "
        "##TargetName##.");
}
