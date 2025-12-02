//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/traits/baseTrait.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("type", "personality");
    addSpecification("name", "arbitrary");
    addSpecification("description", "Your decisions are typically based on random "
        "choice or your personal whim at the time you're making said choice.");
    addSpecification("root", "arbitrary");
    addSpecification("opposing root", "reasonable");
    addSpecification("opinion", -5);
    addSpecification("opposing opinion", -15);
}
