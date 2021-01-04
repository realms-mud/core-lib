//*****************************************************************************
// Copyright (c) 2021 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/instantaneousActiveResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
public void reset(int arg)
{
    if (!arg)
    {
        instantaneousActiveResearchItem::reset(arg);
        addSpecification("name", "Enervation Breath");
        addSpecification("description", "This is a persona research item.");
        addSpecification("effect", "combat");
        addSpecification("scope", "targeted");
        addSpecification("research type", "granted");
        addSpecification("spell point cost", 15);
        addSpecification("damage type", "evil");
        addSpecification("damage hit points", ({ ([
            "probability":100,
            "base damage" : 25,
            "range" : 25
        ]) }));
        addSpecification("modifiers", ({ ([
            "type":"skill",
            "name": "blood",
            "formula": "additive",
            "rate": 1.15
        ]), ([
            "type":"skill",
            "name": "evocation",
            "formula": "additive",
            "rate": 1.10
        ]), ([
            "type":"skill",
            "name": "destruction",
            "formula": "additive",
            "rate": 1.10
        ]), ([
            "type":"attribute",
            "name": "intelligence",
            "formula": "logarithmic",
            "base value": 10,
            "rate": 1.2
        ]) }));
        addSpecification("cooldown", 10);
        addSpecification("command template", "enervationbreath at ##Target##");
        addSpecification("use ability message", "##InitiatorName## "
            "##Infinitive::open## ##InitiatorPossessive## maw and "
            "##Infinitive::breathe## a ball of electrically-charged black plasma "
            "  at ##TargetName##.");
    }
}
