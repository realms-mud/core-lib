//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/constructedResearchComponent.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Test Component C");
    addSpecification("source", "test");
    addSpecification("description", "Test component C for constructed research.");
    addSpecification("research type", "granted");
    addSpecification("research cost", 1);

    addSpecification("additional hit point cost", 3);
    addSpecification("additional spell point cost", 20);
    addSpecification("additional stamina point cost", 5);
    addSpecification("additional cooldown", 2);
}
