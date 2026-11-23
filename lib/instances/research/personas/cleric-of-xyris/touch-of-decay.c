//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD. All rights reserved.
//*****************************************************************************
inherit "/lib/modules/research/instantaneousActiveResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Touch of Decay");
    addSpecification("description", "A brief touch calls forth the withering power "
        "of Xyris.");
    addSpecification("effect", "combat");
    addSpecification("scope", "targeted");
    addSpecification("research type", "granted");
    addSpecification("spell point cost", 5);
    addSpecification("damage type", "evil");
    addSpecification("damage hit points", ({ ([
        "probability": 100,
        "base damage": 20,
        "range": 20
    ]) }));
    addSpecification("cooldown", 4);
    addSpecification("command template", "touchofdecay at ##Target##");
    addSpecification("use ability message",
        "##InitiatorName## touches ##TargetName## with a chill hand.");
}
