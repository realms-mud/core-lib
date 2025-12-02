//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
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
    addSpecification("name", "Winter's Boon");
    addSpecification("source", "Scion of Dhuras");
    addSpecification("description", "This skill provides the user with the "
        "knowledge of the Winter's Boon technique. This form enhances "
        "the scion's Frost Brand and Glacial Brand abilities.");
    SetupResearch();

    addPrerequisite("level",
        (["type":"level",
            "guild" : "Scion of Dhuras",
            "value" : 21]));
    addPrerequisite(sprintf("/guilds/scion/paths/%s/ice/icy-edge.c", WeaponType),
        (["type":"research"]));

    addSpecification("research type", "points");
    addSpecification("research cost", 1);
    addSpecification("affected research", ([
        "Frost Brand": 100,
        "Glacial Brand": 75
    ]));
    addSpecification("affected research type", "percentage");
}
