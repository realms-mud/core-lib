//*****************************************************************************
// Copyright (c) 2024 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/traits/baseTrait.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("type", "health");
    addSpecification("name", "cataracts");
    addSpecification("description", "You have cataracts clouding your eyes and are quite blind.");
    addSpecification("root", "blind");
    addSpecification("opinion", -1);
    addSpecification("cost", -1);
}
