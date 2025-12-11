//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/constructedResearchComponent.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Test Effect A");
    addSpecification("source", "blarg");
    addSpecification("description", "A test effect component");
    addSpecification("research type", "granted");
    addSpecification("additional spell point cost", 8);
    addSpecification("additional cooldown", 4);
}
