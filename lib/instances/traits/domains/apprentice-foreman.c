//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/traits/baseTrait.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("type", "professional");
    addSpecification("name", "apprentice foreman");
    addSpecification("description", "You are able to lead building projects");
    addSpecification("root", "foreman");
    addSpecification("opinion", 5);
    addSpecification("bonus engineering", 2);
    addSpecification("bonus mathematics", 1);
    addSpecification("bonus physics", 1);
}
