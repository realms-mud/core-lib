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
    addSpecification("name", "Malefic Barrier");
    addSpecification("source", "Scion of Dhuras Guild");
    addSpecification("description", "This research provides the user with the "
        "knowledge of the malefic barrier technique. This form enhances "
        "the Scion's defense degradation spells.");
    SetupResearch();

    addPrerequisite("level", 
        (["type":"level", 
          "guild": "Scion of Dhuras",
          "value": 11 ]));
    addPrerequisite(sprintf("guilds/scion/paths/%s/blood/choking-tendrils.c", WeaponType),
        (["type":"research"]));

    addSpecification("research type", "points");
    addSpecification("research cost", 1);
    addSpecification("affected research", ([
        "Choking Tendrils": 25,
        "Enervating Barrier": 25,
        "Bloodswarm": 25
    ]));
    addSpecification("affected research type", "percentage");
}
