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
    addSpecification("name", "Chill the Blood");
    addSpecification("source", "Scion of Dhuras Guild");
    addSpecification("description", "This research provides the user with the "
        "knowledge of the chill the blood technique. This form enhances "
        "the Scion's offensive spells.");
    SetupResearch();

    addPrerequisite("level", 
        (["type":"level", 
          "guild": "Scion of Dhuras",
          "value": 5 ]));
    addPrerequisite(sprintf("guilds/scion/paths/%s/spirit/spirit-bolt.c", WeaponType),
        (["type":"research"]));

    addSpecification("research type", "points");
    addSpecification("research cost", 1);
    addSpecification("affected research", ([
        "Spirit Bolt": 50,
        "Soul Shard": 25,
        "Shadow Storm": 25,
        "Spectral Storm": 25,
        "Spirit Scourge": 25
    ]));
    addSpecification("affected research type", "percentage");
}
