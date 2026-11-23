//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD. All rights reserved.
//*****************************************************************************
inherit "/lib/modules/research/instantaneousActiveResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Restoration");
    addSpecification("description", "Ilyrth's restorative force sears away "
        "hostile energy.");
    addSpecification("effect", "combat");
    addSpecification("scope", "targeted");
    addSpecification("research type", "granted");
    addSpecification("spell point cost", 12);
    addSpecification("damage type", "radiant");
    addSpecification("damage hit points", ({ ([
        "probability": 100,
        "base damage": 35,
        "range": 30
    ]) }));
    addSpecification("cooldown", 12);
    addSpecification("command template", "restoration at ##Target##");
    addSpecification("use ability message",
        "A pulse of cleansing radiance bursts around ##TargetName##.");
}
