//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD. All rights reserved.
//*****************************************************************************
inherit "/lib/modules/research/instantaneousActiveResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Silent Execution");
    addSpecification("description", "A precise final strike ends the engagement.");
    addSpecification("effect", "combat");
    addSpecification("scope", "targeted");
    addSpecification("research type", "granted");
    addSpecification("spell point cost", 20);
    addSpecification("damage type", "physical");
    addSpecification("damage hit points", ({ ([
        "probability": 100, "base damage": 55, "range": 45
    ]) }));
    addSpecification("cooldown", 30);
    addSpecification("command template", "silentexecution at ##Target##");
    addSpecification("use ability message", "A silent, decisive strike hits ##TargetName##.");
}
