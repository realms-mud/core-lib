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
        "On the rack the katana and wakizashi seem an unequal "
        "pair. In practiced hands, their different voices can "
        "learn to tell the same enduring story.");

    addSpecification("research type", "tree root");
}
