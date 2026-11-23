//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD. All rights reserved.
//*****************************************************************************
inherit "/lib/modules/research/instantaneousActiveResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Khazurath Fury");
    addSpecification("description", "The guardian brings the mountain's fury to bear.");
    addSpecification("effect", "combat");
    addSpecification("scope", "targeted");
    addSpecification("research type", "granted");
    addSpecification("spell point cost", 20);
    addSpecification("damage type", "earth");
    addSpecification("damage hit points", ({ ([
        "probability": 100, "base damage": 55, "range": 45
    ]) }));
    addSpecification("cooldown", 30);
    addSpecification("command template", "khazurathfury at ##Target##");
    addSpecification("use ability message", "The mountain's fury crashes into ##TargetName##.");
}
