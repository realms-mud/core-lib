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
    addSpecification("name", "Dalreth's Might");
    addSpecification("source", "Scion of Dhuras");
    addSpecification("description", "This skill provides the user with the "
        "knowledge of the Dalreth's Might technique. This form enhances "
        "the scion's Magical Strike and Power Strike abilities.");
    SetupResearch();

    addPrerequisite("level",
        (["type":"level",
            "guild" : "Scion of Dhuras",
            "value" : 21]));
    addPrerequisite(sprintf("/guilds/scion/paths/%s/evocation/magical-edge.c", WeaponType),
        (["type":"research"]));

    addSpecification("research type", "points");
    addSpecification("research cost", 1);
    addSpecification("affected research", ([
        "Magical Strike": 100,
        "Power Strike" : 75
    ]));
    addSpecification("affected research type", "percentage");
}
