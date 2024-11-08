//*****************************************************************************
// Copyright (c) 2024 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/knowledgeResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Spectral Touch");
    addSpecification("source", "Scion of Dhuras");
    addSpecification("description", "This research gives your "
        "avatar the `Spectral Touch' spell.");

    addSpecification("research type", "points");
    addSpecification("research cost", 1);
    addSpecification("related research", ({
        "/guilds/scion/avatars/spirit/root.c",
    }));
}
