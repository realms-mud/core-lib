//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/constructedResearchComponent.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Test Function A");
    addSpecification("source", "blarg");
    addSpecification("description", "A test function component");
    addSpecification("research type", "granted");
    addSpecification("additional spell point cost", 10);
    addSpecification("additional cooldown", 3);
}
