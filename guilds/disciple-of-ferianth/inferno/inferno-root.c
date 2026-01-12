//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/knowledgeResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Inferno Fundamentals");
    addSpecification("source", "disciple of ferianth");
    addSpecification("description", "This research provides the user with "
        "fundamental knowledge of Ferianth's sacred fire - the divine flames "
        "that can be channeled to smite enemies. This is the foundation of "
        "all offensive fire magic practiced by the Disciples.");

    addSpecification("research type", "tree root");
}
