//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD. All rights reserved.
//*****************************************************************************
inherit "/lib/modules/research/instantaneousActiveResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Searing Rebuke");
    addSpecification("description", "Seilyndria answers an offense with a burst "
        "of searing fire.");
    addSpecification("effect", "combat");
    addSpecification("scope", "targeted");
    addSpecification("research type", "granted");
    addSpecification("spell point cost", 12);
    addSpecification("damage type", "fire");
    addSpecification("damage hit points", ({ ([
        "probability": 100,
        "base damage": 35,
        "range": 30
    ]) }));
    addSpecification("cooldown", 12);
    addSpecification("command template", "searingrebuke at ##Target##");
    addSpecification("use ability message",
        "A searing flare erupts around ##TargetName##.");
}
