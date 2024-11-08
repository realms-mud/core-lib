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
    addSpecification("name", "Magical Condenser");
    addSpecification("source", "Scion of Dhuras");
    addSpecification("description", "This research provides the user with the "
        "knowledge of the magical condenser technique. This form enhances "
        "the Scion's offensive spells.");
    SetupResearch();

    addPrerequisite("level", 
        (["type":"level", 
          "guild": "Scion of Dhuras",
          "value": 45 ]));
    addPrerequisite(sprintf("/guilds/scion/paths/%s/evocation/kinetic-discharge.c", WeaponType),
        (["type":"research"]));

    addSpecification("research type", "points");
    addSpecification("research cost", 1);
    addSpecification("affected research", ([
        "Energy Blast": 25,
        "Energy Storm": 25,
        "Maelstrom": 25,
        "Plasma Ball": 25
    ]));
    addSpecification("affected research type", "percentage");
}
