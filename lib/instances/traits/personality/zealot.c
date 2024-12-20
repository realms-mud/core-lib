//*****************************************************************************
// Copyright (c) 2025 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/traits/baseTrait.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("type", "personality");
    addSpecification("name", "zealot");
    addSpecification("description", "You are fanatical and uncompromising "
        "in your ideals.");
    addSpecification("root", "arrogant");
    addSpecification("opposing root", "humble");
    addSpecification("opinion", 5);
    addSpecification("opposing opinion", -15);
    addSpecification("penalty to diplomacy", 1);
}
