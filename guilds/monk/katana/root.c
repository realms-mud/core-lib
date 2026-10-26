//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/knowledgeResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Katana Foundations");
    addSpecification("source", "monk");
    addSpecification("description",
        "On the polished floor of the sword hall, patience gives "
        "shape to steel. The katana's curved edge asks for a steady "
        "hand, an honest stance, and the courage to begin again.");

    addSpecification("research type", "tree root");
}
