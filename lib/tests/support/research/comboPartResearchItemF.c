//*****************************************************************************
// Copyright (c) 2021 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/instantaneousActiveResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "clerb");
    addSpecification("source", "blarg");
    addSpecification("description", "This is limited active research");
    addSpecification("usage summary", "Beware the clerb.");
    addSpecification("scope", "targeted");
    addSpecification("research type", "granted");
    addSpecification("research cost", 1);
    addSpecification("spell point cost", 10);
    addSpecification("damage hit points", ({ ([
        "probability": 100,
        "base damage": 11,
        "range": 0
    ]) }));
    addSpecification("damage type", "fire");

    addSpecification("cooldown", 4);
    addSpecification("event handler", "usedResearchEvent");
    addSpecification("command template", "clerb [at ##Target##]");
    addSpecification("use ability message", "##InitiatorName## ##Infinitive::throw## a turnip at ##TargetName##.");
    addSpecification("use combination message", "clerb at ##TargetName## with fiery death");
}
