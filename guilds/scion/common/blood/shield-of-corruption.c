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
    addSpecification("name", "Shield of Corruption");
    addSpecification("source", "Scion of Dhuras");
    addSpecification("description", "This research provides the user with the "
        "knowledge of the shield of corruption technique. This form enhances "
        "the Scion's defensive spells.");
    SetupResearch();

    addPrerequisite("level", 
    ([
        "type":"level", 
        "guild": "Scion of Dhuras",
        "value": 35 
    ]));
    addPrerequisite(sprintf("/guilds/scion/paths/%s/blood/soul-shield.c", WeaponType),
        (["type":"research"]));

    addSpecification("research type", "points");
    addSpecification("research cost", 1);
    addSpecification("affected research", (["Sanguine Shroud": 5 ]));
    addSpecification("affected research type", "bonus");
}
