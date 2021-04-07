//*****************************************************************************
// Copyright (c) 2021 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/traits/baseTrait.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("type", "personality");
    addSpecification("name", "rational");
    addSpecification("description", "Your interactions with others are generally well-grounded "
    "in reason and logic.");
    addSpecification("root", "reasonable");
    addSpecification("opinion", 5);
}
