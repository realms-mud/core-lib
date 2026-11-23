//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD. All rights reserved.
//*****************************************************************************
inherit "/lib/modules/research/instantaneousActiveResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Thorn Whip");
    addSpecification("description", "A thorned vine lashes a foe at the druid's "
        "command.");
    addSpecification("effect", "combat");
    addSpecification("scope", "targeted");
    addSpecification("research type", "granted");
    addSpecification("spell point cost", 12);
    addSpecification("damage type", "earth");
    addSpecification("damage hit points", ({ ([
        "probability": 100,
        "base damage": 35,
        "range": 30
    ]) }));
    addSpecification("cooldown", 12);
    addSpecification("command template", "thornwhip at ##Target##");
    addSpecification("use ability message",
        "A thorned vine lashes across ##TargetName##.");
}
