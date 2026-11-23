//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD. All rights reserved.
//*****************************************************************************
inherit "/lib/modules/research/instantaneousActiveResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Healing Light");
    addSpecification("description", "A flash of Ilyrth's radiant power strikes "
        "a foe.");
    addSpecification("effect", "combat");
    addSpecification("scope", "targeted");
    addSpecification("research type", "granted");
    addSpecification("spell point cost", 5);
    addSpecification("damage type", "radiant");
    addSpecification("damage hit points", ({ ([
        "probability": 100,
        "base damage": 20,
        "range": 20
    ]) }));
    addSpecification("cooldown", 4);
    addSpecification("command template", "healinglight at ##Target##");
    addSpecification("use ability message",
        "A shaft of radiant light flashes against ##TargetName##.");
}
