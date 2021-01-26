//*****************************************************************************
// Copyright (c) 2021 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/knowledgeResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
public void reset(int arg)
{
    if (!arg)
    {
        knowledgeResearchItem::reset(arg);
        addSpecification("name", "Gwaelphilin Dagnir");
        addSpecification("source", "Aegis Guard");
        addSpecification("description", "This skill provides the user with the "
            "knowledge to decrease the cost for which they can use their "
            "magical archery skills.");

        addPrerequisite("level",
            (["type":"level",
                "guild": "Aegis Guard",
                "value": 43
            ]));
        addPrerequisite("guilds/aegis-guard/forms/bow/gwaelphilin-manadh.c",
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
        addSpecification("affected research type", "decrease cost");
    }
}
