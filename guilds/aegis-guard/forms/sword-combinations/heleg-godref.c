//*****************************************************************************
// Copyright (c) 2023 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/knowledgeResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Heleg Godref");
    addSpecification("source", "Aegis Guard");
    addSpecification("description", "This skill provides the user with the "
        "knowledge to increase the speed with which they can use their "
        "combinations.");

    addPrerequisite("level",
        (["type":"level",
            "guild": "Aegis Guard",
            "value": 43
        ]));
    addPrerequisite("/guilds/aegis-guard/forms/sword-combinations/heleg-golwen.c",
        (["type":"research"]));

    addSpecification("research type", "points");
    addSpecification("research cost", 1);
    addSpecification("affected research", ([
        "Godrebh ai Megil": 15
    ]));
    addSpecification("affected research type", "decrease cooldown");
}
