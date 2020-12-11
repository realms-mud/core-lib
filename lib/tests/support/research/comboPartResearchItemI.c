//*****************************************************************************
// Copyright (c) 2020 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/instantaneousActiveResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
public void reset(int arg)
{
    if (!arg)
    {
        instantaneousActiveResearchItem::reset(arg);
        addSpecification("name", "fargle");
        addSpecification("source", "blarg");
        addSpecification("description", "This is limited active research");
        addSpecification("scope", "targeted");
        addSpecification("research type", "granted");
        addSpecification("research cost", 1);
        addSpecification("spell point cost", 1);
        addSpecification("increase hit points", ({ ([
            "probability": 100,
            "base damage": 14,
            "range": 0
        ]) }));
        addSpecification("damage type", "physical");

        addSpecification("cooldown", 4);
        addSpecification("event handler", "usedResearchEvent");
        addSpecification("command template", "rarg [at ##Target##]");
        addSpecification("use ability message", "##InitiatorName## ##Infinitive::throw## a turnip at ##TargetName##.");
        addSpecification("use combination message", "fargle mightily");
    }
}
