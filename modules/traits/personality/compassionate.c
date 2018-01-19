//*****************************************************************************
// Copyright (c) 2018 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/traits/baseTrait.c";

/////////////////////////////////////////////////////////////////////////////
public void reset(int arg)
{
    if (!arg)
    {
        addSpecification("type", "personality");
        addSpecification("name", "compassionate");
        addSpecification("description", "You truly care for those around you.");
        addSpecification("root", "kind");
        addSpecification("opposing root", "cruel");
        addSpecification("opinion", 10);
        addSpecification("opposing opinion", -10);
        "baseTrait"::reset(arg);
    }
}

