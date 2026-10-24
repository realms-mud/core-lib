//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/knowledgeResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Paired Sword Foundations");
    addSpecification("source", "monk");
    addSpecification("description",
        "The coordination of a primary katana and offhand wakizashi. "
        "Individual lessons require instruction; two weapons do not "
        "automatically grant extra attacks.");

    addPrerequisite("monk", ([
        "type":"guild",
        "value":({ "monk" })
    ]));

    addSpecification("research type", "tree root");
}
