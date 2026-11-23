//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD. All rights reserved.
//*****************************************************************************
inherit "/lib/modules/research/instantaneousActiveResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Frostfire Glyph");
    addSpecification("description", "A rune releases a surge of frostfire.");
    addSpecification("effect", "combat");
    addSpecification("scope", "targeted");
    addSpecification("research type", "granted");
    addSpecification("spell point cost", 12);
    addSpecification("damage type", "cold");
    addSpecification("damage hit points", ({ ([
        "probability": 100, "base damage": 35, "range": 30
    ]) }));
    addSpecification("cooldown", 12);
    addSpecification("command template", "frostfireglyph at ##Target##");
    addSpecification("use ability message", "A frostfire rune detonates by ##TargetName##.");
}
