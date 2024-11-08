//*****************************************************************************
// Copyright (c) 2024 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/knowledgeResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Braig Dagnir");
    addSpecification("source", "Aegis Guard");
    addSpecification("description", "This skill provides the user with the "
        "knowledge to increase the speed with which they can use their "
        "mythic magic skills.");

    addPrerequisite("level",
        (["type":"level",
            "guild": "Aegis Guard",
            "value": 51
        ]));
    addPrerequisite("/guilds/aegis-guard/forms/sword-mythic/braig-manadh.c",
        (["type":"research"]));

    addSpecification("research type", "points");
    addSpecification("research cost", 1);
    addSpecification("affected research", ([
        "Auth": 10,
        "Sereg": 10,
        "Guruthos": 10,
        "Lhutha": 10,
        "Angolo": 10,
    ]));
    addSpecification("affected research type", "decrease cooldown");
}
