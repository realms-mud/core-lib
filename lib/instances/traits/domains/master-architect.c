//*****************************************************************************
// Copyright (c) 2023 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/traits/baseTrait.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("type", "professional");
    addSpecification("name", "master architect");
    addSpecification("description", "You are a master architect");
    addSpecification("root", "architect");
    addSpecification("opinion", 5);
    addSpecification("bonus engineering", 25);
    addSpecification("bonus mathematics", 20);
    addSpecification("bonus physics", 20);
}
