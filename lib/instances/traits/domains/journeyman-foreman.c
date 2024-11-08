//*****************************************************************************
// Copyright (c) 2024 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/traits/baseTrait.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("type", "professional");
    addSpecification("name", "journeyman foreman");
    addSpecification("description", "You are able to lead building projects");
    addSpecification("root", "foreman");
    addSpecification("opinion", 5);
    addSpecification("bonus engineering", 10);
    addSpecification("bonus mathematics", 5);
    addSpecification("bonus physics", 5);
}
