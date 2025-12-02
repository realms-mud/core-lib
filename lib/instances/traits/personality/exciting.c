//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/traits/baseTrait.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("type", "personality");
    addSpecification("name", "exciting");
    addSpecification("description", "People gravitate toward you as you "
        "have a knack for piquing their enthusiasm.");
    addSpecification("root", "interesting");
    addSpecification("opinion", 5);
    addSpecification("bonus persuasion", 1);
    addSpecification("bonus diplomacy", 1);
}
