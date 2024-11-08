//*****************************************************************************
// Copyright (c) 2024 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/knowledgeResearchItem.c";

protected string WeaponType = "ERROR";

/////////////////////////////////////////////////////////////////////////////
protected void SetupResearch()
{
}

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Scorching Mark");
    addSpecification("source", "Scion of Dhuras");
    addSpecification("description", "This research provides the user with the "
        "knowledge of the scorching mark technique. This form enhances "
        "the Scion's offensive spells.");
    SetupResearch();

    addPrerequisite("level", 
        (["type":"level", 
          "guild": "Scion of Dhuras",
          "value": 13 ]));
    addPrerequisite(
        sprintf("/guilds/scion/paths/%s/flame/fuel-the-flames.c", WeaponType),
        (["type":"research"]));

    addSpecification("research type", "points");
    addSpecification("research cost", 1);
    addSpecification("affected research", ([
        "Flame Bolt": 100,
        "Fire Bolt": 25,
        "Fireball": 25,
        "Conflagration": 25,
        "Inferno Spear": 25
    ]));
    addSpecification("affected research type", "percentage");
}
