//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/traits/baseTrait.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("type", "persona");
    addSpecification("name", "purple dragon");
    addSpecification("description", "You are a purple dragon.");
    addSpecification("root", "large creature persona");
    addSpecification("bonus resist psionic", 75);
    addSpecification("bonus resist electricity", 75);
}
