//*****************************************************************************
// Copyright (c) 2018 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/instantaneousActiveResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
public void reset(int arg)
{
    if (!arg)
    {
        instantaneousActiveResearchItem::reset(arg);
        addSpecification("name", "Mind blade");
        addSpecification("description", "This is a persona research item.");
        addSpecification("effect", "combat");
        addSpecification("scope", "targeted");
        addSpecification("research type", "granted");
        addSpecification("spell point cost", 5);
        addSpecification("damage type", "psionic");
        addSpecification("damage hit points", ({ ([
            "probability":100,
                "base damage" : 25,
                "range" : 25
        ]) }));
        addSpecification("modifiers", ({ ([
            "type":"skill",
            "name": "mind",
            "formula": "additive",
            "rate": 1.10
        ]), ([
            "type":"skill",
            "name": "senses",
            "formula": "additive",
            "rate": 1.10
        ]), ([
            "type":"skill",
            "name": "spirit",
            "formula": "additive",
            "rate": 1.10
        ]),([
            "type":"attribute",
            "name": "intelligence",
            "formula": "logarithmic",
            "base value": 5,
            "rate": 1.2
        ]) }));
        addSpecification("cooldown", 4);
        addSpecification("command template", "mindblade at ##Target##");
        addSpecification("use ability message", "##InitiatorName## ##Infinitive::raise## "
            "##InitiatorPossessive## hand and points at ##TargetName##.");
    }
}
