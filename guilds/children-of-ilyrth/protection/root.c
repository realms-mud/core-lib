//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/knowledgeResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Tidal Protection");
    addSpecification("source", "Children of Ilyrth");
    addSpecification("description", "This skill provides the user with "
        "knowledge of protective magic channeled through the power of "
        "Ilyrth, goddess of the sea. Her followers learn to shield "
        "themselves and others from harm using barriers of sacred water.");

    addSpecification("research type", "tree root");
    addSpecification("research cost", 1);
}
