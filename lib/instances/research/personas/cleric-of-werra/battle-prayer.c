//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD. All rights reserved.
//*****************************************************************************
inherit "/lib/modules/research/instantaneousActiveResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Battle Prayer");
    addSpecification("description", "A prayer to Werra empowers a punishing "
        "strike.");
    addSpecification("effect", "combat");
    addSpecification("scope", "targeted");
    addSpecification("research type", "granted");
    addSpecification("spell point cost", 5);
    addSpecification("damage type", "bludgeon");
    addSpecification("damage hit points", ({ ([
        "probability": 100,
        "base damage": 20,
        "range": 20
    ]) }));
    addSpecification("cooldown", 4);
    addSpecification("command template", "battleprayer at ##Target##");
    addSpecification("use ability message",
        "##InitiatorName## utters a battle prayer and strikes at ##TargetName##.");
}
