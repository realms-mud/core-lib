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
        addSpecification("name", "muclid");
        addSpecification("source", "blarg");
        addSpecification("description", "This is limited active research");
        addSpecification("usage summary", "This muclidifies stuff.");
        addSpecification("scope", "targeted");
        addSpecification("research type", "granted");
        addSpecification("research cost", 1);
        addSpecification("spell point cost", 10);
        addSpecification("damage hit points", ({ ([
            "probability": 100,
            "base damage": 22,
            "range": 0
        ]) }));
        addSpecification("damage type", "physical");

        addSpecification("cooldown", 4);
        addSpecification("event handler", "usedResearchEvent");
        addSpecification("command template", "muclid [at ##Target##]");
        addSpecification("use ability message", "##InitiatorName## ##Infinitive::throw## a turnip at ##TargetName##.");
    }
}
