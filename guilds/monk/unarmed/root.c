//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/knowledgeResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Unarmed Foundations");
    addSpecification("source", "monk");
    addSpecification("description",
        "Lay the weapon on the rack and enter the courtyard with empty "
        "hands. Here the first lesson is not how to strike, but how to "
        "stand without borrowing courage from steel.");


    addSpecification("research type", "tree root");
}
