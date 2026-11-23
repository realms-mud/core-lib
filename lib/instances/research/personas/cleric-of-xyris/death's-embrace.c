//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD. All rights reserved.
//*****************************************************************************
inherit "/lib/modules/research/instantaneousActiveResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Death's Embrace");
    addSpecification("description", "A grasp of shadow drains the strength from "
        "Xyris's foe.");
    addSpecification("effect", "combat");
    addSpecification("scope", "targeted");
    addSpecification("research type", "granted");
    addSpecification("spell point cost", 12);
    addSpecification("damage type", "evil");
    addSpecification("damage hit points", ({ ([
        "probability": 100,
        "base damage": 35,
        "range": 30
    ]) }));
    addSpecification("cooldown", 12);
    addSpecification("command template", "deathembrace at ##Target##");
    addSpecification("use ability message",
        "A shadowy hand closes around ##TargetName##.");
}
