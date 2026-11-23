//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD. All rights reserved.
//*****************************************************************************
inherit "/lib/modules/research/instantaneousActiveResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Vengeful Smite");
    addSpecification("description", "A swift strike carries Seilyndria's "
        "vengeance.");
    addSpecification("effect", "combat");
    addSpecification("scope", "targeted");
    addSpecification("research type", "granted");
    addSpecification("spell point cost", 5);
    addSpecification("damage type", "fire");
    addSpecification("damage hit points", ({ ([
        "probability": 100,
        "base damage": 20,
        "range": 20
    ]) }));
    addSpecification("cooldown", 4);
    addSpecification("command template", "vengefulsmite at ##Target##");
    addSpecification("use ability message",
        "##InitiatorName## calls down Seilyndria's wrath upon ##TargetName##.");
}
