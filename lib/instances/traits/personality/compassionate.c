//*****************************************************************************
// Copyright (c) 2025 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/traits/baseTrait.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("type", "personality");
    addSpecification("name", "compassionate");
    addSpecification("description", "You truly care for those around you.");
    addSpecification("root", "kind");
    addSpecification("opposing root", "cruel");
    addSpecification("opinion", 10);
    addSpecification("opposing opinion", -10);
    addSpecification("bonus persuasion", 1);
    addSpecification("bonus diplomacy", 1);
}
