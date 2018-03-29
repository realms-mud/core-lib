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
        addSpecification("name", "zorlak's revenge");
        addSpecification("source", "mage guild");
        addSpecification("description", "This is limited active research");
        addPrerequisite("long sword", (["type":"skill", "value" : 10]));
        addSpecification("scope", "targeted");
        addSpecification("research type", "points");
        addSpecification("research cost", 1);
        addSpecification("spell point cost", 1);
        addSpecification("limited by", (["equipment":"long sword"]));
        addSpecification("increase hit points", ({ ([
            "probability":80,
            "base damage" : 25,
            "range" : 25
        ]),
        ([
            "probability":20,
            "base damage" : 35,
            "range" : 25
        ])}));
        addSpecification("modifiers", ({ ([
            "type":"skill",
            "name": "long sword",
            "formula": "additive",
            "rate": 1.25
        ]),
        ([
            "type":"attribute",
            "name": "strength",
            "formula": "subtractive",
            "rate": 0.25
        ]) }));
        addSpecification("cooldown", 4);
        addSpecification("event handler", "usedResearchEvent");
        addSpecification("command template", "throw turnip at ##Target##");
        addSpecification("command template", "hurl turnip at ##Target##");
        addSpecification("use ability message", "##InitiatorName## ##Infinitive::throw## a turnip at ##TargetName##.");
    }
}
