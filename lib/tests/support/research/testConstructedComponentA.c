//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/constructedResearchComponent.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Test Component A");
    addSpecification("source", "test");
    addSpecification("description", "Test component A for constructed research - a form.");
    addSpecification("research type", "granted");
    addSpecification("research cost", 1);

    addSpecification("additional hit point cost", 5);
    addSpecification("additional spell point cost", 10);
    addSpecification("additional stamina point cost", 8);
    addSpecification("additional cooldown", 3);
    addSpecification("additional repeat effect", 2);

    addSpecification("use combination message", 
        "##InitiatorName## ##Infinitive::blast## a bolt of ##Function## at ##TargetName##.");
}
