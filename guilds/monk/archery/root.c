//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/knowledgeResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Monastic Archery Foundations");
    addSpecification("source", "monk");
    addSpecification("description",
        "The monastery's bow teaches patience before it teaches "
        "aim. Beneath its drawn string, breath and purpose "
        "must become steady before the hand is ready to release.");


    addSpecification("research type", "tree root");
}
