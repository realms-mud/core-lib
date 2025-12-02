//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/passiveResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Relentless");
    addSpecification("source", "background");
    addSpecification("description",
        "You push through pain and fatigue, refusing to give up.");
    addSpecification("research type", "points");
    addSpecification("research cost", 1);
    addSpecification("bonus hit points", 3);
    addSpecification("bonus constitution", 1);
    addSpecification("bonus defense class", 1);
}
