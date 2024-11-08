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
    addSpecification("name", "Plasma Shield");
    addSpecification("source", "Scion of Dhuras");
    addSpecification("description", "This research provides the user with the "
        "knowledge of the plasma shield technique. This form enhances "
        "the Scion's defensive spells.");
    SetupResearch();

    addPrerequisite("level", 
        (["type":"level", 
          "guild": "Scion of Dhuras",
          "value": 35 ]));
    addPrerequisite(sprintf("/guilds/scion/paths/%s/electricity/static-shield.c", WeaponType),
        (["type":"research"]));

    addSpecification("research type", "points");
    addSpecification("research cost", 1);
    addSpecification("affected research", (["Electric Shroud": 5 ]));
    addSpecification("affected research type", "bonus");
}
