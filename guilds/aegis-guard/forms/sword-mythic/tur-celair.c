//*****************************************************************************
// Copyright (c) 2021 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/knowledgeResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    addSpecification("name", "Tur Celair");
    addSpecification("source", "Aegis Guard");
    addSpecification("description", "This skill provides the user with the "
        "knowledge to decrease the cost for which they can use their "
        "mythic magic skills.");

    addPrerequisite("level",
        (["type":"level",
            "guild": "Aegis Guard",
            "value": 23
        ]));
    addPrerequisite("guilds/aegis-guard/forms/sword-mythic/mythic-root.c",
        (["type":"research"]));

    addSpecification("research type", "points");
    addSpecification("research cost", 1);
    addSpecification("affected research", ([
        "Auth": 15,
        "Sereg": 15,
        "Guruthos": 15,
        "Lhutha": 15,
        "Angolo": 15,
    ]));
    addSpecification("affected research type", "decrease cost");
}
