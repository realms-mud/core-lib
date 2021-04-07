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
    addSpecification("name", "Nienwyn's Kiss");
    addSpecification("source", "Scion of Dhuras Guild");
    addSpecification("description", "This research provides the user with the "
        "knowledge of the Nienwyn's Kiss technique. This form enhances "
        "the Scion's offensive spells.");
    SetupResearch();

    addPrerequisite("level", 
        (["type":"level", 
          "guild": "Scion of Dhuras",
          "value": 27 ]));
    addPrerequisite(sprintf("guilds/scion/paths/%s/spirit/spectral-rage.c", WeaponType),
        (["type":"research"]));

    addSpecification("research type", "points");
    addSpecification("research cost", 1);
    addSpecification("affected research", ([
        "Soul Shard": 35,
        "Shadow Storm": 35,
        "Spectral Storm": 35,
        "Spirit Scourge": 35
    ]));
    addSpecification("affected research type", "percentage");
}
