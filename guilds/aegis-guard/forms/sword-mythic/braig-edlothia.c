//*****************************************************************************
// Copyright (c) 2021 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/knowledgeResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    addSpecification("name", "Braig Edlothia");
    addSpecification("source", "Aegis Guard");
    addSpecification("description", "This skill provides the user with the "
        "knowledge to increase the speed with which they can use their "
        "mythic magic skills.");

    addPrerequisite("level",
        (["type":"level",
            "guild": "Aegis Guard",
            "value": 31
        ]));
    addPrerequisite("guilds/aegis-guard/forms/sword-mythic/braig-celair.c",
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
