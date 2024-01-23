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
    addSpecification("name", "Energized Strike");
    addSpecification("source", "Scion of Dhuras");
    addSpecification("description", "This research provides the user with the "
        "knowledge of the energized strike technique. This form enhances "
        "the scion's Shock Strike and Lightning Strike abilities.");
    SetupResearch();

    addPrerequisite("level", 
        (["type":"level", 
          "guild": "Scion of Dhuras",
          "value": 11 ]));
    addPrerequisite(
        sprintf("/guilds/scion/paths/%s/electricity/shock-brand.c", WeaponType),
        (["type":"research"]));

    addSpecification("research type", "points");
    addSpecification("research cost", 1);
    addSpecification("affected research", ([
        "Shock Strike": 30,
        "Lightning Strike": 30 
    ]));
    addSpecification("affected research type", "percentage");
}
