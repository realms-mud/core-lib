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
        addSpecification("name", "Tremor");
        addSpecification("description", "This is a persona research item.");
        addSpecification("effect", "combat");
        addSpecification("scope", "targeted");
        addSpecification("research type", "granted");
        addSpecification("spell point cost", 25);
        addSpecification("damage type", "earth");
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
        addSpecification("command template", "tremor at ##Target##");
        addSpecification("use ability message", "##InitiatorName## ##Infinitive::scream## words of power. The ground shakes violently as it splinters.");
    }
}
