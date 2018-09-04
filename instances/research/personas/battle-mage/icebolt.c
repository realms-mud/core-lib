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
        addSpecification("name", "Icebolt");
        addSpecification("description", "This is a persona research item.");
        addSpecification("effect", "combat");
        addSpecification("scope", "targeted");
        addSpecification("research type", "granted");
        addSpecification("spell point cost", 15);
        addSpecification("damage type", "cold");
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
        addSpecification("cooldown", 20);
        addSpecification("command template", "icebolt at ##Target##");
        addSpecification("use ability message", "##InitiatorName## ##Infinitive::raise## ##InitiatorPossessive## arms and a "
            "bolt of pure ice slams into ##TargetName##.");
    }
}
