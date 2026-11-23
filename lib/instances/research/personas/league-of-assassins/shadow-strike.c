//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD. All rights reserved.
//*****************************************************************************
inherit "/lib/modules/research/instantaneousActiveResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Shadow Strike");
    addSpecification("description", "A concealed attack springs from the shadows.");
    addSpecification("effect", "combat");
    addSpecification("scope", "targeted");
    addSpecification("research type", "granted");
    addSpecification("spell point cost", 12);
    addSpecification("damage type", "shadow");
    addSpecification("damage hit points", ({ ([
        "probability": 100, "base damage": 35, "range": 30
    ]) }));
    addSpecification("cooldown", 12);
    addSpecification("command template", "shadowstrike at ##Target##");
    addSpecification("use ability message", "A shadowed blade flashes at ##TargetName##.");
}
