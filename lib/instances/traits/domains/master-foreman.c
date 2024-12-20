//*****************************************************************************
// Copyright (c) 2025 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/traits/baseTrait.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("type", "professional");
    addSpecification("name", "master foreman");
    addSpecification("description", "You are an expert at leading building projects");
    addSpecification("root", "foreman");
    addSpecification("opinion", 5);
    addSpecification("bonus engineering", 25);
    addSpecification("bonus mathematics", 20);
    addSpecification("bonus physics", 20);
}
