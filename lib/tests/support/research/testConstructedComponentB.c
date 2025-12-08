//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/constructedResearchComponent.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Test Component B");
    addSpecification("source", "test");
    addSpecification("description", "Test component B for constructed research.");
    addSpecification("research type", "granted");
    addSpecification("research cost", 1);

    addSpecification("additional hit point cost", 7);
    addSpecification("additional spell point cost", 15);
    addSpecification("additional stamina point cost", 12);
    addSpecification("additional cooldown", 5);
    addSpecification("additional repeat effect", 1);

    addSpecification("use combination message", "of ##Infinitive::shock## lightning");
}
