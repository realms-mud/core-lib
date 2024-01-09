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
    addSpecification("name", "Thunder's Boon");
    addSpecification("source", "Scion of Dhuras Guild");
    addSpecification("description", "This skill provides the user with the "
        "knowledge of the Thunder's Boon technique. This form enhances "
        "the scion's Shock Strike and Lightning Strike abilities.");
    SetupResearch();

    addPrerequisite("level",
        (["type":"level",
            "guild" : "Scion of Dhuras",
            "value" : 21]));
    addPrerequisite(sprintf("/guilds/scion/paths/%s/electricity/shocking-edge.c", WeaponType),
        (["type":"research"]));

    addSpecification("research type", "points");
    addSpecification("research cost", 1);
    addSpecification("affected research", ([
        "Shock Strike":100,
        "Lightning Strike" : 75
    ]));
    addSpecification("affected research type", "percentage");
}
