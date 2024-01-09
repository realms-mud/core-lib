//*****************************************************************************
// Copyright (c) 2024 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/knowledgeResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Gwaelphilin Celair");
    addSpecification("source", "Aegis Guard");
    addSpecification("description", "This skill provides the user with the "
        "knowledge to decrease the cost for which they can use their "
        "magical archery skills.");

    addPrerequisite("level",
        (["type":"level",
            "guild": "Aegis Guard",
            "value": 19
        ]));
    addPrerequisite("/guilds/aegis-guard/forms/bow/angol-ai-cu.c",
        (["type":"research"]));

    addSpecification("research type", "points");
    addSpecification("research cost", 1);
    addSpecification("affected research", ([
        "Pilin ai Ambar": 15,
        "Pilin ai Naurtho": 15,
        "Pilin ai Heleg": 15,
        "Pilin ai Glauro": 15,
        "Pilin ai Guruthos": 15,
        "Pilin ai Lhutha": 15,
        "Pilin ai Angolo": 15,
    ]));
    addSpecification("affected research type", "decrease cost");
}
