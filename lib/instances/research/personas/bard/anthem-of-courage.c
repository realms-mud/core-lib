//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD. All rights reserved.
//*****************************************************************************
inherit "/lib/modules/research/instantaneousActiveResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Anthem of Courage");
    addSpecification("description", "A forceful anthem becomes a wave of sound.");
    addSpecification("effect", "combat");
    addSpecification("scope", "targeted");
    addSpecification("research type", "granted");
    addSpecification("spell point cost", 20);
    addSpecification("damage type", "sonic");
    addSpecification("damage hit points", ({ ([
        "probability": 100, "base damage": 55, "range": 45
    ]) }));
    addSpecification("cooldown", 30);
    addSpecification("command template", "anthemofcourage at ##Target##");
    addSpecification("use ability message", "A ringing anthem crashes over ##TargetName##.");
}
