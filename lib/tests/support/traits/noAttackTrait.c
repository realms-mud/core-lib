//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/traits/baseTrait.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("type", "health");
    addSpecification("name", "Inconsequential Boy");
    addSpecification("root", "no weapon attacks");
    addSpecification("description", "You cannot make weapon attacks while "
        "this effect is active. Only special attacks function.");
}
