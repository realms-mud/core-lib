//*****************************************************************************
// Copyright (c) 2024 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/knowledgeResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Cu Ai Manadh");
    addSpecification("source", "Aegis Guard");
    addSpecification("description", "This skill provides the user with the "
        "knowledge to increase the speed with which they can use their "
        "magical archery skills.");

    addPrerequisite("level",
        (["type":"level",
            "guild": "Aegis Guard",
            "value": 37
        ]));
    addPrerequisite("/guilds/aegis-guard/forms/bow/cu-ai-edlothia.c",
        (["type":"research"]));

    addSpecification("research type", "points");
    addSpecification("research cost", 1);
    addSpecification("affected research", ([
        "Pilin ai Ambar": 10,
        "Pilin ai Naurtho": 10,
        "Pilin ai Heleg": 10,
        "Pilin ai Glauro": 10,
        "Pilin ai Guruthos": 10,
        "Pilin ai Lhutha": 10,
        "Pilin ai Angolo": 10,
    ]));
    addSpecification("affected research type", "decrease cooldown");
}
