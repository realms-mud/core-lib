//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/passiveResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Faithful Heart");
    addSpecification("source", "background");
    addSpecification("description", "Your faith provides you with resilience "
        "in the face of adversity.");
    addSpecification("research type", "points");
    addSpecification("research cost", 1);
    addSpecification("bonus constitution", 1);
    addSpecification("bonus theology", 1);
}
