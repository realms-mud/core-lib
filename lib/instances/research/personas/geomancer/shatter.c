//*****************************************************************************
// Copyright (c) 2023 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/instantaneousActiveResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Shatter");
    addSpecification("description", "This is a persona research item.");
    addSpecification("effect", "combat");
    addSpecification("scope", "targeted");
    addSpecification("research type", "granted");
    addSpecification("spell point cost", 15);
    addSpecification("damage type", "earth");
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
        "name": "elemental earth",
        "formula": "additive",
        "rate": 1.25
    ]), ([
        "type":"attribute",
        "name": "intelligence",
        "formula": "logarithmic",
        "base value": 5,
        "rate": 1.2
    ]) }));
    addSpecification("cooldown", 20);
    addSpecification("command template", "shatter at ##Target##");
    addSpecification("use ability message", "##InitiatorName## ##Infinitive::raise## ##InitiatorPossessive## arms and spears of stone come up out of the ground and slam into ##TargetName##.");
}
