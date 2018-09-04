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
        addSpecification("name", "Lightning (Knight of the Storm)");
        addSpecification("description", "This is a persona research item.");
        addSpecification("effect", "combat");
        addSpecification("scope", "targeted");
        addSpecification("research type", "granted");
        addSpecification("spell point cost", 5);
        addSpecification("damage type", "electricity");
        addSpecification("damage hit points", ({ ([
            "probability":100,
                "base damage" : 30,
                "range" : 25
        ]) }));
        addSpecification("cooldown", 14);
        addSpecification("command template", "lightning at ##Target##");
        addSpecification("use ability message", "##InitiatorName## ##Infinitive::raise## ##InitiatorPossessive## hand and a stream of lightning slams into ##TargetName##.");
    }
}
