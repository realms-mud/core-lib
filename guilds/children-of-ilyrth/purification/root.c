//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/knowledgeResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Purifying Currents");
    addSpecification("source", "Children of Ilyrth");
    addSpecification("description", "This skill provides the user with "
        "knowledge of the purifying power of sacred water. Ilyrth's followers "
        "learn to cleanse corruption, cure afflictions, and wash away the "
        "taint of poison and disease from those they protect.");

    addSpecification("research type", "tree root");
    addSpecification("research cost", 1);
}
