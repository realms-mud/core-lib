//*****************************************************************************
// Copyright (c) 2021 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/knowledgeResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Tad-Godref");
    addSpecification("source", "Aegis Guard");
    addSpecification("description", "This skill provides the user with the "
        "knowledge to chain an additional attack to their combinations.");

    addPrerequisite("level",
        (["type":"level",
            "guild": "Aegis Guard",
            "value": 21
        ]));
    addPrerequisite("/guilds/aegis-guard/forms/sword-combinations/godramin.c",
        (["type":"research"]));

    addSpecification("research type", "points");
    addSpecification("research cost", 1);
    addSpecification("affected research", ([
        "Godrebh ai Megil": 1
    ]));
    addSpecification("affected research type", "max combination chain");
}
