//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD. All rights reserved.
//*****************************************************************************
inherit "/lib/modules/research/instantaneousActiveResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Rune Strike");
    addSpecification("description", "A rune flares as the runeskald strikes.");
    addSpecification("effect", "combat");
    addSpecification("scope", "targeted");
    addSpecification("research type", "granted");
    addSpecification("spell point cost", 5);
    addSpecification("damage type", "magical");
    addSpecification("damage hit points", ({ ([
        "probability": 100, "base damage": 20, "range": 20
    ]) }));
    addSpecification("cooldown", 4);
    addSpecification("command template", "runestrike at ##Target##");
    addSpecification("use ability message", "A glowing rune flashes against ##TargetName##.");
}
