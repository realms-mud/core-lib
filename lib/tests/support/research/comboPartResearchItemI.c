//*****************************************************************************
// Copyright (c) 2021 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/instantaneousActiveResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "fargle");
    addSpecification("source", "blarg");
    addSpecification("description", "This is limited active research");
    addSpecification("usage summary", "This fargles with the fresh scent of Brute.");
    addSpecification("scope", "targeted");
    addSpecification("research type", "granted");
    addSpecification("research cost", 1);
    addSpecification("stamina point cost", 10);
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
