//*****************************************************************************
// Copyright (c) 2024 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/traits/baseTrait.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("type", "professional");
    addSpecification("name", "master engineer");
    addSpecification("description", "You are a master engineer");
    addSpecification("root", "engineer");
    addSpecification("opinion", 5);
    addSpecification("bonus engineering", 25);
    addSpecification("bonus mathematics", 20);
    addSpecification("bonus physics", 20);
}
