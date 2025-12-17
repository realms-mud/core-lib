//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/knowledgeResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Dream Magic Fundamentals");
    addSpecification("source", "oneiromancer");
    addSpecification("description", "This research provides the user with "
        "fundamental knowledge of dream magic - the art of reaching into "
        "the realm of dreams to manipulate minds, weave illusions, and "
        "channel the power of nightmares.");

    addSpecification("research type", "tree root");
}
