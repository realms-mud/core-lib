//*****************************************************************************
// Copyright (c) 2021 - Allen Cummings, RealmsMUD, All rights reserved. See
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
    addSpecification("name", "Plasma Eruption");
    addSpecification("source", "Scion of Dhuras Guild");
    addSpecification("description", "This research provides the user with the "
        "knowledge of the plasma eruption technique. This form enhances "
        "the Scion's offensive spells.");
    SetupResearch();

    addPrerequisite("level", 
        (["type":"level", 
          "guild": "Scion of Dhuras",
          "value": 39 ]));
    addPrerequisite(sprintf("guilds/scion/paths/%s/electricity/enhanced-discharge.c", WeaponType),
        (["type":"research"]));

    addSpecification("research type", "points");
    addSpecification("research cost", 1);
    addSpecification("affected research", ([
        "Lightning": 40,
        "Lightning Blast": 40,
        "Maelstrom": 40,
        "Plasma Ball": 40
    ]));
    addSpecification("affected research type", "percentage");
}
