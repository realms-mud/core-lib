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
        addSpecification("name", "Nightmare");
        addSpecification("description", "This is a persona research item.");
        addSpecification("effect", "combat");
        addSpecification("scope", "area");
        addSpecification("research type", "granted");
        addSpecification("spell point cost", 25);
        addSpecification("damage type", "psionic");
        addSpecification("damage hit points", ({ ([
            "probability":100,
                "base damage" : 50,
                "range" : 50
        ]) }));
        addSpecification("damage spell points", ({ ([
            "probability":100,
                "base damage" : 100,
                "range" : 100
        ]) }));
        addSpecification("damage stamina points", ({ ([
            "probability":100,
                "base damage" : 50,
                "range" : 50
        ]) }));
        addSpecification("cooldown", 60);
        addSpecification("command template", "nightmare at ##Target##");
        addSpecification("use ability message", "##InitiatorName## "
            "##Infinitive::scream## words of power. Horrible, crippling "
            "nightmares overcome everyone in the area.");
    }
}
