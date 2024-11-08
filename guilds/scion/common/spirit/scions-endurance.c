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
    addSpecification("name", "Scion's Endurance");
    addSpecification("source", "Scion of Dhuras");
    addSpecification("description", "This research provides the user with the "
        "knowledge of the Scion's Endurance technique. This form reduces "
        "the time it takes to recover from using this spell.");
    SetupResearch();

    addPrerequisite("level", 
        (["type":"level", 
          "guild": "Scion of Dhuras",
          "value": 33 ]));
    addPrerequisite(sprintf("/guilds/scion/paths/%s/spirit/scions-finess.c", WeaponType),
        (["type":"research"]));

    addSpecification("research type", "points");
    addSpecification("research cost", 1);
    addSpecification("affected research", ([
        "Soul Shard": 10,
        "Shadow Storm": 10,
        "Spectral Storm": 10,
        "Spirit Scourge": 10
    ]));
    addSpecification("affected research type", "decrease cooldown");
}
