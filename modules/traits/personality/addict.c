//*****************************************************************************
// Copyright (c) 2018 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/traits/baseTrait.c";

/////////////////////////////////////////////////////////////////////////////
public void reset(int arg)
{
    addSpecification("type", "personality");
    addSpecification("name", "addict");
    addSpecification("description", "You are prone to compulsive or obsessive behavior "
        "be it toward a substance, habit, or activity.");
    addSpecification("root", "addict");
    addSpecification("opinion", -5);
    "baseTrait"::reset(arg);
}
